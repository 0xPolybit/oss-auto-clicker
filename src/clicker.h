#ifndef CLICKER_H
#define CLICKER_H

#include "common.h"
#include <atomic>
#include <thread>

class AutoClicker {
public:
    AutoClicker();
    ~AutoClicker();

    void Start(ClickerSettings settings);
    void Stop();
    bool IsRunning() const;

private:
    void ClickThread();
    void PerformClick(int btn, int type);

    std::atomic<bool> running;
    std::thread workerThread;
    ClickerSettings currentSettings;
};

#endif
