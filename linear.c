#include<stdio.h>
#include<stdlib.h>

int main()
{
	system("CLS");
	int array[100], length, DATA, check, pos;
	
	length = 0;
	check = 0;
	char ch = 'y';
	
	for(int i = 0; i < 100; i++)
	{	array[i] = '\0';
	}
	
	while(ch == 'y'||ch == 'Y')
	{	printf("\n Enter the element you wish to enter: ");
		scanf("%d", &array[length]);
		++length;
		printf(" Do you wish to enter another element?(Y/N) --> ");
		scanf(" %c", &ch);
	}
	
	printf("\n The array you entered is shown below:\n ");	
	for(int i = 0; i < length; i++)
	{	printf("| %d |", array[i]);
	}
	
	ch = 'y';
	while(ch == 'y' || ch == 'Y')
	{	printf("\n Enter the element you wish to search for: ");
		scanf("%d", &DATA);
		for(int i = 0; i < length; i++)
		{	if(array[i] == DATA)
			{	pos = i + 1;
				++check;
				break;
			}
		}
		if(check == 1)
		{	printf("\n The data element %d was found at position %d.", DATA, pos);
		}
		else if(check == 0)
		{ printf("\n The data element %d is not present in the array.", DATA);
		}
		check = 0;
		printf("\n Search for another element?(Y/N)--> ");
		scanf(" %c",&ch);
	}
	return 0;
}