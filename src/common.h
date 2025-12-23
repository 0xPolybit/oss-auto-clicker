#ifndef COMMON_H
#define COMMON_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// Control IDs
#define ID_EDIT_HOURS       101
#define ID_EDIT_MINS        102
#define ID_EDIT_SECS        103
#define ID_EDIT_MILLIS      104
#define ID_COMBO_MOUSEBTN   105
#define ID_COMBO_CLICKTYPE  106
#define ID_RADIO_REPEAT     107
#define ID_RADIO_UNTILSTOP  108
#define ID_EDIT_REPEAT_COUNT 109
#define ID_BTN_START        110
#define ID_BTN_STOP         111
#define ID_HOTKEY_F6        112

// Settings Structure
struct ClickerSettings {
    int hours;
    int minutes;
    int seconds;
    int milliseconds;
    int mouseButton; // 0=Left, 1=Right, 2=Middle
    int clickType;   // 0=Single, 1=Double
    bool repeatUntilStopped;
    int repeatCount;
};

#endif
