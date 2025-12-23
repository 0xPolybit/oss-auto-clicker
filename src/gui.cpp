#include "gui.h"
#include "common.h"
#include <string>
#include <vector>

void CreateControls(HWND hwnd) {
    HFONT hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);

    // --- Click Interval Group ---
    HWND hGroup1 = CreateWindow(L"BUTTON", L"Click Interval", WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
        10, 10, 460, 70, hwnd, NULL, NULL, NULL);
    SendMessage(hGroup1, WM_SETFONT, (WPARAM)hFont, TRUE);

    HWND hStatic1 = CreateWindow(L"STATIC", L"Hours", WS_CHILD | WS_VISIBLE, 20, 35, 40, 20, hwnd, NULL, NULL, NULL);
    SendMessage(hStatic1, WM_SETFONT, (WPARAM)hFont, TRUE);
    HWND hEdit1 = CreateWindow(L"EDIT", L"0", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, 60, 30, 50, 25, hwnd, (HMENU)ID_EDIT_HOURS, NULL, NULL);
    SendMessage(hEdit1, WM_SETFONT, (WPARAM)hFont, TRUE);

    HWND hStatic2 = CreateWindow(L"STATIC", L"Mins", WS_CHILD | WS_VISIBLE, 120, 35, 40, 20, hwnd, NULL, NULL, NULL);
    SendMessage(hStatic2, WM_SETFONT, (WPARAM)hFont, TRUE);
    HWND hEdit2 = CreateWindow(L"EDIT", L"0", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, 160, 30, 50, 25, hwnd, (HMENU)ID_EDIT_MINS, NULL, NULL);
    SendMessage(hEdit2, WM_SETFONT, (WPARAM)hFont, TRUE);

    HWND hStatic3 = CreateWindow(L"STATIC", L"Secs", WS_CHILD | WS_VISIBLE, 220, 35, 40, 20, hwnd, NULL, NULL, NULL);
    SendMessage(hStatic3, WM_SETFONT, (WPARAM)hFont, TRUE);
    HWND hEdit3 = CreateWindow(L"EDIT", L"0", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, 260, 30, 50, 25, hwnd, (HMENU)ID_EDIT_SECS, NULL, NULL);
    SendMessage(hEdit3, WM_SETFONT, (WPARAM)hFont, TRUE);

    HWND hStatic4 = CreateWindow(L"STATIC", L"Millis", WS_CHILD | WS_VISIBLE, 320, 35, 40, 20, hwnd, NULL, NULL, NULL);
    SendMessage(hStatic4, WM_SETFONT, (WPARAM)hFont, TRUE);
    HWND hEdit4 = CreateWindow(L"EDIT", L"100", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, 360, 30, 50, 25, hwnd, (HMENU)ID_EDIT_MILLIS, NULL, NULL);
    SendMessage(hEdit4, WM_SETFONT, (WPARAM)hFont, TRUE);

    // --- Click Options Group ---
    HWND hGroup2 = CreateWindow(L"BUTTON", L"Click Options", WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
        10, 90, 220, 100, hwnd, NULL, NULL, NULL);
    SendMessage(hGroup2, WM_SETFONT, (WPARAM)hFont, TRUE);

    HWND hStatic5 = CreateWindow(L"STATIC", L"Mouse Button:", WS_CHILD | WS_VISIBLE, 20, 115, 90, 20, hwnd, NULL, NULL, NULL);
    SendMessage(hStatic5, WM_SETFONT, (WPARAM)hFont, TRUE);
    HWND hComboBtn = CreateWindow(L"COMBOBOX", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, 
        110, 110, 100, 100, hwnd, (HMENU)ID_COMBO_MOUSEBTN, NULL, NULL);
    SendMessage(hComboBtn, WM_SETFONT, (WPARAM)hFont, TRUE);
    SendMessage(hComboBtn, CB_ADDSTRING, 0, (LPARAM)L"Left");
    SendMessage(hComboBtn, CB_ADDSTRING, 0, (LPARAM)L"Right");
    SendMessage(hComboBtn, CB_ADDSTRING, 0, (LPARAM)L"Middle");
    SendMessage(hComboBtn, CB_SETCURSEL, 0, 0);

    HWND hStatic6 = CreateWindow(L"STATIC", L"Click Type:", WS_CHILD | WS_VISIBLE, 20, 150, 90, 20, hwnd, NULL, NULL, NULL);
    SendMessage(hStatic6, WM_SETFONT, (WPARAM)hFont, TRUE);
    HWND hComboType = CreateWindow(L"COMBOBOX", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, 
        110, 145, 100, 100, hwnd, (HMENU)ID_COMBO_CLICKTYPE, NULL, NULL);
    SendMessage(hComboType, WM_SETFONT, (WPARAM)hFont, TRUE);
    SendMessage(hComboType, CB_ADDSTRING, 0, (LPARAM)L"Single");
    SendMessage(hComboType, CB_ADDSTRING, 0, (LPARAM)L"Double");
    SendMessage(hComboType, CB_SETCURSEL, 0, 0);

    // --- Click Repeat Group ---
    HWND hGroup3 = CreateWindow(L"BUTTON", L"Click Repeat", WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
        240, 90, 230, 100, hwnd, NULL, NULL, NULL);
    SendMessage(hGroup3, WM_SETFONT, (WPARAM)hFont, TRUE);

    HWND hRadio1 = CreateWindow(L"BUTTON", L"Repeat", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
        250, 115, 70, 20, hwnd, (HMENU)ID_RADIO_REPEAT, NULL, NULL);
    SendMessage(hRadio1, WM_SETFONT, (WPARAM)hFont, TRUE);
    HWND hEditRepeat = CreateWindow(L"EDIT", L"1", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, 
        320, 115, 50, 20, hwnd, (HMENU)ID_EDIT_REPEAT_COUNT, NULL, NULL);
    SendMessage(hEditRepeat, WM_SETFONT, (WPARAM)hFont, TRUE);
    HWND hStatic7 = CreateWindow(L"STATIC", L"times", WS_CHILD | WS_VISIBLE, 380, 115, 40, 20, hwnd, NULL, NULL, NULL);
    SendMessage(hStatic7, WM_SETFONT, (WPARAM)hFont, TRUE);

    HWND hRadio2 = CreateWindow(L"BUTTON", L"Repeat until stopped", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
        250, 150, 150, 20, hwnd, (HMENU)ID_RADIO_UNTILSTOP, NULL, NULL);
    SendMessage(hRadio2, WM_SETFONT, (WPARAM)hFont, TRUE);
    
    // Select "Repeat until stopped" by default
    CheckRadioButton(hwnd, ID_RADIO_REPEAT, ID_RADIO_UNTILSTOP, ID_RADIO_UNTILSTOP);

    // --- Action Buttons ---
    HWND hBtnStart = CreateWindow(L"BUTTON", L"Start (F6)", WS_CHILD | WS_VISIBLE, 
        50, 210, 150, 50, hwnd, (HMENU)ID_BTN_START, NULL, NULL);
    SendMessage(hBtnStart, WM_SETFONT, (WPARAM)hFont, TRUE);

    HWND hBtnStop = CreateWindow(L"BUTTON", L"Stop (F6)", WS_CHILD | WS_VISIBLE, 
        280, 210, 150, 50, hwnd, (HMENU)ID_BTN_STOP, NULL, NULL);
    SendMessage(hBtnStop, WM_SETFONT, (WPARAM)hFont, TRUE);
}

