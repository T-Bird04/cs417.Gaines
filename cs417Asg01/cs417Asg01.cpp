#include <iostream>
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"


using namespace std;


int main()
{
	string shape = "";
	
	do
	{
		cout << "Which shape would you like to make: Square, Rectangle, Triangle, Circle?\n";
		cin >> shape;

		if (shape == "Square")
		{
			int length = 1;

			cout << "What is the length of your square?\n";
			cin >> length;

			Square userShape(length);

			cout << "The perimeter of your square is " << userShape.getPerimeter() << " and its area is " << userShape.getArea() << endl;
		}

		else if (shape == "Rectangle")
		{
			int length = 1, width = 1;

			cout << "What is the length of your rectangle?\n";
			cin >> length;
			cout << "What is the width of your rectangle?\n";
			cin >> width;

			Rectangle userShape(length, width);

			cout << "The perimeter of your rectangle is " << userShape.getPerimeter() << " and its area is " << userShape.getArea() << endl;
		}

		else if (shape == "Triangle")
		{
			int sideA = 1, sideB = 1, sideC = 1;

			cout << "What is the length of side A of your triangle?\n";
			cin >> sideA;
			cout << "What is the length of side B of your triangle?\n";
			cin >> sideB;
			cout << "What is the length of side C of your triangle?\n";
			cin >> sideC;

			Triangle userShape(sideA, sideB, sideC);

			cout << "The perimeter of your triangle is " << userShape.getPerimeter() << " and its area is " << userShape.getArea() << endl;
		}

		else if (shape == "Circle")
		{
			int radius = 1;

			cout << "What is the radius of your circle?\n";
			cin >> radius;

			Square userShape(radius);

			cout << "The perimeter of your circle is " << userShape.getPerimeter() << " and its area is " << userShape.getArea() << endl;
		}

	}while(shape != "Square" && shape != "Rectangle" && shape != "Triangle" && shape != "Circle");

}
