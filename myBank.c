#include <stdio.h>
#include "myBank.h"

#define BankLimit 50
#define AccId 901 //from 901 to 950

//int inBank=0;
float Acc [50][2];//amount || taken/free (1/0)

void open(float amount){
	//printf("making account.... please wait!  ");
	if((freeSpace())>0)
	{
		//printf("entered if  ");
		int freePlace;
		for (int i = 0; i < 50; i++)
		{
			if(Acc[i][1]!=1)
			{
				freePlace=i;
				i=50;
			}	
		}
		Acc [freePlace][0]=amount;
		Acc [freePlace][1]=1;
		int a = freePlace+901;
		printf("New account number is: %d \n",a);
	}
	else
	{
		printf("could not open new account, there are already 50 accounts. \n");
	}
}
void Status(int x){
	if(Acc[x-901][1]==1)//need to check
	{
		double am = (double) Acc[x-901][0];
		printf("The balance of account number %d, is: %f",x,am);
	}
	else
	{
		printf("This account is closed");
	}
	
}
void deposit(int x, float amount){
	if(amount>0)
	{
		Acc [x-901][0]=Acc [x-901][0]+amount;
		printf("succesfuly added");
	}
	else
	{
		printf("Cannot deposit a negative amount \n");
	}
}
void withdraw(int x, float amount){
	if(Acc [x-901][0]-amount>=0)
		{
			Acc [x-901][0]-=amount;
			//printf("successful withrawn");
		}
		else
		{
			printf("there is not enough");
		}
	
}
void close (int x){
	if(Acc [x-901][1]==1)
	{
	Acc [x-901][0]=0;
	printf("Closed account number %ls",&x);
	//inBank--;
}else
{
	printf("This account is closed");
}

}

int isOpen(int x)
{
	if(Acc[x-901][1]==1)
	{
		return 1;
	}
	return 0;
}

void addInterest(double pct){
	for (int i = 0; i < 50; i++)
	{
		if(Acc[i][1]==1)
		{
		Acc [i][0]=(float)(Acc [i][0])*(1+(pct/100));
		}
	}
}
void Printer(){
	for (int i = 0; i < 50; i++)
	{
		if(Acc[i][1]==1)
		{
			int acc = (int)i+901;
			float amo = Acc[i][0];
			printf("The balance of account number %d is: %f", acc,amo);
		}
		
	}

}
void init(){
	for (int i = 0; i < 50; i++)
	{
		Acc [i][0]=0;
		Acc [i][1]=0;
	}
}
int freeSpace(){
	int ans=0;
	for (int i = 0; i < 50; i++)
	{
		if(Acc[i][1]==0)
		ans++;
	}
	
	return ans;
}

char Catalog()
{

			char in;
			
			return in;
}