ClickerSettings GetSettingsFromGUI(HWND hwnd) {
    ClickerSettings s;
    WCHAR buffer[16];

    GetDlgItemText(hwnd, ID_EDIT_HOURS, buffer, 16); s.hours = _wtoi(buffer);
    GetDlgItemText(hwnd, ID_EDIT_MINS, buffer, 16); s.minutes = _wtoi(buffer);
    GetDlgItemText(hwnd, ID_EDIT_SECS, buffer, 16); s.seconds = _wtoi(buffer);
    GetDlgItemText(hwnd, ID_EDIT_MILLIS, buffer, 16); s.milliseconds = _wtoi(buffer);

    s.mouseButton = SendMessage(GetDlgItem(hwnd, ID_COMBO_MOUSEBTN), CB_GETCURSEL, 0, 0);
    s.clickType = SendMessage(GetDlgItem(hwnd, ID_COMBO_CLICKTYPE), CB_GETCURSEL, 0, 0);

    s.repeatUntilStopped = (IsDlgButtonChecked(hwnd, ID_RADIO_UNTILSTOP) == BST_CHECKED);
    
    GetDlgItemText(hwnd, ID_EDIT_REPEAT_COUNT, buffer, 16);
    s.repeatCount = _wtoi(buffer);

    return s;
}
