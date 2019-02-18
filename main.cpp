#include <iostream>
#include "bankaccount.h"
#include <string>
using namespace std;

int main(){
	bankacc myAccount("John Doe",549002);
	myAccount.deposit(50000);
	myAccount.withDraw(2000);
	myAccount.Print();

}