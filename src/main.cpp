#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <commctrl.h>
#include "common.h"
#include "gui.h"
#include "clicker.h"

AutoClicker g_clicker;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CREATE:
        CreateControls(hwnd);
        RegisterHotKey(hwnd, ID_HOTKEY_F6, 0, VK_F6);
        break;

    case WM_CTLCOLORSTATIC:
    {
        HDC hdcStatic = (HDC)wParam;
        SetBkColor(hdcStatic, RGB(255, 255, 255));
        SetBkMode(hdcStatic, TRANSPARENT);
        return (INT_PTR)GetStockObject(WHITE_BRUSH);
    }

    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case ID_BTN_START:
            g_clicker.Start(GetSettingsFromGUI(hwnd));
            EnableWindow(GetDlgItem(hwnd, ID_BTN_START), FALSE);
            EnableWindow(GetDlgItem(hwnd, ID_BTN_STOP), TRUE);
            break;
        case ID_BTN_STOP:
            g_clicker.Stop();
            EnableWindow(GetDlgItem(hwnd, ID_BTN_START), TRUE);
            EnableWindow(GetDlgItem(hwnd, ID_BTN_STOP), FALSE);
            break;
        }
        break;

    case WM_HOTKEY:
        if (wParam == ID_HOTKEY_F6) {
            if (g_clicker.IsRunning()) {
                SendMessage(hwnd, WM_COMMAND, ID_BTN_STOP, 0);
            } else {
                SendMessage(hwnd, WM_COMMAND, ID_BTN_START, 0);
            }
        }
        break;

    case WM_DESTROY:
        UnregisterHotKey(hwnd, ID_HOTKEY_F6);
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {
    // Initialize Common Controls (for modern look)
    INITCOMMONCONTROLSEX icex;
    icex.dwSize = sizeof(INITCOMMONCONTROLSEX);
    icex.dwICC = ICC_WIN95_CLASSES | ICC_STANDARD_CLASSES;
    InitCommonControlsEx(&icex);

    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = L"AutoClickerClass";
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, L"Window Registration Failed!", L"Error", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        L"AutoClickerClass",
        L"OSS Auto Clicker v0.1 Beta",
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT, 520, 320,
        NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) {
        MessageBox(NULL, L"Window Creation Failed!", L"Error", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&Msg, NULL, 0, 0) > 0) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}
