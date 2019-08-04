#include<stdio.h>
#include<stdlib.h>

int swap_by_value(int, int);
int swap_by_reference(int *, int *);

int main()
{	
	system("CLS");
	char run_again = 'y';
	int num1, num2, choice;
	while(run_again == 'y' || run_again == 'Y')
	{	printf("_______________________________________________________________________________________________________________________________________\n");
		printf(" Enter number 1: ");
		scanf("%d", &num1);
		printf(" Enter number 2: ");
		scanf("%d", &num2);
		error_run:
		printf(" Press 1 to swap num1 and num2 by value\n Press 2 to swap num1 and num2 by reference\n --> ");
		scanf("%d", &choice);
		switch(choice)
		{	case 1: swap_by_value(num1, num2);
						break;
			case 2: swap_by_reference(&num1, &num2);
						break;
			default: goto error_run;
		}
		printf("\n\n Swapping done!!\n In main function:\n num1 = %d and num2 = %d", num1, num2);
		printf("\n\n Do you wish to run the loop again?(y/n)\n --> ");
		scanf(" %c", &run_again);
	}
	return 0;
}

int swap_by_value(int a, int b)
{	
	int temp = a;
	a = b;
	b = temp;
	printf("\n Copies of num1 and num2 after swapping:\n num1 = %d and num2 = %d",a,b);
	return 0;
}

int swap_by_reference(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("\n References of num1 and num2 after swapping:\n num1 = %d and num2 = %d",*a,*b);
	return 0;
}