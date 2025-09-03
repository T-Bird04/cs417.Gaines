

class Square
{
private:
	int length = 1;
public:

	Square() {};
	Square(int a) { length = a; }
	
	
	void setLength(int);
	int getLength();
	int getArea();
	int getPerimeter();


};

void Square::setLength(int l)
{
	length = l;
}

int Square::getLength()
{
	return length;
}

int Square::getArea()
{
	return length * length;
}

int Square::getPerimeter()
{
	return length * 4;
}