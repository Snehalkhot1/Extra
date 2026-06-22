#include<iostream>
using namespace std;
class Student
{
    public:
    int roll_no;
    string name;
};
int main(){
     int n;
     cout<<"How many students record u want to save?";
     cin>>n;
     Student S[n];
     cout<<"Enter the details of students:"<<n<<endl;
    for(int i=0;i<n;i++){
    cout<<"Number of Student:"<<i+1<<endl;
    cout<<"Enter the roll no:";
    cin>>S[i].roll_no;
    cout<<"Enter the name:";
    cin>>S[i].name;
    }
cout<<" details of 5 students:"<<endl;
for(int i=0;i<n;i++){
cout<<"Number of Student:"<<i+1<<endl;
    cout<<"The roll no is "<<S[i].roll_no<<endl;
    cout<<"The name is "<<S[i].name<<endl;
}
}