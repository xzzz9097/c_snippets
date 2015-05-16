/*
	Classes and objects
*/

#include <iostream>
#include <cmath>

using namespace std;

char TITLE_AREA[] = "Area: ";
char TITLE_PERIMETER[] = "Perimeter: ";
char TITLE_DIAGONAL[] = "Diagonal: ";

class Rectangle {
	int width, height;

	public:
		Rectangle(int, int);

		int area() { return width * height; }
		int perimeter() { return (width + height) * 2; }
		float diagonal() { return sqrt(width*width+height*height); }
};

Rectangle::Rectangle(int w, int h) {
	width = w;
	height = h;
}

void print(char title[], float value) {
	cout << title << value << endl;
}

int main() {
	Rectangle mRectangle(2, 3);

	print(TITLE_AREA, mRectangle.area());
	print(TITLE_PERIMETER, mRectangle.perimeter());
	print(TITLE_DIAGONAL, mRectangle.diagonal());
}