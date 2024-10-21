// GameManager.cpp
#include "GameManager.h"
#include <windows.h>
#include <gl/gl.h>

GameManager::GameManager() : currentGame(nullptr) {}

GameManager::~GameManager() {
    if (currentGame != nullptr) {
        currentGame->end();
        delete currentGame;
    }
    DisableOpenGL(hWnd);  // Pass hWnd as a parameter
}

void GameManager::startGame(Game* game) {
    if (currentGame != nullptr) {
        currentGame->end();
        delete currentGame;
    }

    currentGame = game;
    currentGame->initialize();
    currentGame->play();
}

void GameManager::startTicTacToe() {
    startGame(&ticTacToe); // Start Tic Tac Toe game
}

void GameManager::EnableOpenGL(HWND hWnd) {
    PIXELFORMATDESCRIPTOR pfd;
    int iFormat;

    this->hWnd = hWnd; // Store hWnd

    hDC = GetDC(hWnd);

    ZeroMemory(&pfd, sizeof(pfd));
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;
    iFormat = ChoosePixelFormat(hDC, &pfd);
    SetPixelFormat(hDC, iFormat, &pfd);

    hRC = wglCreateContext(hDC);
    wglMakeCurrent(hDC, hRC);
}

void GameManager::DisableOpenGL(HWND hWnd) {
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hRC);
    ReleaseDC(hWnd, hDC);
}

