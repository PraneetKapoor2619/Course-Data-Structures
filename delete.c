#include<stdio.h>
#include<stdlib.h>

int main()
{
	system("CLS");
	int array[100];
	for(int i = 0; i<100; i++)
	{	array[i] = '\0';
	}
	int length = 0;
	char ch = 'y';
	while(ch == 'y'||ch == 'Y')
	{	printf(" Enter element no. %d : ", length + 1);
		scanf("%d", &array[length]);
		++length;
		printf(" There are now %d element(s) in the array. Do you wish to enter another element? (y/n)",length);
		scanf(" %c",&ch);
	}
	
	for(int i = 0; i < length; i++)
	{	printf("| %d |", array[i]);
	}
	
	ch = 'y';
	while(ch == 'y'|| ch == 'Y')
	{	int check, k, DATA;
		check = 0;
		while(check == 0)
		{	printf("\n\n Enter the element you wish to delete: ");
			scanf("%d", &DATA);
			for(int i = 0; i < length; i++)
			{	if(array[i] == DATA)
				{	k = i;
					++check;
					break;
				}
			}
			if(check == 1)
				printf(" Data element %d found at location %d", DATA, k+1);
			else if(check == 0)
				printf(" Data element %d not found!!", DATA);
		}
		
		printf("\n Starting deletion of the element...\n");
		for(int j = k; j < length; j++)
		{	array[j] = array[j + 1];
			for(int i = 0; i < length; i++)
			{	printf("| %d |", array[i]);
			}
			printf("\n");
		}
		--length;
		printf("\n Element deleted!!\n New array is shown below: \n");
		for(int i = 0; i < length; i++)
		{	printf("| %d |", array[i]);
		}
		printf("\n\n Do you wish to delete another element? (y/n)"); 
		scanf(" %c", &ch);
	}
	return 0;
}