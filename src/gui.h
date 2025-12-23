#ifndef GUI_H
#define GUI_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

void CreateControls(HWND hwnd);
void InitializeDefaultValues(HWND hwnd);
struct ClickerSettings GetSettingsFromGUI(HWND hwnd);

#endif
