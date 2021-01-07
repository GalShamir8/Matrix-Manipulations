#include <stdio.h>
#include <ctype.h>
#include "picMan.h"
#include "numGame.h"

int main()
{
	char choice;
	int flag = 0;
	while (flag == 0)
	{
		printf("\nEnter your choice from the following menu:");
		printf("\nP/p - Picture Manipulation");
		printf("\nN/n - Number Game");
		printf("\nE/e - Quit\n");
		scanf("%c", &choice);
		choice = toupper(choice);
		switch (choice)
		{
		case 'P':
			pictureManipulation();
			break;
		case 'N':
			numberGame();
			break;
		case 'E':
			printf("\nBye Bye\n");
			flag = -1;
			break;
		}
	}
}

