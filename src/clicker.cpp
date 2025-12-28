#include "clicker.h"
#include <iostream>
#include <chrono>

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
    cv.notify_all();
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
    long long intervalMs = (static_cast<long long>(currentSettings.hours) * 3600000) +
                           (static_cast<long long>(currentSettings.minutes) * 60000) +
                           (static_cast<long long>(currentSettings.seconds) * 1000) +
                           currentSettings.milliseconds;
    
    if (intervalMs < 1) intervalMs = 1; // Safety minimum

    int count = 0;

    while (running) {
        if (!currentSettings.useCurrentLocation) {
            SetCursorPos(currentSettings.x, currentSettings.y);
        }

        PerformClick(currentSettings.mouseButton, currentSettings.clickType);
        
        count++;
        if (!currentSettings.repeatUntilStopped && count >= currentSettings.repeatCount) {
            running = false;
            break;
        }

        // Interruptible sleep
        std::unique_lock<std::mutex> lk(cv_m);
        cv.wait_for(lk, std::chrono::milliseconds(intervalMs), [this]{ return !running; });
    }
}
