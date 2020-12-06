#include "myBank.h"
#include "myBank.c"
#include <stdio.h>

int main()
{
	char in='O';
	int userIn;
	float amountIn;
	init();
	
	
	int exit = 0;
	while(exit!=1)
	{
		
		
		printf("Please choose a transaction type: \n O-Open Account \n B-Balance Inquiry \n D-Deposit \n W-Withdrawal \n C-Close Account \n I-Interest \n P-Print \n E-Exit \n");
		
		scanf(" %c", &in);
		//printf("_____%c_____",in);
		switch(in){
		case 'O':
			printf("Please enter the amount for deposit: ");

			if(scanf(" %f",&amountIn)==1)
			{
				if(amountIn>0)
				{
				open(amountIn);
				}
				else
				{
					printf("Invalid Amount \n");
				}
			}
			else
			{
				printf("Failed to read the amount\n");
			}
			break;
		case 'B':
			printf("Please enter account number:");
			scanf(" %d",&userIn);
			if(userIn>900&&userIn<951&&userIn!=0)
			{
				if(isOpen(userIn)==1)
				{
				Status(userIn);
				}
				else
				{
					printf("This account is closed \n");
				}
				
			}
			else
			{
			printf("Failed to read the account number \n");
			}
			break;
		case 'D':
		
			printf("Please enter account number: ");
			scanf(" %d",&userIn);
			if(userIn>900&&userIn<951)
			{
				if(isOpen(userIn)==1)
				{
				printf("Please enter the amount to deposit:");
				scanf("%f",&amountIn);
				deposit(userIn,amountIn);
				}
				else
				printf("This account is closed \n");
			}
			else if(userIn==0)
			{
				printf("Failed to read the account number \n");
			}
			else
			{
				printf("Invalid account number");
			}
			break;
		case 'W':
		
			printf("Please enter account number: ");
			scanf(" %d",&userIn);
			if(userIn>900&&userIn<951)
			{
				if(isOpen(userIn)==1)
				{
				printf("Please enter the amount to withdraw:");
				scanf(" %f",&amountIn);
				withdraw(userIn,amountIn);
				}
				else
				printf("This account is closed\n");
			}
			else if(userIn==0)
			{
				printf("Failed to read the account number \n");
			}
			else
			{
				printf("Invalid account number");
			}
			break;
		case 'C':
		
			printf("Please enter account number:");
			scanf(" %ls",&userIn);
			if(userIn!=0)
			{
				if(isOpen(userIn)==1)
				close(userIn);
				else
				{
					printf("This account is closed\n");
				}
			}
			else
			printf("Failed to read the account number");
			break;
		case 'I':
		
			printf("Please enter interest rate: ");
			double I;
			scanf(" %lf",&I);
			if(I!=0)
			addInterest(I);
			else
			{
				printf("Failed to read the interest rate\n");
			}
			break;
		case 'P':
			Printer();
			break;
		case 'E':
			exit=1;
			break;
		default:
		printf("Invalid transaction type\n");
		//fflush(stdin);
			break;
		}

		//in = Catalog();	
	}
	printf("BYEBYE");
	return 0;
}
