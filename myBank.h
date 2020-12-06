#ifndef _myBank_h
#define _myBank_h

#define BankLimit 50
#define AccId 901 //from 901 to 950

	void open(float amount);
	void Status(int x);
	void deposit(int x, float amount);
	void withdraw(int x, float amount);
	void close (int x);
	void addInterest(double pct);
	void Printer();
	int isOpen(int x);
	int freeSpace();
	char Catalog();

#endif
