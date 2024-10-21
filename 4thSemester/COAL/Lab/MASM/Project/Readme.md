# Tic-Tac-Toe Game in Assembly (MASM)

This is a Tic-Tac-Toe game implemented in Assembly language using MASM (Microsoft Macro Assembler). The game can be played against another human or the computer, which uses the Minimax algorithm to make optimal moves. The game board is displayed in the console with colored cells representing the players.

## Features

- Play against another human or the computer.
- The computer uses the Minimax algorithm to make optimal moves.
- The game board is displayed in the console with colored cells:
  - Player 1 (`X`) is displayed in red.
  - Player 2 (`O`) is displayed in blue.
- The game dynamically updates the board after each move.

## Prerequisites

- Visual Studio with MASM support.
- Basic understanding of Assembly language.

## Setup and Build Instructions

1. **Clone the repository:**

   ```bash
   git clone https://github.com/yourusername/tic-tac-toe-asm.git
   cd tic-tac-toe-asm

- Open the project in Visual Studio:
  - Open Visual Studio.
  - Select "File" -> "Open" -> "Project/Solution".
  - Navigate to the cloned repository and open tic-tac-toe-asm.sln.
  - Build the project:
	- Right-click on the solution in the Solution Explorer.
	- Select "Build Solution" (or press Ctrl+Shift+B).
	- Run the project:
      - Press F5 to start the game.
		
# Code Structure
 ## main.asm: 
 The main file containing the game loop and procedures for handling player moves, drawing the board, and checking for wins.
 ## minimax.asm: 
 Contains the Minimax algorithm for the computer player.

# Key Procedures
## main.asm:

 - start: Entry point of the program.
 - mainLoop: The main game loop handling player moves and drawing the board.
 - drawBoard: Displays the current state of the board with colors.
 - setColor: Sets the console text color.
 - setColorForCell: Sets the color for a specific cell in the board.
 - getPlayerMove: Gets the current player's move.
 - updateBoard: Updates the board with the player's move.
 - checkWin: Checks for a winner or a draw.
	- checkLine: Checks if a line (row, column, or diagonal) has the same player's mark.
   	- checkRows: Checks the rows for a win.
	- checkColumns: Checks the columns for a win.
	- checkDiagonals: Checks the diagonals for a win.
	- checkDraw: Checks if the board is full (draw).
	- announceResult: Announces the result of the game (win or draw).
	- playAgain: Asks the players if they want to play again.
	- clearBoard: Clears the board for a new game.
	- resetBoard: Resets the board state.
	- exitGame: Exits the game.
- humanVsHuman: Starts a game between two human players.
- humanVsComputer: Starts a game between a human player and the computer.
	- computerMove: Handles the computer's move using the Minimax algorithm.
	- getEmptyCells: Gets the list of empty cells on the board.
	- getBestMove: Finds the best move for the computer using the Minimax algorithm.
	- getScore: Calculates the score for the current board state.
	- isGameOver: Checks if the game is over.
	- getWinner: Gets the winner of the game.

## minimax.asm:

- minimax: Implements the Minimax algorithm for optimal moves.
- findBestMove: Finds the best move for the computer.
- getEmptyCells: Gets the list of empty cells on the board.
- getScore: Calculates the score for the current board state.

## How to Play

The game starts with Player 1 (X) making a move.
Enter the number (1-9) corresponding to the cell you want to mark.
The game board updates, and it is Player 2's (O) turn or the computer's turn if playing against the CPU.
The game continues until a player wins or the board is full (draw).

## Example Game Board


						 X | O | 3 
						----------
						 4 | X | 6 
						----------
						 O | 8 | X
						----------
In the example above,
X and O are colored in red and blue respectively.
The numbers represent the available cells for the next move.

# Contributing
Contributions are welcome! Please fork the repository and create a pull request with your changes.

# License
This project is licensed under the MIT License - see the LICENSE file for details.

# Acknowledgments
Inspired by various Tic-Tac-Toe implementations and Minimax algorithm tutorials.
Special thanks to the MASM32 community for their support and resources.