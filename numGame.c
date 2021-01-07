#include <stdio.h>
#include "numGame.h"
#include "functionMat.h"



void numberGame()
{
	int rows = 4, flag = 0;//rows as an input?
	int mat[rows][COL];
	initMat((int*)mat, rows, COL);
	
	printf("\n---------Game board before shuffle---------\n");
	printMatrix((int*)mat , rows, COL);
	
	shuffleMat((int*)mat, rows, COL);
	printf("\n---------Game board after shuffle---------\n");
	printMatrix((int*)mat , rows,  COL);
	
	printf("\nWelcome to number game for exit please enter -1\n");
	flag = isWin((int*)mat, rows);//flag = 1 (WIN!)
	while(flag == 0)
	{
		int choice;
		printf("\nEnter your step: \n");
		scanf("%d" ,&choice);
		if(choice == -1)
			flag =-1;//Exit
		else	
		{
			gameHandler((int*)mat, rows, choice);
			
			printf("\n---------Game board---------\n");
                       printMatrix((int*)mat , rows,  COL);
                       
                       flag = isWin((int*)mat, rows);
		}	
	}
	if(flag == 1)
		printf("\nGame ended YOU WIN!!!\n");	
	getchar();//clean the buffer				
}

