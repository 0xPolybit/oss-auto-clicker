#include "gui.h"
#include "common.h"
#include <windows.h>
#include <commctrl.h>
#include <string>
#include <vector>

void CreateControls(HWND hwnd) {
    HFONT hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);

    // --- Click Interval Group ---
    HWND hGroup1 = CreateWindow(L"BUTTON", L"Click Interval", WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
        10, 10, 485, 70, hwnd, NULL, NULL, NULL);
    SendMessage(hGroup1, WM_SETFONT, (WPARAM)hFont, TRUE);

    // Hours
    HWND hStatic1 = CreateWindow(L"STATIC", L"Hours", WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE, 20, 33, 40, 20, hwnd, NULL, NULL, NULL);
    SendMessage(hStatic1, WM_SETFONT, (WPARAM)hFont, TRUE);
    HWND hEdit1 = CreateWindow(L"EDIT", L"0", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, 60, 30, 60, 23, hwnd, (HMENU)ID_EDIT_HOURS, NULL, NULL);
    SendMessage(hEdit1, WM_SETFONT, (WPARAM)hFont, TRUE);
    HWND hUpDn1 = CreateWindow(UPDOWN_CLASS, NULL, WS_CHILD | WS_VISIBLE | UDS_SETBUDDYINT | UDS_ALIGNRIGHT | UDS_AUTOBUDDY | UDS_ARROWKEYS, 0, 0, 0, 0, hwnd, NULL, NULL, NULL);
    SendMessage(hUpDn1, UDM_SETBUDDY, (WPARAM)hEdit1, 0);
    SendMessage(hUpDn1, UDM_SETRANGE, 0, MAKELPARAM(999, 0));
    SendMessage(hUpDn1, UDM_SETPOS, 0, 0);

    // Mins
    HWND hStatic2 = CreateWindow(L"STATIC", L"Mins", WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE, 130, 33, 40, 20, hwnd, NULL, NULL, NULL);
    SendMessage(hStatic2, WM_SETFONT, (WPARAM)hFont, TRUE);
    HWND hEdit2 = CreateWindow(L"EDIT", L"0", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, 170, 30, 60, 23, hwnd, (HMENU)ID_EDIT_MINS, NULL, NULL);
    SendMessage(hEdit2, WM_SETFONT, (WPARAM)hFont, TRUE);
    HWND hUpDn2 = CreateWindow(UPDOWN_CLASS, NULL, WS_CHILD | WS_VISIBLE | UDS_SETBUDDYINT | UDS_ALIGNRIGHT | UDS_AUTOBUDDY | UDS_ARROWKEYS, 0, 0, 0, 0, hwnd, NULL, NULL, NULL);
    SendMessage(hUpDn2, UDM_SETBUDDY, (WPARAM)hEdit2, 0);
    SendMessage(hUpDn2, UDM_SETRANGE, 0, MAKELPARAM(59, 0));
    SendMessage(hUpDn2, UDM_SETPOS, 0, 0);

    // Secs
    HWND hStatic3 = CreateWindow(L"STATIC", L"Secs", WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE, 240, 33, 40, 20, hwnd, NULL, NULL, NULL);
    SendMessage(hStatic3, WM_SETFONT, (WPARAM)hFont, TRUE);
    HWND hEdit3 = CreateWindow(L"EDIT", L"0", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, 280, 30, 60, 23, hwnd, (HMENU)ID_EDIT_SECS, NULL, NULL);
    SendMessage(hEdit3, WM_SETFONT, (WPARAM)hFont, TRUE);
    HWND hUpDn3 = CreateWindow(UPDOWN_CLASS, NULL, WS_CHILD | WS_VISIBLE | UDS_SETBUDDYINT | UDS_ALIGNRIGHT | UDS_AUTOBUDDY | UDS_ARROWKEYS, 0, 0, 0, 0, hwnd, NULL, NULL, NULL);
    SendMessage(hUpDn3, UDM_SETBUDDY, (WPARAM)hEdit3, 0);
    SendMessage(hUpDn3, UDM_SETRANGE, 0, MAKELPARAM(59, 0));
    SendMessage(hUpDn3, UDM_SETPOS, 0, 0);

    // Millis
    HWND hStatic4 = CreateWindow(L"STATIC", L"Millis", WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE, 350, 33, 40, 20, hwnd, NULL, NULL, NULL);
    SendMessage(hStatic4, WM_SETFONT, (WPARAM)hFont, TRUE);
    HWND hEdit4 = CreateWindow(L"EDIT", L"100", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, 395, 30, 80, 23, hwnd, (HMENU)ID_EDIT_MILLIS, NULL, NULL);
    SendMessage(hEdit4, WM_SETFONT, (WPARAM)hFont, TRUE);
    HWND hUpDn4 = CreateWindow(UPDOWN_CLASS, NULL, WS_CHILD | WS_VISIBLE | UDS_SETBUDDYINT | UDS_ALIGNRIGHT | UDS_AUTOBUDDY | UDS_ARROWKEYS, 0, 0, 0, 0, hwnd, NULL, NULL, NULL);
    SendMessage(hUpDn4, UDM_SETBUDDY, (WPARAM)hEdit4, 0);
    SendMessage(hUpDn4, UDM_SETRANGE, 0, MAKELPARAM(999, 0));
    SendMessage(hUpDn4, UDM_SETPOS, 0, 100);

    // --- Click Options Group ---
    HWND hGroup2 = CreateWindow(L"BUTTON", L"Click Options", WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
        10, 90, 220, 100, hwnd, NULL, NULL, NULL);
    SendMessage(hGroup2, WM_SETFONT, (WPARAM)hFont, TRUE);

    HWND hStatic5 = CreateWindow(L"STATIC", L"Mouse Button:", WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE, 20, 113, 90, 20, hwnd, NULL, NULL, NULL);
    SendMessage(hStatic5, WM_SETFONT, (WPARAM)hFont, TRUE);
    HWND hComboBtn = CreateWindow(L"COMBOBOX", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, 
        110, 110, 100, 100, hwnd, (HMENU)ID_COMBO_MOUSEBTN, NULL, NULL);
    SendMessage(hComboBtn, WM_SETFONT, (WPARAM)hFont, TRUE);
    SendMessage(hComboBtn, CB_ADDSTRING, 0, (LPARAM)L"Left");
    SendMessage(hComboBtn, CB_ADDSTRING, 0, (LPARAM)L"Right");
    SendMessage(hComboBtn, CB_ADDSTRING, 0, (LPARAM)L"Middle");
    SendMessage(hComboBtn, CB_SETCURSEL, 0, 0);

    HWND hStatic6 = CreateWindow(L"STATIC", L"Click Type:", WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE, 20, 148, 90, 20, hwnd, NULL, NULL, NULL);
    SendMessage(hStatic6, WM_SETFONT, (WPARAM)hFont, TRUE);
    HWND hComboType = CreateWindow(L"COMBOBOX", L"", WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, 
        110, 145, 100, 100, hwnd, (HMENU)ID_COMBO_CLICKTYPE, NULL, NULL);
    SendMessage(hComboType, WM_SETFONT, (WPARAM)hFont, TRUE);
    SendMessage(hComboType, CB_ADDSTRING, 0, (LPARAM)L"Single");
    SendMessage(hComboType, CB_ADDSTRING, 0, (LPARAM)L"Double");
    SendMessage(hComboType, CB_SETCURSEL, 0, 0);

    // --- Click Repeat Group ---
    HWND hGroup3 = CreateWindow(L"BUTTON", L"Click Repeat", WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
        240, 90, 255, 100, hwnd, NULL, NULL, NULL);
    SendMessage(hGroup3, WM_SETFONT, (WPARAM)hFont, TRUE);

    HWND hRadio1 = CreateWindow(L"BUTTON", L"Repeat", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
        250, 115, 70, 20, hwnd, (HMENU)ID_RADIO_REPEAT, NULL, NULL);
    SendMessage(hRadio1, WM_SETFONT, (WPARAM)hFont, TRUE);
    HWND hEditRepeat = CreateWindow(L"EDIT", L"1", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, 
        320, 115, 80, 23, hwnd, (HMENU)ID_EDIT_REPEAT_COUNT, NULL, NULL);
    SendMessage(hEditRepeat, WM_SETFONT, (WPARAM)hFont, TRUE);
    HWND hUpDnRepeat = CreateWindow(UPDOWN_CLASS, NULL, WS_CHILD | WS_VISIBLE | UDS_SETBUDDYINT | UDS_ALIGNRIGHT | UDS_AUTOBUDDY | UDS_ARROWKEYS, 0, 0, 0, 0, hwnd, NULL, NULL, NULL);
    SendMessage(hUpDnRepeat, UDM_SETBUDDY, (WPARAM)hEditRepeat, 0);
    SendMessage(hUpDnRepeat, UDM_SETRANGE, 0, MAKELPARAM(9999, 1));
    SendMessage(hUpDnRepeat, UDM_SETPOS, 0, 1);

    HWND hStatic7 = CreateWindow(L"STATIC", L"times", WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE, 410, 118, 40, 20, hwnd, NULL, NULL, NULL);
    SendMessage(hStatic7, WM_SETFONT, (WPARAM)hFont, TRUE);

    HWND hRadio2 = CreateWindow(L"BUTTON", L"Repeat until stopped", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
        250, 150, 150, 20, hwnd, (HMENU)ID_RADIO_UNTILSTOP, NULL, NULL);
    SendMessage(hRadio2, WM_SETFONT, (WPARAM)hFont, TRUE);
    
    // Select "Repeat until stopped" by default
    CheckRadioButton(hwnd, ID_RADIO_REPEAT, ID_RADIO_UNTILSTOP, ID_RADIO_UNTILSTOP);

    // --- Action Buttons ---
    HWND hBtnStart = CreateWindow(L"BUTTON", L"Start (F6)", WS_CHILD | WS_VISIBLE, 
        50, 210, 160, 50, hwnd, (HMENU)ID_BTN_START, NULL, NULL);
    SendMessage(hBtnStart, WM_SETFONT, (WPARAM)hFont, TRUE);

    HWND hBtnStop = CreateWindow(L"BUTTON", L"Stop (F6)", WS_CHILD | WS_VISIBLE, 
        290, 210, 160, 50, hwnd, (HMENU)ID_BTN_STOP, NULL, NULL);
    SendMessage(hBtnStop, WM_SETFONT, (WPARAM)hFont, TRUE);
    EnableWindow(hBtnStop, FALSE);
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
