# Tic Tac Toe in C

This is a simple implementation of the classic Tic Tac Toe game written in C. The game allows a human player to play against the computer.

## How to Play

1. The game starts with an empty 3x3 board.
2. The player is prompted to enter the row and column numbers to place their move (X).
3. The computer then makes its move (O) randomly on an available spot.
4. The game continues until there is a winner or the board is full, resulting in a tie.

## Functions

### `void resetBoard()`
Initializes the game board to an empty state.

### `void printBoard()`
Prints the current state of the game board to the console.

### `int checkFreeSpaces()`
Returns the number of free spaces left on the board.

### `void playerMove()`
Prompts the player to enter their move and updates the board accordingly.

### `void computerMove()`
Generates a random move for the computer and updates the board.

### `char checkWinner()`
Checks the board for a winner (either player or computer) or a tie. Returns the winner's symbol ('X' or 'O') or a space character (' ') if there is no winner yet.

### `void printWinner(char winner)`
Prints the result of the game, indicating whether the player won, the computer won, or if it was a tie.

## How to Compile and Run

1. Make sure you have a C compiler installed (e.g., `gcc`).
2. Save the code in a file named `index.c`.
3. Open a terminal and navigate to the directory containing `index.c`.
4. Compile the code using the following command:
    ```sh
    gcc -o tictactoe index.c
    ```
5. Run the compiled program
