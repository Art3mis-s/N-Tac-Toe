#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

const int N = 10; // The board Max size is 10
void initBoard(char board[N][N], int n); // initialize the board
void printBoard(char board[N][N], int n); // print the board
bool isGameOver(char board[N][N], int n); // check if the game is over
void getPlayerInput(char board[N][N], int n, char playerChar); // get player input
void getRandomInput(char board[N][N], int n, char playerChar);

int main() // Main function to run the game 
{
    int p1 = -1;
    int p2 = -1; 

    srand(time(0)); //This seeds the random function
    char board[10][10];

    while (p1 != 0 && p1 != 1)
    {
        cout << "Is player 1 human, enter 1, else enter 0" << endl;
        cin >> p1; 
    }
    while (p2 != 0 && p2 != 1)
    {
        cout << "Is player 2 human, enter 1, else enter 0" << endl;
        cin >> p2; 
    }

    int n;
    do
    {
        cout << "Enter the board size (3-10): " << endl;
        cin >> n;

    }
    while (n < 3 || n > 10);

    initBoard(board, n);  // Initializes the 'board' and the user input 'n'
    //Print the board to see the results 
    printBoard(board, n);

    char playerChar = 'X'; // Player 1 starts with 'X'
    while (!isGameOver(board, n)) 
    {
        if (p1 == 1)
        {
            getPlayerInput(board, n, playerChar);
        }
        else
        {
            getRandomInput(board, n, playerChar);
        }
        //getPlayerInput(board, n, playerChar); // Get player input
        //getRandomInput(board, n, playerChar); 
        printBoard(board, n); // Print the updated board

        // Toggle players
        if (playerChar == 'X') 
        {
            playerChar = 'O';
        } else {
            playerChar = 'X';
        }
    }

    return 0;
}

void initBoard(char board[N][N], int n) // Initialize the board
{
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            board[r][c] = '_'; // Initialize each cell to '_'
        }
    }
}

void printBoard(char board[N][N], int n) // Print the board
{
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            cout << board[r][c]; // Initialize each cell to '_'
        }
        cout << endl;
    }
}

void getPlayerInput(char board[N][N], int n, char playerChar) // Get player input (row and column) and assign the player's character to the selected cell
{
    int row, col; // Variables to store the row and column
    
    do
    {
        // Prompt user to input row (within range)
        do
        {
            cout << "Enter the row (0 to " << n - 1 << "): " << endl; 
            cin >> row;
        } while (row < 0 || row >= n); // Ensure row is within range

        // Prompt user to input column (within range)
        do
        {
            cout << "Enter the column (0 to " << n - 1 << "): " << endl;
            cin >> col;
        } while (col < 0 || col >= n); // Ensure column is within range

        // Check if the selected cell is taken
        if (board[row][col] != '_')
        {
            cout << "Cell is already taken! Try again." << endl;
        }

    } while (board[row][col] != '_'); // Repeat if cell is taken

    // Assign the player's character to the selected cell
    board[row][col] = playerChar;
}

bool isGameOver(char board[N][N], int n) // Check if the game is over and determine who's the winner.
{
    // Checking rows
    for (int r = 0; r < n; r++) 
    {
        bool rowWin = true;
        for (int c = 1; c < n; c++) 
        {
            if (board[r][c] != board[r][0] || board[r][c] == '_') 
            {
                rowWin = false;
                break;
            }
        }
        if (rowWin) 
        {
            cout << "Player " << board[r][0] << " wins!" << endl;
            return true;
        }
    }

    // Checking columns
    for (int c = 0; c < n; c++) 
    {
        bool colWin = true;
        for (int r = 1; r < n; r++) 
        {
            if (board[r][c] != board[0][c] || board[r][c] == '_') 
            {
                colWin = false;
                break;
            }
        }
        if (colWin) 
        {
            cout << "Player " << board[0][c] << " wins!" << endl;
            return true;
        }
    }

    // Forward diagonal
    bool forwardDiagonalWin = true;
    for (int i = 0; i < n; i++) 
    {
        if (board[i][i] != board[0][0] || board[i][i] == '_') 
        {
            forwardDiagonalWin = false;
            break;
        }
    }
    if (forwardDiagonalWin) 
    {
        cout << "Player " << board[0][0] << " wins!" << endl;
        return true;
    }

    // Backward diagonal
    bool backwardDiagonalWin = true;
    for (int i = 0; i < n; i++) 
    {
        if (board[i][n-i-1] != board[0][n-1] || board[i][n-i-1] == '_') 
        {
            backwardDiagonalWin = false;
            break;
        }
    }
    if (backwardDiagonalWin) 
    {
        cout << "Player " << board[0][n-1] << " wins!" << endl;
        return true;
    }

    // If there is no winner and the board is full, it's a tie
    bool isTie = true;
    for (int r = 0; r < n; r++) 
    {
        for (int c = 0; c < n; c++) 
        {
            if (board[r][c] == '_') 
            {
                isTie = false;
                break;
            }
        }
    }
    if (isTie) 
    {
        cout << "It's a tie!" << endl;
        return true;
    }

    return false; // Game is not over
}

void getRandomInput(char board[N][N], int n, char playerChar)
{
    int col;
    int row;
    do 
    {
        col = rand() % n;
        row = rand() % n;
    }
    while (board[row][col] != '_'); 
    board[row][col] = playerChar; 
}
