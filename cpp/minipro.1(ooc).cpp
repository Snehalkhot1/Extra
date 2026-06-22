#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to set monthly budget
void setBudget() {
    float budget;
    cout << "Enter your monthly budget: ₹";
    cin >> budget;

    ofstream file("C:\\Users\\Public\\budget.txt");
    if (!file) {
        cout << "Error saving budget.\n";
        return;
    }

    file << budget;
    file.close();
    cout << "Budget set successfully!\n";
}

// Function to get the stored budget
float getBudget() {
    ifstream file("C:\\Users\\Public\\budget.txt");
    float budget = 0;

    if (file >> budget) {
        file.close();
        return budget;
    } else {
        file.close();
        return 0;
    }
}

// Function to calculate total expenses
float calculateTotalExpenses() {
    ifstream file("C:\\Users\\Public\\expenses.txt");
    string line;
    float total = 0;

    while (getline(file, line)) {
        size_t firstComma = line.find(',');
        if (firstComma != string::npos) {
            float amt = stof(line.substr(0, firstComma));
            total += amt;
        }
    }
    file.close();
    return total;
}

// Function to add expenses with categories and check budget
void addExpense() {
    float amount;
    string category, date;

    cout << "Enter amount: ";
    cin >> amount;
    cin.ignore();

    cout << "Enter category (e.g., Hostel, Mess, Shopping, JunkFood, Others): ";
    getline(cin, category);

    cout << "Enter date (DD-MM-YYYY): ";
    getline(cin, date);

    ofstream file("C:\\Users\\Public\\expenses.txt", ios::app);
    if (!file) {
        cout << "Error opening file. Try running as Administrator.\n";
        return;
    }

    file << amount << "," << category << "," << date << "\n";
    file.close();
    cout << "Expense added successfully!\n";

    // Budget check
    float total = calculateTotalExpenses();
    float budget = getBudget();

    if (budget > 0 && total > budget) {
        cout << "\n BUDGET ALERT: You have exceeded your monthly budget of ₹" << budget << "!\n";
        cout << "Your current total spending is ₹" << total << ".\n";
        cout << "Consider reviewing your expenses.\n";
    }
}

// Function to view all expenses
void viewExpenses() {
    ifstream file("C:\\Users\\Public\\expenses.txt");
    string line;

    cout << "\n--- Your Expenses ---\n";
    if (!file) {
        cout << "No expenses found or file missing.\n";
        return;
    }

    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

// Function to calculate total and category-wise percentage
void totalSummary() {
    ifstream file("C:\\Users\\Public\\expenses.txt");
    string line;

    float hostel = 0, mess = 0, shopping = 0, junk = 0, others = 0, total = 0;

    if (!file) {
        cout << "No expenses found or file missing.\n";
        return;
    }

    while (getline(file, line)) {
        size_t firstComma = line.find(',');
        size_t secondComma = line.find(',', firstComma + 1);

        float amount = stof(line.substr(0, firstComma));
        string category = line.substr(firstComma + 1, secondComma - firstComma - 1);

        total += amount;

        if (category == "Hostel") hostel += amount;
        else if (category == "Mess") mess += amount;
        else if (category == "Shopping") shopping += amount;
        else if (category == "JunkFood") junk += amount;
        else others += amount;
    }
    file.close();

    cout << "\n--- Expense Summary ---\n";
    cout << "Total Expense: ₹" << total << "\n";
    if (total == 0) return;

    cout << "Hostel Fee: " << (hostel / total) * 100 << "%\n";
    cout << "Mess Fee: " << (mess / total) * 100 << "%\n";
    cout << "Shopping: " << (shopping / total) * 100 << "%\n";
    cout << "Junk Food: " << (junk / total) * 100 << "%\n";
    cout << "Others: " << (others / total) * 100 << "%\n";

    float extraSpending = shopping + junk + others;
    if (extraSpending > 500) {
        cout << "\n ALERT: You are overspending ₹" << extraSpending << " on non-essential items!\n";
        cout << "Try to reduce shopping, junk food, or other expenses.\n";
    }

    float budget = getBudget();
    if (budget > 0 && total > budget) {
        cout << "\n BUDGET ALERT: You have exceeded your monthly budget of ₹" << budget << "!\n";
        cout << "Consider reviewing your spending habits.\n";
    }
}

// Main menu
int main() {
    int choice;

    while (true) {
        cout << "\n--- Expense Tracker Menu ---\n";
        cout << "1. Add Expense\n";
        cout << "2. View All Expenses\n";
        cout << "3. Expense Summary\n";
        cout << "4. Set Monthly Budget\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addExpense(); break;
            case 2: viewExpenses(); break;
            case 3: totalSummary(); break;
            case 4: setBudget(); break;
            case 5: cout << "Goodbye!\n"; return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
}