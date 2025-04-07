// This is a tic tac toe game written in C
#include <stdio.h>
#include <stdlib.h>
// #include <ctype.h>
#include <time.h>

char board[3][3];

char PLAYER;
char COMPUTER;

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);
void chooseSymbol();

int main()
{
    chooseSymbol();
    char winner = ' ';
    char response = ' ';

    do
    {
        winner = ' ';
        response = ' ';
        resetBoard();
        while (winner == ' ' && checkFreeSpaces() != 0)
        {
            if (PLAYER == 'X')
            {
                printBoard();
                playerMove();
            }
            else
            {
                computerMove();
                printBoard();
            }
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }
            if(PLAYER=='X')
            {
                computerMove();
            }
            else
                playerMove();
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }
        }

        printBoard();
        printWinner(winner);

        printf("\nWould you like to play again? (Y/N): ");
        scanf("\n");
        scanf("%c", &response);
    } while (response == 'Y');

    printf("\nThank you for playing!\n");

    return 0;
}

void resetBoard()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
        // printf("----|----|--\n");
    }
}

int checkFreeSpaces()
{
    int i, j;
    int freeSpaces = 9;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }

    return freeSpaces;
}

void playerMove()
{
    int x;
    int y;

    do
    {
        printf("Enter row #(1-3): ");
        scanf("%d", &x);
        x--;
        printf("Enter column #(1-3): ");
        scanf("%d", &y);
        y--;

        if (board[x][y] != ' ')
        {
            printf("Invalid move. Try again.\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    } while (board[x][y] != ' ');
}

void computerMove()
{
    // Creating a seed based on current time
    srand(time(0));
    int x;
    int y;

    if (checkFreeSpaces() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
    }
    else
    {
        printWinner(' ');
    }
}

char checkWinner()
{
    // Checking rows
    int i;
    for (i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }

    // Checking columns
    for (i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }

    // Checking diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }

    return ' ';
}

void printWinner(char winner)
{
    if (winner == PLAYER)
    {
        printf("Congratulations! You win!\n");
    }
    else if (winner == COMPUTER)
    {
        printf("The computer wins!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }
}

void chooseSymbol()
{
    printf("Enter the symbol u want to choose (X/O):");
    scanf("%c", &PLAYER);

    if (PLAYER == 'X')
        COMPUTER = 'O';
    else
        COMPUTER = 'X';
}