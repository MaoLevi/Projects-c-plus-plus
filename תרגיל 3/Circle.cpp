#include "Circle.h"
//#include "Point.h"
#include <iostream>
#include <string>
/*
maor levi
328301981
sadna
targil#1-3
the program recieve 3 circle and calculte the area and the center of them
the program ask from the user point and check if the point in the circlle

*/
const double PAY = 3.14;
using namespace std;
void Circle::setcenter(int x, int y) {
    center.setX(x);
    center.setY(y);

}

void Circle::setRadius(int myRadius) {
    radius = myRadius;
}
Point Circle::getcenter() {
    return center;
}
int Circle::getRadius() {
    return radius;
}
double Circle::area() {
    return (PAY * radius * radius);
}
double Circle::perimeter() {
    return (2 * PAY * radius);
}
int Circle::onInOut(Point p) {
    double num;
    num = (((p.getX() - center.getX()) * (p.getX() - center.getX())) + ((p.getY() - center.getY()) * (p.getY() - center.getY())));
    if (num == radius * radius)
        return 0;
    if (num < radius * radius)
        return -1;
    if (num > radius * radius)
        return 1;

}

