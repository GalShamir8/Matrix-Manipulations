#include <stdio.h>
#include "functionMat.h"
#include "picMan.h"

void printMatrix(int* mat, int rows, int cols)
{
	printf("\nPrinting matrix:\n");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%5d", *mat);
			mat++;
		}
		printf("\n");
	}
}

void swap(int* mat, int row1, int col1, int row2, int col2)
{
	int temp = *(mat + (COL* row1) + col1);
	*(mat + (COL* row1) + col1) = *(mat + (COL*row2) + col2);
	*(mat + (COL*row2) + col2) = temp;
}

int getRand(int min, int max)
{
	return min + (rand() % (max - min + 1));
}

//////////////////////////////////////////////////////////Q1////////////////////////////////////////////////////
void flipHorizontally(int *mat , int rows, int cols)
{
	for (int i = 0; i < (rows/2); i++)
	{	
		for (int j = 0; j < cols; j++)
		{
			int from = rows - i - 1;
			swap(mat, i, j, from, j);	
		}
	}
}

void flipVertically(int *mat , int rows, int cols)
{
	for (int i = 0; i < (cols/2); i++)
	{	
		for (int j = 0; j < rows; j++)
		{
			int from = cols - i - 1;
			swap(mat, j, i, j, from);	
		}
	}

}

void RotateClockwise(int *mat , int rows, int cols)
{
	for(int i=0 ; i < (rows/2); i++)
	{
		handlerClockwise(i, mat, rows, cols);
		cols--;
	}

}

void handlerClockwise(int squareIndex,int* mat,int rows,int cols)
{
	int pointer=0;
	for(int j=squareIndex; j < cols-1; j++)
	{	
	
		int firstR = squareIndex;
		int firstC = j;
		int secR = j;
		int secC = cols - 1;
		swap90Clockwise(mat, firstR, firstC, secR, secC, pointer);
		pointer++;
	}
	
}

void swap90Clockwise(int* mat, int firstR, int firstC, int secR, int secC,int pointer)
{
	int index = secC;
	int first = *(mat + (COL*firstR) + firstC);
	int second= *(mat + (COL*secR) + secC);
	int third = *(mat + (COL * index) + (index-pointer));
	int fourth = *(mat + (COL*(index-pointer)) + firstR);
	 *(mat + (COL*firstR) + firstC) = fourth;// first = fourth 
	 *(mat + (COL*secR) + secC) = first; // second = first
	 *(mat + (COL * index) + (index-pointer)) = second; // third = second
	 *(mat + (COL*(index-pointer)) + firstR) = third; // fourth = third
}


void RotateCounterClockwise(int *mat , int rows, int cols)
{

	for(int i=0 ; i < (cols/2); i++)
	{
		handlerCounterClockwise(i, mat, rows, cols);
		rows--;
	}
}


void handlerCounterClockwise(int squareIndex,int* mat,int rows,int cols)
{
	int pointer=0;
	for(int j=squareIndex; j < rows-1; j++)
	{	
		int firstR = j;
		int firstC = squareIndex;
		int secR = squareIndex;
		int secC = rows-pointer-1;
		swap90CounterClockwise(mat, firstR, firstC, secR, secC, pointer);
		pointer++;
	}
	
}

void swap90CounterClockwise(int* mat, int firstR, int firstC, int secR, int secC,int pointer)
{

	int index = secC;
	int first = *(mat + (COL*firstR) + firstC);
	int second= *(mat + (COL*secR) + secC);
	int third = *(mat + (COL * index) + (index+pointer));
	int fourth = *(mat + (COL*(index+pointer)) + firstR);
	*(mat + (COL*(index+pointer)) + firstR) = first; // fourth = first
	*(mat + (COL * index) + (index+pointer)) = fourth; // third = fourth
	*(mat + (COL*secR) + secC) = third; // second = third
	*(mat + (COL*firstR) + firstC) = second;// first = second 



}


/////////////////////////////////////////////////Q2/////////////////////////////////////////////////////////////
void initMat(int* mat, int rows, int cols)
{
	int size= (rows * cols);
	for(int i=0; i < size; i++)
	{
		*mat = i+1;
		 mat++;
	}
	*(mat-1) = 0;	
}

