#include "Rectangle.h"

Rectangle::Rectangle()
{
	x = y = w = h = 0;
}

Rectangle::Rectangle(int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

Rectangle::Rectangle(const Rectangle &other)
{
	this->x = other.x;
	this->y = other.y;
	this->w = other.w;
	this->h = other.h;
	this->parentRectangles = other.parentRectangles;
}

Rectangle& Rectangle::operator =(const Rectangle &other)
{
	this->x = other.x;
	this->y = other.y;
	this->w = other.w;
	this->h = other.h;
	this->parentRectangles = other.parentRectangles;
	return *this;
}

bool Rectangle::operator==(const Rectangle &other)
{
	if (x == other.x && y == other.y && w == other.w && h == other.h)
		return true;
	return false;
}

Rectangle Rectangle::intersectionWith(const Rectangle &other) const
{
	int x1, x2, y1, y2;
	x1 = std::max(this->x, other.x);
	y1 = std::max(this->y, other.y);
	x2 = std::min(this->x + this->w, other.x + other.w);
	y2 = std::min(this->y + this->h, other.y + other.h);
	
	if (x1 < x2 && y1 < y2) // valid rectangle of intersection
	{
		return Rectangle(x1, y1, x2 - x1, y2 - y1);
	}
	
	return Rectangle();
}