#include "clicker.h"
#include <iostream>

AutoClicker::AutoClicker() : running(false) {}

AutoClicker::~AutoClicker() {
    Stop();
}

void AutoClicker::Start(ClickerSettings settings) {
    if (running) return;
    currentSettings = settings;
    running = true;
    workerThread = std::thread(&AutoClicker::ClickThread, this);
}

void AutoClicker::Stop() {
    running = false;
    if (workerThread.joinable()) {
        workerThread.join();
    }
}

bool AutoClicker::IsRunning() const {
    return running;
}

void AutoClicker::PerformClick(int btn, int type) {
    INPUT inputs[2] = {};
    ZeroMemory(inputs, sizeof(inputs));

    DWORD downFlags, upFlags;

    // Determine flags based on button
    if (btn == 0) { // Left
        downFlags = MOUSEEVENTF_LEFTDOWN;
        upFlags = MOUSEEVENTF_LEFTUP;
    } else if (btn == 1) { // Right
        downFlags = MOUSEEVENTF_RIGHTDOWN;
        upFlags = MOUSEEVENTF_RIGHTUP;
    } else { // Middle
        downFlags = MOUSEEVENTF_MIDDLEDOWN;
        upFlags = MOUSEEVENTF_MIDDLEUP;
    }

    inputs[0].type = INPUT_MOUSE;
    inputs[0].mi.dwFlags = downFlags;

    inputs[1].type = INPUT_MOUSE;
    inputs[1].mi.dwFlags = upFlags;

    int clicks = (type == 0) ? 1 : 2; // Single or Double

    for (int i = 0; i < clicks; ++i) {
        SendInput(2, inputs, sizeof(INPUT));
        if (i < clicks - 1) Sleep(50); // Small delay between double clicks
    }
}

void AutoClicker::ClickThread() {
    long long intervalMs = (currentSettings.hours * 3600000) +
                           (currentSettings.minutes * 60000) +
                           (currentSettings.seconds * 1000) +
                           currentSettings.milliseconds;
    
    if (intervalMs < 1) intervalMs = 1; // Safety minimum

    int count = 0;

    while (running) {
        PerformClick(currentSettings.mouseButton, currentSettings.clickType);
        
        count++;
        if (!currentSettings.repeatUntilStopped && count >= currentSettings.repeatCount) {
            running = false;
            break;
        }

        // Simple sleep (in a real app, use a condition variable for better responsiveness on stop)
        Sleep(static_cast<DWORD>(intervalMs));
    }
}
