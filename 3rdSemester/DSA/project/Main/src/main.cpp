#include <windows.h>
#include <gl/gl.h>

#include "../include/util.h"

// Forward declaration of WndProc
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSW wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"Main_Window"; // Use wide string literal for class name

    RegisterClassW(&wc); // Use RegisterClassA if working with ANSI characters

    HWND hWnd;
    MSG msg;
    BOOL bQuit = FALSE;

    /* create main window */
    hWnd = CreateWindowW(
        L"Main_Window", L"My OpenGL Program",
        WS_CAPTION | WS_POPUPWINDOW | WS_VISIBLE,
        0, 0, 800, 600, // Adjusted window size
        NULL, NULL, hInstance, NULL);

    GameManager gameManager;
    gameManager.EnableOpenGL(hWnd);

    /* program main loop */
    while (!bQuit)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            if (gameManager.getCurrentGame() != nullptr)
            {
                gameManager.getCurrentGame()->play();
                SwapBuffers(gameManager.getHDC());
            }
        }
    }

    gameManager.DisableOpenGL(hWnd);
    DestroyWindow(hWnd);

    return msg.wParam;
}

// Implement WndProc here or include its definition
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        return 0;
    case WM_CLOSE:
        PostQuitMessage(0);
        return 0;

    case WM_DESTROY:
        return 0;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            PostQuitMessage(0);
            return 0;
        }
        return 0;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
}
