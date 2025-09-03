

class Circle
{
private:
	int radius = 1;
public:

	Circle() {};
	Circle(int a) { radius = a; }

	void setRadius(int);
	int getRadius();
	int getArea();
	int getPerimeter();


};


void Circle::setRadius(int r)
{
	radius = r;
}

int Circle::getRadius()
{
	return radius;
}

int Circle::getArea()
{
	return (3.14 * radius * radius);
}

int Circle::getPerimeter()
{
	return (2 * 3.14 * radius);
}