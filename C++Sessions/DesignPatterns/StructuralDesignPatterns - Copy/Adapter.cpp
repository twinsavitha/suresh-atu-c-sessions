// Adapter.cpp

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

class Shape
{
public:
	virtual void draw() = 0;
};

class Rectangle : public Shape
{
public:
	void draw() { cout << "Rendering a rectangle.\n"; }
};

class Triangle : public Shape
{
public:
	void draw() { cout << "Rendering a triangle.\n"; }
};

class RealHexagon
{
public:
	void display() { cout << "Rendering a hexagon.\n"; }
};

class Hexagon : public Shape
{
public:
	void draw() { hexagonObj_.display(); }
private:
	RealHexagon hexagonObj_;
};

int main()
{
	vector<Shape *> pShapes;
	int nChoice;
	while (true)
	{
		cout << "(1)Rectangle\n(2)Triangle\n(3)Hexagon\n(0)break\n";
		cout << "Enter your choice\n";
		cin >> nChoice;
		if (nChoice == 0) break;
		else if (nChoice == 1) { pShapes.push_back(new Rectangle); }
		else if (nChoice == 2) { pShapes.push_back(new Triangle); }
		else if (nChoice == 3) { pShapes.push_back(new Hexagon); }
	}

	for (int nIdx = 0; nIdx < pShapes.size(); nIdx++)
	{
		pShapes[nIdx]->draw();
	}
	return(0);
}