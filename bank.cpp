#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    string owner;
    double balance;

public:
    BankAccount(string name, double bal) {
        owner = name;
        balance = bal;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if(amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << ", Remaining Balance: " << balance << endl;
        } else {
            cout << "Insufficient Balance!" << endl;
        }
    }

    void display() {
        cout << "Owner: " << owner << ", Balance: " << balance << endl;
    }
};

int main() {
    BankAccount acc("Nisha", 1000);
    acc.display();
    acc.deposit(500);
    acc.withdraw(200);
    acc.withdraw(2000); // example of insufficient balance
    return 0;
}
