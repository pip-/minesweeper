//minesweeper.h by Philip Gilbreth
//Function Prototypes
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef enum {
	covered,
	uncovered,
	coveredBomb,
	uncoveredBomb
} PositionType;

#define BoardSize 10

void setBoard(PositionType board[BoardSize][BoardSize], int numMines);
void displayBoard(PositionType board[BoardSize][BoardSize]);
int processGuess(PositionType board[BoardSize][BoardSize], int row, int col);
int main(int argc, char* argv[]);
int adjBomb(PositionType board[BoardSize][BoardSize], int row, int col);

