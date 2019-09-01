#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

struct NODE
{
	int DATA;
	struct NODE *LINK;
};
struct NODE *start, *ptr, *T1, *T2;

int creation();
int display_list();
int deletebeg();
int deletemid();
int deleteend();

int main()
{
	system("CLS");
	int choice;
	printf("\n \t\tInitializing linked list\n");
	start = (struct NODE*)malloc(sizeof(struct NODE));
	if(start == NULL)
	{	
		printf("\n \a\t\tINITIALIZATION FAILED\n");
		return 0;
	}
	else
		printf("\n \t\tINITIALIZATION SUCCESSFUL!!\n");
	ptr = start;
	creation();
	display_list();
	system("PAUSE");
	redo:
	printf("\n\a Preparing the system for deletion...");
	system("CLS");
	printf("\n\t\t\tMENU FOR DELETION\n----------------------------------------");
	printf("\n\t1. Delete from beginning\n\t2. Delete from middle\n\t3. Delete from end\n\t4. Exit the program\n Enter your choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: display_list();
					deletebeg();
					break;
		case 2: display_list();
					deletemid();
					break;
		case 3: display_list();
					deleteend();
					break;
		case 4: return 0;
					 break;
		default: printf("\a\a\t\t\tWRONG CHOICE!!!\n\t\t\tTry again!!");
						goto redo;
	}
	display_list();
	system("PAUSE");
	goto redo;
	return 0;
}

int creation()
{
	static int count;
	int buff;
	char ch;
	if(count == 0)
	{
		printf("\n Enter data into node no. %d of the linked list: ",count + 1);
		scanf("%d",&buff);
		ptr->DATA = buff;
		ptr->LINK = NULL;
		++count;
	}
	
	else if(count > 0)
	{
		T1 = ptr;
		ptr = (struct NODE*)malloc(sizeof(struct NODE));
		if(ptr == NULL)
		{
			printf(" No space available for node no. %d!!", count + 1);
			return 0;
		}
		else
		{
			printf("\n Enter data into node no. %d of the linked list: ", count + 1);
			scanf("%d",&buff);
			ptr->DATA = buff;
			ptr->LINK = NULL;
			T1->LINK = ptr;
			++count;
		}
	}
	printf(" Do you wish to enter another element into the linked list?(Y/N) ");
	scanf(" %c", &ch);
	if(ch == 'y'||ch == 'Y')
	{
		creation();
	}
	else 
		return 0;
}


int display_list()
{
	int n = 1;
	printf("\n\n -----------------LINKED LIST SO FAR------------------\n");
	printf(" START -> %X", start);
	printf("\n -----------------------------------------------------");
	T1 = start;
	ptr = start;
	printf("\n S.NO.\t\tADDRESS\t\tDATA\t\tLINK");
	printf("\n -----------------------------------------------------");
	while(T1 != NULL)
	{
		
		printf("\n %2d.\t\t%2X\t\t%2d\t\t%2X", n, ptr, ptr->DATA, ptr->LINK);
		T1 = ptr->LINK;
		ptr = T1;
		++n;
	}
	printf("\n -----------------------------------------------------\n");
	return 0;
}


int deletebeg()
{
	if(start == NULL)
	{
		printf("\n\nLINKED LIST IS EMPTY!!!");
		return 0;
	}
	T1 = start;
	ptr = start->LINK;
	if(ptr == NULL)
	{	
		printf("\n Node containing data %d at address %X is being deleted...",T1->DATA, T1);
		free(T1);
		start = NULL;
	}
	else 
	{
		start = ptr;
	
	printf("\n Node containing data %d at address %X is being deleted...",T1->DATA, T1);
	free(T1);
	}
	return 0;
}

int deleteend()
{
	int iteration = 0;
	ptr = start;
	if(start == NULL)
	{
		printf("\n\a LIST IS EMPTY!!");
		return 0;
	}
	while((ptr->LINK) != NULL)
	{
		if(iteration == 0)
		{
			T1 = ptr;
			++iteration;
		}
		
		else if(iteration >= 1)
		{
			T1 = ptr;
			ptr = ptr->LINK;
			++iteration;
		}
	}
	if(iteration >= 0)
	{
		if(iteration == 0)
		{
			printf("\n Node containing data %d at address %X is being deleted...",ptr->DATA, ptr);
			free(ptr);
			start = NULL;
		}
		else
		{
			printf("\n Node containing data %d at address %X is being deleted...",ptr->DATA, ptr);
			T1->LINK = NULL;
			free(ptr);
		}
	}
	return 0;
}

int deletemid()
{
	int n, counter = 0, limit = 0;
	T1 = start;
	ptr = start;
	while(T1 != NULL)
	{
		T1 = ptr->LINK;
		ptr = T1;
		++limit;
	}
	printf("\n Enter the node no. which you wish to delete: ");
	scanf("%d", &n);
	if(n <= 0|| n > limit)
	{
		printf("\a\t\t\t WRONG CHOICE!!\n");
		return 0;
	}
	ptr = start;
	T1 = start;
	if(start == NULL)
	{
		printf("\n\a LIST IS EMPTY!!!");
		return 0;
	}
	while(counter != n)
	{
		if(counter == 0)
		{
			T2 = ptr->LINK;
			++counter;
		}
		else if(counter >= 1)
		{
			T1 = ptr;
			ptr = ptr->LINK;
			T2 = T2->LINK;
			++counter;
		}
		
	}
	if(counter == 1)
	{
		printf("\n Node containing data %d at address %X is being deleted...",ptr->DATA, ptr);
		start = ptr->LINK;
		free(ptr);
	}	
	else if(counter > 1)
	{	
			printf("\n Node containing data %d at address %X is being deleted...",ptr->DATA, ptr);
			T1->LINK = T2;
			free(ptr);
	}
	return 0;
}
