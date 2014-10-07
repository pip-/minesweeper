//runner.c by Philip Gilbreth
//Minecraft by Philip Gilbreth
//12384560
//10/7/2014
//LAB_C
//Jace, the Mind Sculpter
//ATTEMPTED BONUS
#include <stdio.h>
#include "minesweeper.h"

//Main code running the game
int main(int argc, char* argv[])
{
	//Make sure coreect number of command line arguments
	if(argc != 2)
	{
		printf("Incorrect number of command line arguemnts");
		return 0;
	}
	
	//Assign argument to an int
	int numBomb = atoi(argv[1]);
	
	//Create the board
	PositionType board[BoardSize][BoardSize];
	setBoard(board, numBomb);
	

	//Play Game
	int run = 1;
	int notBomb = BoardSize * BoardSize - numBomb;
	while(run == 1)
	{
		displayBoard(board);

		//Ask for a guess
		int row, col;
		printf("\n\nPlease select a row: ");
		scanf("%d", &row);
		printf("\nPlease select a column: ");
		scanf("%d", &col);
		//Fix offset
		row = row-1;
		col = col-1;

		//process guess according to rules defined in processGuess function and change spots on board accordingly
		switch (processGuess(board, row, col))
		{
			case 0:
				printf("\nSPOT WAS ALREADY UNCOVERED\n");
				break;
			case 1:
				board[row][col] = uncovered;
				notBomb--;
				break;
			case 2:
				board[row][col] = uncoveredBomb;
				displayBoard(board);
				printf("\n\nBOMB FOUND\nGAME OVER");
				run = 0;
				break;
			default:
				printf("\nINVALID SELECTION\n");
				break;
		}
		
		//Check win condition
		if(notBomb == 0)
		{
			printf("\nALL BOMBS CLEARED\nYOU WIN");
			run = 0;
		}

	}
}
