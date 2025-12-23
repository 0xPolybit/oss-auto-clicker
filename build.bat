@echo off
echo Compiling Auto Clicker...

:: Check if g++ is available
where g++ >nul 2>nul
if %errorlevel% neq 0 (
    echo Error: g++ not found. Please install MinGW or another C++ compiler.
    echo Alternatively, if you have Visual Studio, use the Developer Command Prompt and run:
    echo cl src/*.cpp /Fe:AutoClicker.exe user32.lib gdi32.lib
    pause
    exit /b
)

:: Compile with g++
:: -static: Links libraries statically so the exe runs without extra DLLs
:: -mwindows: Creates a GUI application (no console window)
:: -I src: Adds the src directory to include path (fixes missing header issue)
:: -DUNICODE -D_UNICODE: Enables Unicode support in Windows headers
:: -municode: Tells the linker to use wWinMain as the entry point
g++ -I src -DUNICODE -D_UNICODE src/main.cpp src/gui.cpp src/clicker.cpp -o AutoClicker.exe -static -mwindows -municode

if %errorlevel% equ 0 (
    echo Build successful! Run AutoClicker.exe to start.
) else (
    echo Build failed.
)
pause
