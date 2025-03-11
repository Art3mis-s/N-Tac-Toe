# N-Tac-Toe with C++

Overview

This is a simple console-based Tic-Tac-Toe game implemented in C++. The game supports both human and AI players, allowing users to play against each other or against a computer-controlled opponent.

	Features

Supports board sizes from 3x3 up to 10x10.

Two-player mode: Both players can be human, or one can be AI.

AI moves are randomly generated.

Detects winning conditions for rows, columns, and diagonals.

Declares a winner or a tie when the game ends.

	How to Play

The game asks whether each player is human (1) or AI (0).

The user specifies the board size (between 3 and 10).

Players take turns placing their mark (X or O) on the board.

If a player wins or the board fills up, the game announces the result.

	Compilation & Execution

To compile and run the program:

 g++ -o tic_tac_toe tic_tac_toe.cpp
 ./tic_tac_toe

	Code Structure

initBoard(): Initializes the board with empty spaces (_).

printBoard(): Displays the current state of the board.

getPlayerInput(): Accepts and validates human player moves.

getRandomInput(): Generates random AI moves.

isGameOver(): Checks for a winner or a tie.

	Dependencies

Standard C++ libraries (iostream, iomanip, string, vector, ctime)
