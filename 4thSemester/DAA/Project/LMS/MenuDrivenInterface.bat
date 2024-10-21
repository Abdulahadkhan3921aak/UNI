@echo off
:: Clear the screen
cls

:: Display message
echo Compiling the C++ source files...

:: Compile the C++ source files
g++ -std=c++11 -o LMS(MDI) src/Main(MDI).cpp src/Library.cpp src/Book.cpp src/Member.cpp

:: Check if the compilation was successful
if %errorlevel% neq 0 (
    echo Compilation failed.
    pause
    exit /b %errorlevel%
)

:: Display message
echo Compilation successful.

:: Run the executable
echo Running the program...
"LMS(MDI)"

:: Wait for user input before closing
pause
