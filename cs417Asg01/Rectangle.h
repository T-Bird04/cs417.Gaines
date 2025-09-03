

class Rectangle
{
private:
	int length = 1;
	int width = 1;
public:

	Rectangle() {};
	Rectangle(int a) { length = a, width = a; }
	Rectangle(int a, int b) { length = a, width = b; }

	void setLength(int);
	int getLength();
	void setWidth(int);
	int getWidth();
	int getArea();
	int getPerimeter();


};

void Rectangle::setLength(int l)
{
	length = l;
}

int Rectangle::getLength()
{
	return length;
}

void Rectangle::setWidth(int w)
{
	width = w;
}

int Rectangle::getWidth()
{
	return width;
}

int Rectangle::getArea()
{
	return length * width;
}

int Rectangle::getPerimeter()
{
	return 2 * length + 2 * width;
}