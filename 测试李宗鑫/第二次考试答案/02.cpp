#include <iostream>
using namespace std;
#define PI 3.14
class Figure
{
public:
	virtual void Perimeter() = 0;
	virtual void Area() = 0;
};

class Rectangle:public Figure
{
public:
	int length;
	int width;
	Rectangle(int length, int width) :length(length), width(width)
	{

	}
	virtual void Perimeter()
	{
		cout << "the perimeter of rectangle is " << (length + width) * 2 << endl;
	}
	virtual void Area()
	{
		cout << "the area of rectangle is " << length*width << endl;
	}
};

class Circle :public Figure
{
public:
	int radius;
	Circle(int radius) :radius(radius)
	{

	}
	virtual void Perimeter()
	{
		cout << "the perimeter of circle is " << 2 * PI*radius << endl;
	}
	virtual void Area()
	{
		cout << "the area of circle is " << PI*radius*radius << endl;
	}
};

void Func(Figure *figure)
{
	figure->Perimeter();
	figure->Area();
	delete figure;
}

//int main()
//{
//	Func(new Rectangle(3, 2));
//	Func(new Circle(2));
//	return 0;
//}