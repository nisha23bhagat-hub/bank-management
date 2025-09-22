#include <cstdlib> // for clearscreen (system("cls"))
#include <iomanip> // for setw() (display formatting), fixed, and setprecision(n)
#include <iostream>
#include <limits> // for cin.ignore(numeric_limits<streamsize>::max(), '\n')
#include <string>
using namespace std;

/*
    Improvements Added:
    1. Added comments for better code clarity and organization
    2. Renamed variables for clearer variable names
    3. Added getters and setters (follow principles of Object-Oriented Programming)
    4. Added error handling for robustness
    5. Replaced endline (endl) with a newline (\n) for performance (very useful if project scales)
    6. Added TUI (Text-based User Interface) for better user & developer's experience
    7. Added user input instead of parameterized values
    8. Added default constructor for clean object instantiation
    9. Used 'fixed' and 'setprecision(n)' for outputting amount up to 2 decimal places
*/

class BankAccount {
    // Attributes
    string name;
    double balance;

public:
    // Default Constructor
    BankAccount() {
        this->name = "N/A";
        this->balance = 0;
    }

    // Parameterized Constructor
    BankAccount(string name, double balance) {
        this->name = name;
        this->balance = balance;
    }

    // Getters & Setters
    string getName() { return this->name; }
    double getBalance() { return this->balance; }

    void setName(string name) { this->name = name; }
    void setBalance(double balance) { this->balance = balance; }

    // Methods: Utility
    void pressEnterToContinue() {
        cout << "Press [Enter] to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    // Methods
    void deposit() {
        double amount = 0;

        // This loop runs indefinitely until the user enters a valid deposit amount
        while (true) {
            // Prompt user to enter deposit amount
            cout << "Enter amount to deposit: $";
            cin >> amount;

            if (cin.fail()) { // ERROR: Input mismatch
                cout << "ERROR: Invalid input, please enter a valid deposit amount\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else if (amount <= 0) { // ERROR: Invalid deposit amount
                cout << "ERROR: Invalid deposit amount (must be positive)" << '\n';
                return;
            } else break;
        }

        // If no errors found, add the deposited amount to the balance
        balance += amount;

        system("cls");
        cout << "SUCCESS: Deposit successful!\n";
        cout << fixed << setprecision(2) << "Deposited: $" << amount << '\n';
        cout << "New Balance: $" << getBalance() << '\n';
        pressEnterToContinue();
    }

    void withdraw() {
        double amount = 0;

        // This loop runs indefinitely until the user enters a valid withdrawal amount
        while (true) {
            // Display current balance for user's convenience
            cout << "Current Balance: $" << getBalance() << '\n';

            // Prompt user to enter deposit amount
            cout << "Enter amount to withdraw: $";
            cin >> amount;
            
            if (cin.fail()) { // ERROR: Input mismatch
                cout << "ERROR: Invalid input, please enter a valid withdrawal amount\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else if (amount > getBalance()) { // ERROR: Invalid withdrawal amount
                cout << "ERROR: Invalid withdrawal amount (exceeds balance)";
                return;
            } else break;
        }

        // If no errors found, subtract the withdrawn amount from the balance
        balance -= amount;

        system("cls");
        cout << "SUCCESS: Withdrawal successful!\n";
        cout << fixed << setprecision(2) << "Withdrawal Amount: $" << amount << '\n';
        cout << "Current Balance: $" << getBalance() << endl;
        pressEnterToContinue();
    }

    void displayAccountDetails() {
        cout << "[ ACCOUNT DETAILS ]\n";
        cout << right << setw(8) << "Owner:"   << " " << getName() << '\n';
        cout << right << setw(8) << "Balance:" << " $" << fixed << setprecision(2) << getBalance() << '\n';


        pressEnterToContinue();
    }

    void displayMenu() {
        // This loop runs indefinitely until user decides to exit system
        while (true) {
            system("cls"); // Clear console screen before displaying

            cout << "===== Bank Management System =====\n";
            cout << "[1] Deposit\n";
            cout << "[2] Withdraw\n";                        
            cout << "[3] Display Account Details\n";
            cout << "[4] Exit\n";

            int choice = -1;

            // Prompt user to enter choice
            while (true) {
                cout << "Enter choice: ";
                cin >> choice;

                // ERROR: Invalid choice
                if (choice < 1 || choice > 4) {
                    cout << "ERROR: Invalid choice, please enter a number between 1-4\n";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    pressEnterToContinue();
                } else break;
            }

            system("cls"); // Clear console screen before navigating

            // Navigate based on user choice
            switch (choice) {
                case 1: { // Deposit
                    deposit();
                    break;
                }
                case 2: { // Withdraw
                    withdraw();
                    break;
                }
                case 3: { // Display account details
                    displayAccountDetails();
                    break;
                }
                case 4: {
                    cout << "Exiting system...";
                    exit(0);
                }
            }
        }
    }
};

int main() {
    BankAccount bank = BankAccount();
    bank.displayMenu(); // Display main menu

    return 0;
}
