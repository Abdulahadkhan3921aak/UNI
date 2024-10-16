// TicTacToe.h
#pragma once

#include "Game.h"
#include <windows.h>
#include <gl/gl.h>
#include <Math.h>



class TicTacToe : public Game {
private:
    char board[3][3]; // 3x3 Tic Tac Toe board
    char currentPlayer;

public:
    TicTacToe();
    virtual void initialize() override;
    virtual void play() override;
    virtual void end() override;

private:
    void printBoard();
    bool isMoveValid(int row, int col);
    bool checkWin();
    bool checkDraw();
    void drawBoard();
};

