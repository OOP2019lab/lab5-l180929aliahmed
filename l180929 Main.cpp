#include <iostream>
#include "bankaccount.h"
#include <string>
using namespace std;

int main(){
	bankacc myAccount("John Doe",549002);
	for(int i=0; i<20; i++){
		myAccount.deposit(i+20);
		myAccount.withDraw(i);
	}
	myAccount.Print();

}
