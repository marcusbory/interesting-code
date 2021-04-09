#pragma once
#include <bits/stdc++.h>
#include <string>
using namespace std;

class BankAcc {
private:
    string _name;
    float _balance;
public:
    BankAcc(float deposit) {
        this->_name = "NO NAME";
        this->_balance = deposit;
    }
    BankAcc(string name, float deposit) {
        this->_name = name;
        this->_balance = deposit;
    }
    ~BankAcc();
    void deposit(float money);
    void withdraw(float money);
    float checkBal();
    string checkName();
    void setName(string name);
};

void BankAcc::deposit(float money) {
    this->_balance += money;
    cout << "New balance: " << this->_balance << endl;
}

void BankAcc::withdraw(float money) {
    if (money > this->_balance) {
        cout << "Insufficient funds to withdraw " << money << endl;
        return;
    }
    cout << "Amount withdrawn: " << money << endl;
    this->_balance -= money;
    cout << "Amount remaining: " << this->_balance << endl;
}

float BankAcc::checkBal() {
    return this->_balance;
}

string BankAcc::checkName() {
    return this->_name;
}

void BankAcc::setName(string name) {
    this->_name = name;
    cout << "Name of account holder is now: " << this->_name << endl;
}
