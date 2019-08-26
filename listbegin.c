#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

struct NODE
{
	int DATA;
	struct NODE *LINK;
};
struct NODE *start, *ptr, *temp;
int creation();
int display_list();
int insertion();

int main()
{
	system("CLS");
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
	char ch;
	printf("\n Do you wish to insert an element in the beginning of list?(Y/N) ");
	scanf(" %c",&ch);
	while(ch == 'y'||ch == 'Y')
	{
		insertion();
		display_list();
		printf("\n Do you wish to enter another element into the list?(Y/N) ");
		scanf(" %c",&ch);
	}
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
		temp = ptr;
		ptr = (struct NODE*)malloc(sizeof(struct NODE));
		if(ptr == NULL)
		{
			printf(" No space available for node no. %d!!", count + 1);
			exit(0);
		}
		else
		{
			printf("\n Enter data into node no. %d of the linked list: ", count + 1);
			scanf("%d",&buff);
			ptr->DATA = buff;
			ptr->LINK = NULL;
			temp->LINK = ptr;
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

int insertion()
{
	int buff;
	ptr = (struct NODE*)malloc(sizeof(struct NODE));
	if(ptr == NULL)
	{
		printf("\n \a\t\tNO SPACE AVAILABLE IN MEMORY!!!");
		exit(0);
	}
	else
	{
		printf(" Enter data: ");
		scanf("%d", &buff);
		ptr->DATA = buff;
		ptr->LINK = start;
		start = ptr;
	}
	return 0;
}

int display_list()
{
	int n = 1;
	printf("\n\n -----------------LINKED LIST SO FAR------------------\n");
	printf(" START -> %X", start);
	printf("\n -----------------------------------------------------");
	temp = start;
	ptr = start;
	printf("\n S.NO.\t\tADDRESS\t\tDATA\t\tLINK");
	printf("\n -----------------------------------------------------");
	while(temp != NULL)
	{
		
		printf("\n %2d.\t\t%2X\t\t%2d\t\t%2X", n, ptr, ptr->DATA, ptr->LINK);
		temp = ptr->LINK;
		ptr = temp;
		++n;
	}
	return 0;
}
