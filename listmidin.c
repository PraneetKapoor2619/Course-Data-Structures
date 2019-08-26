#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

struct NODE
{
	int DATA;
	struct NODE *LINK;
};
struct NODE *start, *ptr, *temp1, *temp2;
int creation();
int display_list();
int insertion(int);

int main()
{
	system("CLS");
	int max_size;
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
	max_size = display_list();
	char ch;
	printf("\n Do you wish to insert an element in the linked list?(Y/N) ");
	scanf(" %c",&ch);
	while(ch == 'y'||ch == 'Y')
	{
		insertion(max_size);
		max_size = display_list();
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
		temp1 = ptr;
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
			temp1->LINK = ptr;
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

int insertion(int max_size)
{
	int n = 1, num, buff;
	ptr = (struct NODE*)malloc(sizeof(struct NODE));
	if(ptr == NULL)
	{
		printf("\n \a\t\tNO SPACE AVAILABLE IN MEMORY!!!");
		exit(0);
	}
	else
	{	
		printf("\n Enter node no. after which you wish to insert a new node(0 for START): ");
		scanf("%d",&num);
		temp1 = start;
		if(num == 0)
		{
			printf(" Enter data: ");
			scanf("%d", &buff);
			ptr->DATA = buff;
			ptr->LINK = start;
			start = ptr;
		}
		else if((num >= 1) && (num <= max_size) )
		{
			while(n <= num)
			{
				if(n == 1)
				{
					temp2 = temp1->LINK;
				}
				else
				{
					temp1 = temp2;
					temp2 = temp1->LINK;
				}
				++n;
			}
			printf(" Enter data: ");
			scanf("%d", &buff);
			if(temp2 == NULL)
			{
				ptr->DATA = buff;
				ptr->LINK = NULL;
				temp1->LINK = ptr;
			}
			else
			{
				ptr->DATA = buff;
				ptr->LINK = temp2;
				temp1->LINK = ptr;
			}
		}
		else if(num > max_size || num < 0)
		{
			printf("\n \a\t\tINCORRECT ENTRY!! POSITION MUST BE A POSITIVE INTEGER\n");
			return 0;
		}
	}
	return 0;
}

int display_list()
{
	int n = 1;
	printf("\n\n -----------------LINKED LIST SO FAR------------------\n");
	printf(" START -> %X", start);
	printf("\n -----------------------------------------------------");
	temp1 = start;
	ptr = start;
	printf("\n S.NO.\t\tADDRESS\t\tDATA\t\tLINK");
	printf("\n -----------------------------------------------------");
	while(temp1 != NULL)
	{
		
		printf("\n %2d.\t\t%2X\t\t%2d\t\t%2X", n, ptr, ptr->DATA, ptr->LINK);
		temp1 = ptr->LINK;
		ptr = temp1;
		++n;
	}
	return n;
}
