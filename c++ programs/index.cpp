#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Expense {
    string category;
    float amount;
    string date;
};

vector<Expense> expenses;

void addExpense() {
    Expense e;
    cout << "Enter category (e.g., Food, Transport): ";
    cin >> e.category;
    cout << "Enter amount: ";
    cin >> e.amount;
    cout << "Enter date (YYYY-MM-DD): ";
    cin >> e.date;

    expenses.push_back(e);

    ofstream file("expenses.txt", ios::app);
    file << e.category << " " << e.amount << " " << e.date << endl;
    file.close();

    cout << "Expense added!\n";
}

void viewExpenses() {
    ifstream file("expenses.txt");
    string category, date;
    float amount;

    cout << "\nYour Expenses:\n";
    while (file >> category >> amount >> date) {
        cout << "Category: " << category << ", Amount: " << amount << ", Date: " << date << endl;
    }
    file.close();
}

int main() {
    int choice;
    do {
        cout << "\n--- Smart Expense Tracker ---\n";
        cout << "1. Add Expense\n2. View Expenses\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addExpense(); break;
            case 2: viewExpenses(); break;
            case 3: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 3);

    return 0;
}