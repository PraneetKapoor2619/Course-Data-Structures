#include<stdio.h>
#include<stdlib.h>

int array[100];

int binary_search(int, int);

int main()
{
	system("CLS");
	int length, DATA;
	char ch;
	length = 0;
	ch = 'y';
	for(int i = 0; i < 100; i++)
	{	array[i] = '\0';
	}
	while(ch == 'y'|| ch =='Y')
	{	printf("\n Enter the element which you wish to enter into the array: ");
		scanf("%d", &array[length]);
		++length;
		printf(" There are now %d elements in the array.\n Do you wish to enter more elements?(y/n) ", length);
		scanf(" %c",&ch);
	}
	printf("\n\n The array you entered is as shown below: \n\n ");
	for(int i = 0; i < length; i++)
	{	printf("| %d |",array[i]);
	}
	
	ch = 'y';
	while(ch == 'y'||ch == 'Y')
	{	printf("\n\n Enter the data element you wish to search for in the array: ");
		scanf("%d",&DATA);
		binary_search(DATA, length);
		printf(" Do you wish to search for another element?(y/n) ");
		scanf(" %c",&ch);
	}
	system("PAUSE");
	return 0;
}

int binary_search(int DATA, int length)
{	static int limit, offset, iteration, previous_offset, previous_limit;
	int midpoint;
	if(iteration == 0)
	{	limit = length;
		offset = 1;
	}
	midpoint = (offset + limit)/2;
	if(array[midpoint - 1] == DATA)
	{	printf("\n Data element %d found at position %d\n", DATA, midpoint);
		limit = length;
		offset = 1;
		iteration = 0;
		return 0;
	}
	
	else if(array[midpoint - 1] > DATA)
		limit = midpoint - 1;
	else if(array[midpoint - 1] < DATA)
		offset = midpoint + 1;
	if((previous_limit == limit) && (previous_offset == offset))
	{ printf("\n Element %d not found!!\n", DATA);
		limit = length;
		offset = 1;
		iteration = 0;
		return -1;
	}
	++iteration;
	previous_limit = limit;
	previous_offset = offset;
	binary_search(DATA, length);
}