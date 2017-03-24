#ifndef _RECTANGLE_
#define _RECTANGLE_

#include <vector>
#include <algorithm>

using namespace std;

class Rectangle
{
public:
	Rectangle();
	Rectangle(int x, int y, int w, int h);
	Rectangle(const Rectangle &other);
	Rectangle& operator=(const Rectangle &other);

	int x, y; // top left corner
	int w, h; // width and height
	
	bool operator==(const Rectangle &other);
	Rectangle intersectionWith(const Rectangle &other) const;
	
	vector<int> parentRectangles; // retains the indeces of the rectangles that form the current one(this)
};

#endif