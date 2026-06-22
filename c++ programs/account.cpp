#include <iostream>
using namespace std;

class Account {
private:
    string accountNumber;
    string holderName;
    int balance;

public:
    Account(string accNo, string name, int bal = 0) {
        accountNumber = accNo;
        holderName = name;
        balance = bal;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "No balance!" << endl;
        }
    }

    void statement() {
        cout << "\n--- Account Statement ---" << endl;
        cout << "Account No: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: " << balance << endl;
    }
};


class SavingsAccount : public Account {
public:
    SavingsAccount(string accNo, string name, int bal = 0)
        : Account(accNo, name, bal) {}
};


class CheckingAccount : public Account {
public:
    CheckingAccount(string accNo, string name, int bal = 0)
        : Account(accNo, name, bal) {}
};

int main() {
    string accNo, name;
    double balance, amount;

    cout << "Enter Savings Account Details\n";
    cout << "Account Number: ";
    cin >> accNo;
    cout << "Holder Name: ";
    cin >> name;
    cout << "Initial Balance: ";
    cin >> balance;

    SavingsAccount s1(accNo, name, balance);

    cout << "\nEnter amount to deposit in Savings Account: ";
    cin >> amount;
    s1.deposit(amount);

    cout << "Enter amount to withdraw from Savings Account: ";
    cin >> amount;
    s1.withdraw(amount);

    s1.statement();

    cout << "\nEnter Checking Account Details\n";
    cout << "Account Number: ";
    cin >> accNo;
    cout << "Holder Name: ";
    cin >> name;
    cout << "Initial Balance: ";
    cin >> balance;

    CheckingAccount c1(accNo, name, balance);

    cout << "\nEnter amount to deposit in Checking Account: ";
    cin >> amount;
    c1.deposit(amount);

    cout << "Enter amount to withdraw from Checking Account: ";
    cin >> amount;
    c1.withdraw(amount);

    c1.statement();

    return 0;
}