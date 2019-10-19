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
	int QARRAY[100];
	int FRONT = -1, REAR = -1;
	int choice;
	int DATA;
	arerun:
	system("CLS");
	printf("\t\t\t PROGRAM TO WORK WITH QUEUE IMPLEMENTED USING ARRAYS\n");
	printf(" ----------------------------------------------------------------------------------------------");
	printf("\n Press 1 to INSERT a data element into the queue.\n Press 2 to DELETE a data element from the queue\n Press 3 to return to main function\n >> ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:	system("CLS");
				if((FRONT == 0) && (REAR == 99))
				{
					printf("\n\a QUEUE OVERFLOW!!\n");
					system("PAUSE");
					goto arerun;
				}
				else if((FRONT == -1) && (REAR == -1))
				{
					FRONT = REAR = 0;
				}
				else if(FRONT == (REAR + 1))
				{
					FRONT = 0;
					REAR = 0;
				}
				else
					++REAR;
				printf(" Enter data to be inserted into the queue: ");
				scanf("%d", &DATA);
				QARRAY[REAR] = DATA;
				printf(" DATA INSERTED FROM REAR END OF THE QUEUE. \n FRONT -> %d = %d\n REAR -> %d = %d\n ",FRONT, QARRAY[FRONT], REAR, QARRAY[REAR]);
				break;
				
		case 2:	system("CLS");
				if((FRONT == 100) || (FRONT == (REAR + 1)))
				{
					printf(" QUEUE UNDERFLOW!!\n ");
					system("PAUSE");
					goto arerun;
				}
				DATA = QARRAY[FRONT];
				++FRONT;
				printf(" DATA %d HAS BEEN DELETED FROM FRONT END OF THE QUEUE. \n FRONT -> %d = %d\n REAR -> %d = %d\n ", DATA, FRONT, QARRAY[FRONT], REAR, QARRAY[REAR]);
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