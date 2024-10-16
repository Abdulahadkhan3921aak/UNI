// TicTacToe.cpp
#include "TicTacToe.h"
#include <iostream>
#include <cstdlib>

TicTacToe::TicTacToe() : currentPlayer('X') {
    // Initialize the board with empty spaces
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void TicTacToe::initialize() {

  // Clear color to white
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}



void TicTacToe::play() {
    int row, col;
	
	drawBoard();
	
    do {
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        // Check if the move is valid
        if (isMoveValid(row, col)) {
            board[row][col] = currentPlayer;
            drawBoard();
            if (checkWin()) {
                std::cout << "Player " << currentPlayer << " wins!\n";
                return;
            }
            if (checkDraw()) {
                std::cout << "It's a draw!\n";
                return;
            }
            // Switch to the next player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            std::cout << "Invalid move. Try again.\n";
        }

    } while (true);
}

void TicTacToe::end() {
    std::cout << "Thanks for playing Tic Tac Toe!\n";
}

void TicTacToe::printBoard() {
    // Print the current state of the board to the console
    std::cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void TicTacToe::drawBoard()
{
  glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

  // Draw the Tic Tac Toe grid
  glColor3f(1.0f, 1.0f, 1.0f); // Set color to white
  glBegin(GL_LINES);
  for (int i = 1; i < 3; ++i) {
    // Draw horizontal lines
    glVertex2f(-1.0f, i * 2.0f / 3.0f);
    glVertex2f(1.0f, i * 2.0f / 3.0f);

    // Draw vertical lines
    glVertex2f(i * 2.0f / 3.0f, -1.0f);
    glVertex2f(i * 2.0f / 3.0f, 1.0f);
  }
  glEnd();

  // Draw X and O symbols on the board
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (board[i][j] == 'X') {
        glColor3f(1.0f, 0.0f, 0.0f); // Set color to red for X
        glBegin(GL_LINES);
        glVertex2f(j * 2.0f / 3.0f, i * 2.0f / 3.0f);
        glVertex2f((j + 1) * 2.0f / 3.0f, (i + 1) * 2.0f / 3.0f);
        glVertex2f((j + 1) * 2.0f / 3.0f, i * 2.0f / 3.0f);
        glVertex2f(j * 2.0f / 3.0f, (i + 1) * 2.0f / 3.0f);
        glEnd();
      }
      else if (board[i][j] == 'O') {
        glColor3f(0.0f, 0.0f, 1.0f); // Set color to blue for O
        glBegin(GL_LINE_LOOP);
        for (int k = 0; k < 360; k += 10) {
          float radian = k * 3.14159265358979323846 / 180.0;
          glVertex2f(j * 2.0f / 3.0f + 0.2f * cos(radian), i * 2.0f / 3.0f + 0.2f * sin(radian));
        }
        glEnd();
      }
    }
  }

  glFlush(); // Flush the OpenGL pipeline
}


bool TicTacToe::isMoveValid(int row, int col) {
    // Check if the cell is empty and the move is within the board bounds
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

bool TicTacToe::checkWin() {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true; // Row win
        }
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
            return true; // Column win
        }
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true; // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true; // Diagonal win (top-right to bottom-left)
    }
    return false;
}

bool TicTacToe::checkDraw() {
    // Check if the board is full (no empty spaces)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false; // There is an empty space, the game is not a draw
            }
        }
    }
    return true; // The board is full, and there is no winner, it's a draw
}

