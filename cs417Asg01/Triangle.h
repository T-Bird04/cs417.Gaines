

class Triangle
{
private:
	int sideA = 1;
	int sideB = 1;
	int sideC = 1;
public:

	Triangle() {};
	Triangle(int a) { sideA = a, sideB = a, sideC = a; }
	Triangle(int a, int b, int c) { sideA = a, sideB = b, sideC = c; }


	void setSideA(int);
	int getSideA();
	void setSideB(int);
	int getSideB();
	void setSideC(int);
	int getSideC();
	int getArea();
	int getPerimeter();

};

void Triangle::setSideA(int a)
{
	sideA = a;
}

int Triangle::getSideA()
{
	return sideA;
}

void Triangle::setSideB(int b)
{
	sideB = b;
}

int Triangle::getSideB()
{
	return sideB;
}

void Triangle::setSideC(int c)
{
	sideC = c;
}

int Triangle::getSideC()
{
	return sideC;
}

int Triangle::getArea()
{
	return sqrt((getPerimeter() / 2) * (getPerimeter() / 2 - sideA) * (getPerimeter() / 2 - sideB) * (getPerimeter() / 2 - sideC));
}

int Triangle::getPerimeter()
{
	return sideA + sideB + sideC;
}