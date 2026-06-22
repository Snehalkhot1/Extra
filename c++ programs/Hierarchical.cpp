#include<iostream>
using namespace std;
class Library{
public:
	void book(){
			cout<<"Books are in the library"<<endl;
	}
};
class Mathematics : public Library{
public:
	void formula(){
		cout<<"Mathematics Book"<<endl;
		cout<<"This book include formulas"<<endl;
	}
};
class Ooc : public Library{
public:
	void program(){
		cout<<"Object-oriented program"<<endl;
		cout<<"This book includes syntax"<<endl;
	}
};
int main(){
	Mathematics m;
	Ooc o;
	m.book();
	m.formula();
	o.book();
	o.program();
	return 0;
}
