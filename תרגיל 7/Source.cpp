/*
maor levi 328301981
ary oz 321918484 
*/

#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
enum SHAPES { CIRCLE = 1, TRIANGLE = 3, RECTANGLE };
int main() {
	Point p;

	int numShapes, choice;
	cout << "How many shapes you would like to define?\n";
	cin >> numShapes;
	Shape** shapes = new Shape * [numShapes];
	for (int i = 0; i < numShapes; i++) {
		cout << "Which shape will you choose? Circle - 1, Triangle - 3, Rectangle - 4\n";
		cin >> choice;
		switch (choice) {
		case CIRCLE:
			float radius;
			cout << "Enter radius:\n";
			cin >> radius;
			shapes[i] = new Circle(radius);
			break;
		case TRIANGLE:
			
			shapes[i] = new Triangle();
			break;
		case RECTANGLE:
			shapes[i] = new Rectangle();
			break;
		default:
			cout << "invalid input\n";
			i--;
		}

	}

	for (int i = 0; i < numShapes; i++) {
		cout << *shapes[i];
		cout << "area is: " << shapes[i]->area() << endl;;
		if (shapes[i]->isSpecial()) {
			shapes[i]->printSpecial();
		}
		cout << endl;
	}




return 0;
}
