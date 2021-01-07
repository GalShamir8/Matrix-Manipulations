#include <stdio.h>
#include "picMan.h"
#include "functionMat.h"

const int MIN = 0;
const int MAX = 99;

void pictureManipulation()
{
	int num;
	srand(time(NULL));
	int mat[ROW][COL];
	//InitMat
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			mat[i][j] = getRand(MIN, MAX);
		}
	}
	printMatrix((int*)mat, ROW, COL);
	int flag = 0;
	int choice;
	while(flag == 0)
	{
		printf("\nEnter your choice from the following menu:");
		printf("\n1 - 90 degree clockwise");
		printf("\n2 - 90 degree counter clockwise");
		printf("\n3 - Flip Horizontal");
		printf("\n4 - Flip Vertical");
		printf("\n-1 - Exit\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			RotateClockwise((int*)mat, ROW, COL);
			printf("\n-------- picture after manipulation ---------\n");
			printMatrix((int*)mat, ROW, COL);
			break;
		case 2:
			RotateCounterClockwise((int*)mat, ROW, COL);
			printf("\n-------- picture after manipulation ---------\n");
			printMatrix((int*)mat, ROW, COL);
			break;
		case 3:
			flipHorizontally((int*)mat, ROW, COL);
			printf("\n-------- picture after manipulation ---------\n");
			printMatrix((int*)mat, ROW, COL);
			break;
		case 4:
			flipVertically((int*)mat, ROW, COL);
			printf("\n-------- picture after manipulation ---------\n");
			printMatrix((int*)mat, ROW, COL);
			break;
		case -1:
			flag = -1;
			getchar();//clean the buffer
			break;

		}
	}
}
	

