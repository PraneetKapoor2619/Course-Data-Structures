#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

struct NODE
{
	int DATA;
	struct NODE *LINK;
};
struct NODE *start, *ptr, *temp, *T1, *T2;

int creation();
int display_list();
int reversal(int);

int main()
{
	system("CLS");
	int choice, n;
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
	n = display_list();
	system("PAUSE");
	printf("\n\a Preparing the system for reversal of data stored in nodes...");
	system("CLS");
	reversal(n);
	display_list();
	system("PAUSE");
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
	if(start == NULL)
		return 0;
	else
		return n;
}

int reversal(int n)
{
	int iterations, front = 1, back = n, counter = 1, buff;
	if(n == 0)
	{	printf("\t\t\t LIST IS EMPTY!!!");
		return 0;
	}
	else if((n%2)==0)
		iterations = n/2;
	else if((n%2) != 0)
		iterations = (n+1)/2;
	printf("\n Iterations = %d", iterations);
	for(int i = 1; i <= iterations; i++)
	{
		ptr = start;
		temp = ptr;
		while(temp != NULL)
		{
			if(counter == front)
			{	T1 = ptr;
			}
			else if(counter == (back-1))
			{	T2 = ptr;
			}
			temp = ptr->LINK;
			ptr = temp;
			++counter;
		}
		buff = T1->DATA;
		T1->DATA = T2->DATA;
		T2->DATA = buff;
		counter = 1;
		++front;
		--back;
	}
	return 0;
}
