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
	int j, k, DATA;
	while(ch == 'y'||ch == 'Y')
	{	j = (length - 1);
		printf("\n Enter the element which you wish to enter: ");
		scanf("%d", &DATA);
		printf(" Enter the location (1 to %d) at which this element is to be inserted: ",length);
		scanf("%d", &k);
		while(k > length)
		{	printf("\t\t\t\tINCORRECT ENTRY!!\n Enter location again: ");
			scanf("%d", &k);
		}
		for(j; j >= (k-1) ; --j)
		{	array[j + 1] = array[j];
			for(int i = 0; i<length + 1; i++)
			{	printf("| %d |",array[i]);
			}
			printf("\n");
		}
		array [k - 1] = DATA;
		printf("\n");
		++length;
		for(int i = 0; i<length; i++)
		{	printf("| %d |",array[i]);
		}
		printf("\n\n Modified array is shown below: \n");
		for(int l = 0; l < length; l++)
		{	printf("| %d |",array[l]);
		}
		
		printf("\n\n Do you wish to insert another element?(y/n) ");
		scanf(" %c",&ch);
	}
	return 0;
}