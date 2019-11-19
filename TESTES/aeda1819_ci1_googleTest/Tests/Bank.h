/*
 * Bank.h
 */

#ifndef SRC_BANK_H_
#define SRC_BANK_H_

#include "Account.h"
#include <vector>
#include <iostream>

#include "BankOfficer.h"


class Bank {
	vector<Account *> accounts;
	vector<BankOfficer> bankOfficers;
public:
	Bank();
	void addAccount(Account *a);
	void addBankOfficer(BankOfficer b);
	vector<BankOfficer> getBankOfficers() const;
	vector<Account *> getAccounts() const;

	//-------
	double getWithdraw(string cod1) const;
	vector<Account *> removeBankOfficer(string name);
	const BankOfficer& addAccountToBankOfficer(Account *ac, string name);
	void sortAccounts();
};


template<typename T>
unsigned int numberDifferent (const vector<T> & v1)
{
    vector<T> copy = v1;
    size_t size = copy.size();
    auto fix = copy.begin();
    auto it = copy.begin();
    int counter = 0;

    while(fix != copy.end()){
        it=copy.begin();
        it++;
        for(it; it!=copy.end(); it++){
            if((*fix) == (*it)){
                counter++;
            }
        }
        copy.erase(fix);
        fix++;
    }
    return size-counter;

}




#endif /* SRC_BANK_H_ */
