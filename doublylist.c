#include<stdio.h>
#include<stdlib.h>

struct NODE
{
	int DATA;
	struct NODE *PREV, *NEXT;
} *START, *LAST, *PTR, *T1, *T2;

int insertion();
int display(int, int);

int main()
{
	START = NULL;
	LAST = NULL;
	char ch = 'y';
	while(ch == 'y'||ch == 'Y')
	{
		system("CLS");
		printf(" Program to insert new nodes into a doubly linked list\n ");
		insertion();
		system("PAUSE");
		printf(" Do you wish to enter another node into the doubly linked list? (Y/N)\n >> ");
		scanf(" %c",&ch);
	}
	return 0;
}

int display(int mode, int n)
{
	int node_counter = 0;
	T1 = START;
	T2 = START;
	while(T2 != NULL)
	{
		if(mode == 0)
		{
			if(node_counter == 0)
				T2 = START->NEXT;
			else
			{
				T1 = T1->NEXT;
				T2 = T2->NEXT;
			}
			++node_counter;
		}
		else if(mode == 1)
		{
			if(node_counter == n)
				return 0;
			else if(node_counter == 0)
				T2 = START->NEXT;
			else
			{
				T1 = T1->NEXT;
				T2 = T2->NEXT;
			}
			++node_counter;
		}
		else if(mode == 2)
		{
			printf("\n %d. ( %X )-> ||\t %X \t||\t %d \t||\t %X \t||",node_counter+1, T2, T2->PREV, T2->DATA, T2->NEXT);
			T2 = T2->NEXT;
			++node_counter;
		}
	}
	return node_counter;
}
	
int insertion()
{
	int number_of_nodes = 0, N, buffer;
	PTR = (struct NODE*)malloc(sizeof(struct NODE));
	if(PTR == NULL)
	{
		printf("\n\a OVERFLOW ERROR!!");
		return 0;
	}
	PTR->PREV = NULL;
	PTR->NEXT = NULL;
	if(START != NULL)
		number_of_nodes = display(0, 0);
	errorrun:
	printf("\n Enter the node number after which you wish to insert a new node (0 - %d): ", number_of_nodes);
	scanf("%d", &N);
	if((N > number_of_nodes)||(N < 0))
	{
		printf("\n\a WRONG CHOICE!!\n ");
		system("PAUSE");
		system("CLS");
		goto errorrun;
	}
	else
	{
		printf("\n Enter the integer you wish to store in new node: ");
		scanf("%d",&buffer);
		display(1, N);
		if(N == 0)
		{
			if(number_of_nodes == 0)
			{
				START = PTR;
				LAST = PTR;
			}
			else
			{
				START->PREV = PTR;
				PTR->NEXT = START;
				START = PTR;
			}
		}
		else if(N == number_of_nodes)
		{
			LAST->NEXT = PTR;
			PTR->PREV = LAST;
			LAST = PTR;
		}
		else
		{
			T1->NEXT = PTR;
			PTR->PREV = T1;
			T2->PREV = PTR;
			PTR->NEXT = T2;
		}
		PTR->DATA = buffer;
		printf("\n\t\t\t CURRENT STATE OF DOUBLY LINKED LIST");
		printf("\n------------------------------------------------------------------------------------");
		printf("\n START = %X \n LAST = %X ", START, LAST);
		printf("\n------------------------------------------------------------------------------------");
		if(START->NEXT == NULL)
			printf("\n %d. ( %X )-> ||\t %X \t||\t %d \t||\t %X \t||", N+1, START, START->PREV, START->DATA, START->NEXT);
		else
			display(2, 0);
		printf("\n------------------------------------------------------------------------------------\n ");
	}
	return 0;
}
