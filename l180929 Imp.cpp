#include <iostream>
#include <string>
#include "bankaccount.h"
using namespace std;

//Constructor
bankacc::bankacc(string Name, int no){
	name=Name;
	accNo=no;
	balance=0;
	tcapacity=10;
	trans=new float [tcapacity];
	no_of_trans=0;
	balanceLimit=200000;
}

//Get Name 
string bankacc::getName(){
	return name;
}

//Get Account Number
int bankacc::getAccNo(){
	return accNo;
}

//Get Balance
float bankacc::getBalance(){
	return balance;
}

//Diplaying Transaction History
void bankacc::getTransactions(){
	for(int i=0; i< no_of_trans ; i++){
		cout<<trans[i]<<endl;
	}
	cout<<endl;
}

//Get Number of transactions
int bankacc::getNo_of_trans(){
	return no_of_trans;
}

//Print Account information
void bankacc::Print(){
	cout<<"Account Holder's Name: "<<getName()<<endl;
	cout<<"Account Number: "<<getAccNo()<<endl;
	cout<<"Balance: "<<getBalance()<<endl;
	cout<<"Total No of Transactions: "<<getNo_of_trans()<<endl;
	cout<<"Transaction History: "<<endl;
	getTransactions();
}


//Adding New entry in Transaction array or increasing transaction capacity
void bankacc::addTransaction(int amount){
	if(no_of_trans<tcapacity){
		trans[no_of_trans]=amount;
		no_of_trans++;
	}
	else if(no_of_trans>=tcapacity){
		tcapacity=2*tcapacity;
		float* temp=new float [tcapacity];
		for(int i=0; i<no_of_trans; i++){
			temp[i]=trans[i];
		}
		temp[no_of_trans]=amount;
		no_of_trans++;
		delete[]trans;
		trans=temp;
	}
}

//Withdraw function
void bankacc::withDraw(int amount){
	if(amount<=balance){
		cout<<"Transaction Successful!"<<endl<<endl;
		balance=balance-amount;
		amount=-amount;
		addTransaction(amount);
	}
	else if(amount>balance){
		cout<<"Transaction Unsuccessful:Insufficient Balance."<<endl<<endl;
	}
}

//Deposit function
void bankacc::deposit(int amount){
	if(balance+amount>balanceLimit){
		cout<<"Balance Limit Exceeded!"<<endl<<endl;
	}
	else{
		cout<<"Deposit Successful!"<<endl<<endl;
		balance=balance+amount;
		addTransaction(amount);
	}
}

//Destructor function
bankacc::~bankacc(){
	name.clear();
	accNo=-1;
	balance=-1;
	no_of_trans=-1;
	tcapacity=-1;
	balanceLimit=-1;
	delete[] trans;
	trans=nullptr;
}
