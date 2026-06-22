#include<iostream>
using namespace std;
int main()
{
    int a ,b;
    int num;
    char ch;
    cout<<"enter any two  numbers";
    cin>>a>>b;
    do
    {
        cout<<"press 1 for addition, press 2 for substraction, press 3 for multiplication, press 4 for division";
        cin>>num;
        switch(num)
        {
            case 1:
            cout<<"addition of two numbers is:"<<a+b;
            break;
            case 2:
            cout<<"substraction of two numbers is:"<<a-b;
            break;
            case 3:
            cout<<"multiplication of two numbers is:"<<a*b;
            break;
            case 4:
            cout<<"division of two numbers is:"<<a/b;
            break;
            default:
            cout<<"invalid input";
        
        }
        cout<<"do you want to continue";
        cin>>ch;
}
while(ch == 'y' || ch == 'Y');
return 0;
}