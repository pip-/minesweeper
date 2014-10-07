#include "minesweeper.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Populate board randomly with mines
void setBoard(PositionType board[BoardSize][BoardSize], int numMines)
{
			srand(time(NULL));

	//Make all spots covered
	int x, y;
	for(x=0; x<BoardSize; x++)
	{
		for(y=0; y<BoardSize; y++)
		{
				board[x][y] = covered;
		}
	}
	
	//Place Mines
	int i;
	for(i=0; i<numMines; i++)
	{
		//Pick random spots on the board until one without a bomb is found

		int x = rand() % BoardSize;
		int y = rand() % BoardSize;
		if(board[x][y] == coveredBomb)
		{
			i--;
			continue;
		}
			board[x][y] = coveredBomb;
	}
}

//Print out the current board
void displayBoard(PositionType board[BoardSize][BoardSize])
{
	int x, y;
	printf("\n\n\t1 2 3 4 5 6 7 8 9 10 \n\n");
	for(x=0; x<BoardSize; x++)
	{
		printf("%d\t", x+1);
		for(y=0; y<BoardSize; y++)
		{
			switch (board[x][y])
			{
				case uncoveredBomb:
					printf("@ ");
					break;
				case uncovered:
					printf("%d ", adjBomb(board, x, y));
					break;
				default:
					printf("# ");
					break;
			}
		}
		printf("\n");
	}
}

//Process player's guess
int processGuess(PositionType board[BoardSize][BoardSize], int row, int col)
{
	//Make sure indicy guessed is valid
	if(row+1>10 || row+1<1 || col+1>10 || col+1<1)
	{
		return -1;
	}
	//If spot if uncovered, return 0.
	if(board[row][col] == uncovered)
	{
		return 0;

	}
	//If spot is covered and no bomb, return 1.
	else if(board[row][col] == covered)
	{
		return 1;
	}
	//If spot is bomb, return 2
	else if(board[row][col] == coveredBomb)
	{
		return 2;
	}
}

//Counts the number of bombs in the 3x3 block around selection
int adjBomb(PositionType board[BoardSize][BoardSize], int row, int col)
{
	int curRow, curCol, numBomb=0;
	
	for(curRow=row-1; curRow<=row+1; curRow++)
	{
		for(curCol=col-1; curCol<=col+1; curCol++)
		{
			//Makes sure selection is actually on board
			if(curRow>=0 && curRow <BoardSize && curCol>=0 && curCol<BoardSize)
			{
				if(board[curRow][curCol] == coveredBomb)
				{
					numBomb++;
				}
			}
		}
	}
	return numBomb;
}
			


	

