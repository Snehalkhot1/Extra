#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double breadth;

public:
    rectangle(double l, double b) {
        length = l;
        breadth = b;
        cout<<"constructor called"<<endl;
    }
    double area() {
        return length * breadth;
    }
    double perimeter() {
        return 2 * (length + breadth);
    }
    ~rectangle() {
        cout<<"destructor called"<<endl;

    }
};
int main() {
    rectangle r(10.5,5.5);
    cout<<"area of rectangle is "<<r.cout<<endl;
    cout<<"perimeter of rectangle is "<<r.perimeter()<<endl;
    return 0;
}