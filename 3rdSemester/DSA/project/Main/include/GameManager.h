// GameManager.h
#pragma once

#include "Game.h"
#include "TicTacToe.h" // Include the TicTacToe class

class GameManager
{
private:
    Game *currentGame = new TicTacToe();
    HDC hDC;
    HGLRC hRC;
    HWND hWnd;
    TicTacToe ticTacToe; // Add an instance of TicTacToe

public:
    GameManager();
    ~GameManager();

    void startGame(Game *game);
    void startTicTacToe(); // New method to start Tic Tac Toe
    void EnableOpenGL(HWND hWnd);
    void DisableOpenGL(HWND hWnd);

    // Add getter methods if needed
    Game *getCurrentGame() const { return currentGame; }
    HDC getHDC() const { return hDC; }
};
