#include<iostream>
#include<string>
using namespace std;

class Name {
public:
    string name;
    void inputName() {
        cout << "Enter name of student: ";
        cin >> name;
    }
    void showName() {
        cout << "Name of student is: " << name << endl;
    }
};

class Roll_no {
public:
    int roll_no;
    void inputRoll_no() {
        cout << "Enter roll number of student: ";
        cin >> roll_no;
    }
    void showRoll_no() {
        cout << "Roll number of student is: " << roll_no << endl;
    }
};

class Record : public Name, public Roll_no {
public:
    void inputRecord() {
        inputName();
        inputRoll_no();
    }
    void showRecord() {
        cout << "The student record is:" << endl;
        showName();
        showRoll_no();
    }
};

int main() {
    Record obj;
    obj.inputRecord();   
    obj.showRecord();    
    return 0;
}