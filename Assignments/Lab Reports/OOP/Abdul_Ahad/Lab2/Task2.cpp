#include <iostream>

using namespace std;

void drawBoard(char b[3][3], char Cplayer)
{
    cout << "                           column 0            column 1           column 2       " << endl;
    cout << "                                         |                   |                   " << endl;
    cout << "      row 0                    " << b[0][0] << "         |         " << b[0][1] << "         |         " << b[0][2] << "         " << endl;
    cout << "                                         |                   |                   " << endl;
    cout << "                      -----------------------------------------------------------" << endl;
    cout << "                                         |                   |                   " << endl;
    cout << "      row 1                    " << b[1][0] << "         |         " << b[1][1] << "         |         " << b[1][2] << "         " << endl;
    cout << "                                         |                   |                   " << endl;
    cout << "                      -----------------------------------------------------------" << endl;
    cout << "                                         |                   |                   " << endl;
    cout << "      row 2                    " << b[2][0] << "         |         " << b[2][1] << "         |         " << b[2][2] << "         " << endl;
    cout << "                                         |                   |                   " << endl;
    cout << "\n\n\n";
    cout << "Current Player is : " << Cplayer;
    cout << "\n\nEnter your location (row column) : ";
}

void drawFBoard(char b[3][3])
{
    system("cls");
    cout << "                           column 0            column 1           column 2       " << endl;
    cout << "                                         |                   |                   " << endl;
    cout << "      row 0                    " << b[0][0] << "         |         " << b[0][1] << "         |         " << b[0][2] << "         " << endl;
    cout << "                                         |                   |                   " << endl;
    cout << "                      -----------------------------------------------------------" << endl;
    cout << "                                         |                   |                   " << endl;
    cout << "      row 1                    " << b[1][0] << "         |         " << b[1][1] << "         |         " << b[1][2] << "         " << endl;
    cout << "                                         |                   |                   " << endl;
    cout << "                      -----------------------------------------------------------" << endl;
    cout << "                                         |                   |                   " << endl;
    cout << "      row 2                    " << b[2][0] << "         |         " << b[2][1] << "         |         " << b[2][2] << "         " << endl;
    cout << "                                         |                   |                   " << endl;
}


bool checkWinner(char b[3][3])
{
    // horizontal win
    if (b[0][0] == b[0][1] && b[0][1] == b[0][2] && b[0][2] != ' ')
    {
        drawFBoard(b);
        cout << "Winner is : " << b[0][1] << endl;
        return true;
    }
    else if (b[1][0] == b[1][1] && b[1][1] == b[1][2] && b[1][2] != ' ')
    {
        drawFBoard(b);
        cout << "Winner is : " << b[1][1] << endl;
        return true;
    }
    else if (b[2][0] == b[2][1] && b[2][1] == b[2][2] && b[2][2] != ' ')
    {
        drawFBoard(b);
        cout << "Winner is : " << b[2][1] << endl;
        return true;
    }
    // vrtical win
    else if (b[0][0] == b[1][0] && b[1][0] == b[2][0] && b[2][0] != ' ')
    {
        drawFBoard(b);
        cout << "Winner is : " << b[1][0] << endl;
        return true;
    }
    else if (b[0][1] == b[1][1] && b[1][1] == b[2][1] && b[2][1] != ' ')
    {
        drawFBoard(b);
        cout << "Winner is : " << b[1][1] << endl;
        return true;
    }
    else if (b[0][2] == b[1][2] && b[1][2] == b[2][2] && b[2][2] != ' ')
    {
        drawFBoard(b);
        cout << "Winner is : " << b[1][2] << endl;
        return true;
    }
    // diagnal win
    else if (b[0][0] == b[1][1] && b[1][1] == b[2][2] && b[2][2] != ' ')
    {
        drawFBoard(b);
        cout << "Winner is : " << b[1][1] << endl;
        return true;
    }
    else if (b[0][2] == b[1][1] && b[1][1] == b[2][0] && b[2][0] != ' ')
    {
        drawFBoard(b);
        cout << "Winner is : " << b[2][2] << endl;
        return true;
    }
    else
        return false;
}

int main()
{

    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};
    bool boardAvailable[3][3] = {
        {true, true, true},
        {true, true, true},
        {true, true, true}};
    char CPlayer, player1 = 'X', player2 = 'O';
    bool GameOver = false;
    CPlayer = player1;
    int row, col;

    while (!GameOver)
    {
    getinput:
        system("cls");
        drawBoard(board, CPlayer);
        cin >> row >> col;
        if (boardAvailable[row][col])
        {
            if (row < 3 && col < 3 && row > -1 && col > -1)
            {
                board[row][col] = CPlayer;
                boardAvailable[row][col] = false;
            }
            else
            {
                cout << "Row and Column is wrong ReEnter :( (Press Enter to continue)";
                cin.ignore();
                cin.ignore();
                goto getinput;
            }
        }
        else
        {
            cout << "Place Occupied ReEnter :( (Press Enter to continue)";
            cin.ignore();
            cin.ignore();
            goto getinput;
        }
        if (CPlayer == player1)
            CPlayer = player2;
        else
            CPlayer = player1;

        if (checkWinner(board))
            GameOver = true;
    }

    return 0;
}