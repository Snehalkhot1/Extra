#include <iostream>

using namespace std;

class Shape {
public:
    double area(double radius) {
        return 2 * radius * radius;
    }

    int area(int side) {
        return side * side;
    }

    double area(double base, double height) {
        return 0.5 * base * height;
    }
};

int main() {
    Shape s;

    double circleRadius = 5.0;
    int squareSide = 4;
    double triangleBase = 6.0;
    double triangleHeight = 3.0;

    cout << "Area of Circle: " << s.area(circleRadius) << endl;
    cout << "Area of Square: " << s.area(squareSide) << endl;
    cout << "Area of Triangle: " << s.area(triangleBase, triangleHeight) << endl;

    return 0;
}