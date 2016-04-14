// BeforePrototype.cpp

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;

// Object hierarchy
class Widget
{
public:
	virtual void draw() = 0;
};

class Button : public Widget
{
public:
	void draw() { cout << "Rendering a button\n"; }
};

class Scrollbar : public Widget
{
public:
	void draw() { cout << "Rendering a scroll bar\n"; }
};

class Textbox : public Widget
{
public:
	void draw() { cout << "Rendering a text box\n"; }
};

// Client
int main()
{
	vector<Widget *> vecp2Widgets;
	int option;

	while (true)
	{
		cout << "(1) Button\n"
			 << "(2) Scroll bar\n"
			 << "(3) Text box\n"
			 << "(0)break\n"
			 << "Enter your option\n";
		cin >> option;

		if      (option == 0) break;
		else if (option == 1) vecp2Widgets.push_back(new Button);
		else if (option == 2) vecp2Widgets.push_back(new Scrollbar);
		else if (option == 3) vecp2Widgets.push_back(new Textbox);
	}

	for (int nIdx = 0; nIdx < vecp2Widgets.size(); nIdx++)
	{
		vecp2Widgets[nIdx]->draw();
	}

	return(0);
}
