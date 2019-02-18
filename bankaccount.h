#include <iostream>
#include <string>
using namespace std;

class bankacc{
private:
	string name;
	int accNo;
	float balance;
	float balanceLimit;
	float* trans;
	int tcapacity;
	int no_of_trans;
	

public:
	bankacc(string Name, int no);

	string getName();
	int getAccNo();
	float getBalance();
	void getTransactions();
	int getNo_of_trans();
	void addTransaction(int amount);
	void Print();
	void withDraw(int amount);
	void deposit(int amount);

	~bankacc();
};