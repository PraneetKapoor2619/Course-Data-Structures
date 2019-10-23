#include<stdio.h>
#include<stdlib.h>

struct QUEUE
{
	int DATA;
	struct QUEUE *NEXT;
};
struct QUEUE *FRONT = NULL, *REAR = NULL, *NODE;

int insertion();
int deletion();
int display_queue();

int main()
{
	int choice;
	rerun:
	system("CLS");
	printf("\n MENU FOR OPERATING ON QUEUE IMPLEMENTED USING LINKED LISTS");
	printf("\n_______________________________________________________________");
	printf("\n 1. Insertion \n 2. Deletion \n 3. Display current state of the queue\n 4. Exit \n Enter you choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: insertion();
				break;
		case 2: deletion();
				break;
		case 3: display_queue();
				break;
		case 4: exit(0);
				break;
		default: printf("\n WRONG CHOICE!!");
				break;
	}
	goto rerun;
	return 0;
}

int insertion()
{
	system("CLS");
	int buff;
	NODE = (struct QUEUE*)malloc(sizeof(struct QUEUE));
	if(NODE == NULL)
	{
		printf("\a\nQUEUE OVERFLOW!!!\n ");
		system("PAUSE");
		return 0;
	}
	else
	{
		printf("\n Enter the data you wish to insert into the QUEUE at %X: ",NODE);
		scanf("%d", &buff);
		if(REAR == NULL)
		{
			FRONT = REAR = NODE;
			NODE->NEXT = NULL;
		}
		else
		{
			REAR->NEXT = NODE;
			REAR = NODE;
			NODE->NEXT = NULL;
		}
		NODE->DATA = buff;
		printf("\n Data inserted from rear end of Queue!");
		display_queue();
	}
	return 0;
}

int deletion()
{
	system("CLS");
	int buff;
	if(FRONT == NULL)
	{
		printf("\n\a QUEUE UNDERFLOW!!!\n ");
		system("PAUSE");
		return 0;
	}
	else
	{
		buff = FRONT->DATA;
		if((FRONT->NEXT) != NULL)
		{
			NODE = FRONT;
			FRONT = FRONT->NEXT;
			free(NODE);
		}
		else
		{
			free(FRONT);
			FRONT = NULL;
			REAR = NULL;
			printf("\n Queue Empty!!\n");
			system("PAUSE");
			return 0;
		}
		printf("\n %d has been deleted from the front end of the queue.",buff);
		display_queue();
	}
	return 0;
}
		
int display_queue()
{
	printf("\n CURRENT STATE OF QUEUE");
	if(FRONT != NULL)
	{
		printf("\n FRONT -> %X = | %d | %X |", FRONT, FRONT->DATA, FRONT->NEXT);
		printf("\n REAR -> %X = | %d | %X |\n ", REAR, REAR->DATA, REAR->NEXT);
	}
	else
		printf("\n FRONT -> 0 = | 0 | 0 |\n REAR -> 0 = | 0 | 0 |\n");
	system("PAUSE");
	return 0;
}
		