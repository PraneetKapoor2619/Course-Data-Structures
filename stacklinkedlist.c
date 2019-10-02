#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

struct STACK
{
	int DATA;
	struct STACK *NEXT;
};
struct STACK *TOP, *PTR;

int linked_list();

int main()
{
	linked_list();
	return 0;
}

int linked_list()
{
	int choice;
	int DATA;
	static int runs = 1;
	lrerun:
	system("CLS");
	printf("\t\t\t PROGRAM TO WORK WITH STACKS IMPLEMENTED USING LINKED LISTS\n");
	printf(" ----------------------------------------------------------------------------------------------");
	if(runs == 1)
		TOP = NULL;
	printf("\n Press 1 to PUSH a data element into the stack.\n Press 2 to POP a data element from the stack\n Press 3 to return to main function\n >> ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:	PTR = (struct STACK*)malloc(sizeof(struct STACK));
				if(PTR == NULL)
				{
					printf("\n\t\t\t\a OVERFLOW ERROR!!\n");
					system("PAUSE");
				}
				else
				{
					printf("\n Enter data to be pushed: ");
					scanf("%d",&DATA);
					PTR->DATA = DATA;
					PTR->NEXT = TOP;
					TOP = PTR;
					printf("\n PUSHED %d\n", TOP->DATA);
					++runs;
				}
				break;
		case 2:	PTR = TOP;
				if(TOP == NULL)
				{
					printf("\n\a\t\t\t UNDERFLOW!!!\n");
				}
				else
				{
					if((PTR->NEXT) == NULL)
					{
						printf("\n POP Data %d\n",PTR->DATA);
						free(PTR);
						TOP = NULL;
						system("PAUSE");
						goto lrerun;
						
					}
					else
					{
						printf("\n POP Data %d\n",PTR->DATA);
						TOP = TOP->NEXT;
						free(PTR);
					}
					printf("\n  TOP -> DATA = %d\n", TOP->DATA);
				}	
				break;
		case 3: return 0;
				break;
		default: printf("\n\t\t\t\a WRONG CHOICE!!!\n");
				 system("PAUSE");	
				 goto lrerun;
				 break;
	}
	system("PAUSE");
	goto lrerun;
	return 0;
}

