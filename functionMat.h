#ifndef F_M_H
#define F_M_H

#include <stdlib.h>
#include <time.h>

#define COL 4
#define ROW 4
#define SHUFFLE_COUNT 10

int getRand(int min, int max);
void printMatrix(int* mat , int rows, int cols);
void swap(int* mat, int row1, int col1, int row2, int col2);

//////////////////////////////////////Q1/////////////////////////////////////////////////////////////////////////
void RotateClockwise(int *mat , int rows, int cols);
void RotateCounterClockwise(int *mat , int rows, int cols);
void flipHorizontally(int *mat , int rows, int cols);
void flipVertically(int *mat , int rows, int cols);
void swap90Clockwise(int* mat, int firstR, int firstC, int secR, int secC,int pointer);
void handlerClockwise(int squareIndex,int* mat,int rows,int cols);
void handlerCounterClockwise(int squareIndex,int* mat,int rows,int cols);
void swap90CounterClockwise(int* mat, int firstR, int firstC, int secR, int secC,int pointer);

/////////////////////////////////////Q2//////////////////////////////////////////////////////////////////////////
void initMat(int* mat, int rows, int cols);
void shuffleMat(int* mat, int rows, int cols);
void gameHandler(int * mat, int rows, int choice);
int isValidStep(int* mat,int rows, int step);
void findZeroIndex(int* mat,int rows, int* rowIndex, int* colIndex);
void moveUp(int* mat, int rows);
void moveRight(int* mat, int rows);
void moveDown(int* mat, int rows);
void moveLeft(int* mat, int rows);
int checkValidMove(int* mat, int rows, int rowIndex, int colIndex);
int isWin(int* mat, int rows);


#endif 
