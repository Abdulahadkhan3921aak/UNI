#include <iostream>
#include <cstring>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

void displayBoard(char board[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isWin(char board[][COLS], char player)
{
    for (int i = 0; i < ROWS; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
    }

    for (int j = 0; j < COLS; j++)
    {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
        {
            return true;
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true;
    }

    return false;
}

bool isTie(char board[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] == '-')
            {
                return false;
            }
        }
    }
    return true;
}

void playGame()
{
    char board[ROWS][COLS];
    memset(board, '-', sizeof(board)); // Initialize board to all '-'

    char currentPlayer = 'X';
    bool isGameDone = false;

    while (!isGameDone)
    {
        displayBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << " Enter your move (row col): ";
        cin >> row >> col;

        if (row < 0 || row >= ROWS || col < 0 || col >= COLS)
        {
            cout << "Invalid move, try again." << endl;
            continue;
        }

        if (board[row][col] != '-')
        {
            cout << "That cell is already occupied, try again." << endl;
            continue;
        }

        board[row][col] = currentPlayer;

        if (isWin(board, currentPlayer))
        {
            cout << "Player " << currentPlayer << " has won the game!" << endl;
            isGameDone = true;
        }
        else if (isTie(board))
        {
            cout << "The game is a tie!" << endl;
            isGameDone = true;
        }
        else
        {
            // Switch to the other player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    displayBoard(board);
}

int main()
{
    cout << "Welcome to Tic Tac Toe!" << endl;

    while (true)
    {
        playGame();

        char playAgain;
        cout << "Play again? (y/n): ";
        cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y')
        {
            break;
        }
    }

    cout << "Thanks for playing!" << endl;

    return 0;
}