void shuffleMat(int* mat, int rows, int cols)
{
	for(int i = 0; i < SHUFFLE_COUNT; i++)
	{
		int direction= getRand(1,4);//up = 1, 2 = right,3 = down,4 = left
		switch(direction)
		{
			case 1:
				if(isValidStep(mat, rows, 1) == 1)
					moveUp(mat, rows);
				break;
			case 2:
				if(isValidStep(mat, rows, 2) == 1)
					moveRight(mat, rows);
				break;
			case 3:
				if(isValidStep(mat, rows, 3) == 1)
					moveDown(mat, rows);
				break;
			case 4:
				if(isValidStep(mat, rows, 4) == 1)
					moveLeft(mat, rows);
				break;	
		}
	
	}

}

int isValidStep(int* mat,int rows, int step)
{
	int rowIndex, colIndex;
	findZeroIndex(mat, rows, &rowIndex, &colIndex);
	switch(step)
	{
		case 1:
			if(rowIndex == 0)
				return 0;
			return 1;	
		
		case 2:
			if(colIndex == COL-1)
				return 0;
			return 1;	
		
		case 3:
			if(rowIndex == rows -1)
				return 0;
			return 1;	
				
		case 4:
			if(colIndex == 0)
				return 0;
			return 1;	
						
	}
}

void findZeroIndex(int* mat,int rows, int* rowIndex, int* colIndex)
{
	for(int i=0; i < rows; i++)
	{
		for(int j = 0; j < COL; j++)
			{

				if(*(mat + (COL * i) + j) == 0)
				{
					*rowIndex = i;
					*colIndex = j;
				}
				
			}
	}
}

//Move methods
void moveUp(int* mat, int rows)
{
	int fromR, fromC;
	findZeroIndex(mat, rows, &fromR, &fromC);
	swap(mat, fromR, fromC, fromR-1, fromC);
}

void moveRight(int* mat, int rows)
{
	int fromR, fromC;
	findZeroIndex(mat, rows, &fromR, &fromC);
	swap(mat, fromR, fromC, fromR, fromC+1);

}

void moveDown(int* mat, int rows)
{
	int fromR, fromC;
	findZeroIndex(mat, rows, &fromR, &fromC);
	swap(mat, fromR, fromC, fromR+1, fromC);

}

void moveLeft(int* mat, int rows)
{
	int fromR, fromC;
	findZeroIndex(mat, rows, &fromR, &fromC);
	swap(mat, fromR, fromC, fromR, fromC-1);

}
//End move methods

void gameHandler(int* mat, int rows, int choice)
{
	if(choice == -1)
		return;
	int rowIndex, colIndex, flag = 0;
	for(int i=0; i < rows; i++)
	{
		for(int j = 0; j < COL; j++)
			{
				if(*(mat + (COL * i) + j) == choice)//Find choice Index
				{
					rowIndex = i;
					colIndex = j;
					flag = 1;
				}	
			}	
	}
	
	if(flag == 0)
		printf("\nInvalid number %d\n", choice);
		
	else
	{
		int move = checkValidMove(mat, rows, rowIndex, colIndex);
		switch(move)
		{
			case 1:
				moveUp(mat, rows);
				break;
			case 2:
				moveRight(mat, rows);
				break;
			case 3:
				moveDown(mat, rows);
				break;
			case 4:
				moveLeft(mat, rows);
				break;	
				
			case 0://invalid move
				printf("\nInvalid move\n");
		}	
	}
}

int checkValidMove(int* mat, int rows, int rowIndex, int colIndex)
{
	int zeroRIndex, zeroCIndex;
	findZeroIndex(mat, rows, &zeroRIndex, &zeroCIndex);
	if(rowIndex == zeroRIndex -1 && colIndex == zeroCIndex)
		return 1;//move up
		
	else if(colIndex == zeroCIndex +1 && rowIndex == zeroRIndex)
		return 2;//move right
		
	else if(rowIndex == zeroRIndex +1 && colIndex == zeroCIndex)
		return 3;//move down
		
	 else if(colIndex == zeroCIndex -1 && rowIndex == zeroRIndex)
		return 4;//move left
	
	return 0;			
	
}

int isWin(int* mat, int rows)
{
	int size = rows*COL;
	if(*mat == 0)
		return 0;	
	for(int i = 0 ; i < size-2; i++, mat++)
	{
		if(*mat > *(mat+1))
			return 0;
	}	
	return 1;		
}
