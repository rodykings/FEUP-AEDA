/*
 * Bank.cpp
 */

#include "Bank.h"
#include <algorithm>
#include <string>

Bank::Bank() {}

void Bank::addAccount(Account *a) {
	accounts.push_back(a);
}

void Bank::addBankOfficer(BankOfficer b){
	bankOfficers.push_back(b);
}

vector<BankOfficer> Bank::getBankOfficers() const {
	return bankOfficers;
}

vector<Account *> Bank::getAccounts() const {
	return accounts;
}


// ----------------------------------------------------------------------------------------------

// a alterar
double Bank::getWithdraw(string cod1) const{
    double balance;
	for(int i=0; i < this->accounts.size(); i++){
	    if(this->accounts.at(i)->getCodH() == cod1){
	        balance += this->accounts.at(i)->getBalance();
	    }
	}
	return balance;
}


// a alterar
vector<Account *> Bank::removeBankOfficer(string name){
    vector<Account *> accounts;
    vector<BankOfficer>::iterator it = this->bankOfficers.begin();
	for(it; it != this->bankOfficers.end(); it++){
	    if((*it).getName() == name){
            accounts = (*it).getAccounts();
            this->bankOfficers.erase(it);
	    }
	    break;
	}
	return accounts;

}


// a alterar
const BankOfficer & Bank::addAccountToBankOfficer(Account *ac, string name) {
    BankOfficer *bo= new BankOfficer();
    return *bo;
}


// a alterar
void Bank::sortAccounts() {
}

