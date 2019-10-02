#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int array();

int main()
{
	array();
	return 0;
}

int array()
{
	static int SARRAY[100];
	static int TOP = -1;
	int choice;
	int DATA;
	arerun:
	system("CLS");
	printf("\t\t\t PROGRAM TO WORK WITH STACKS IMPLEMENTED USING ARRAYS\n");
	printf(" ----------------------------------------------------------------------------------------------");
	printf("\n Press 1 to PUSH a data element into the stack.\n Press 2 to POP a data element from the stack\n Press 3 to return to main function\n >> ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:	system("CLS");
				++TOP;
				if(TOP < 100)
				{	printf(" Enter data to be pushed: ");
					scanf("%d",&DATA);
					SARRAY[TOP] = DATA;
					printf("\n PUSHED -> %d\n",SARRAY[TOP]);
				}
				else
				{
					printf("\a OOPS!! Stack Overflow!!\n");
				}
				break;
		case 2:	system("CLS");
				if(TOP < 0)
				{
					printf("\a UNDERFLOW ERROR!!!\n");
				}
				else
				{
					printf("POP -> %d\n",SARRAY[TOP]);
					SARRAY[TOP] = 0;
					--TOP;
				}
				break;
		case 3:	return 0;
				break;
		default: printf("\n\t\t\t\a WRONG CHOICE!!!\n");
				 system("PAUSE");
				 goto arerun;
				 break;
	}
	system("PAUSE");
	goto arerun;
}