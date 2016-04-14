// Prototype.cpp

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;

// Object hierarchy
class Widget
{
public:
	virtual Widget* clone() = 0;
	virtual void draw() = 0;
};

class Button : public Widget
{
public:
	Widget* clone() { return(new Button); }
	void draw() { cout << "Rendering a button\n"; }
};

class Scrollbar : public Widget
{
public:
	Widget* clone() { return(new Scrollbar); }
	void draw() { cout << "Rendering a scroll bar\n"; }
};

class Textbox : public Widget
{
public:
	Widget* clone() { return(new Textbox); }
	void draw() { cout << "Rendering a text box\n"; }
};

class Factory
{
public:
	static Widget* createWidget(int option);
private:
	static Widget* s_prototypes[4];
};

// Initializing the static class member
// The first object of each type is created here.
Widget* Factory::s_prototypes[] = {0, new Button, new Scrollbar, new Textbox};
Widget* Factory::createWidget(int option)
{
	return(s_prototypes[option]->clone()); // clone the object asked for
}


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

		if (option == 0) break;
		vecp2Widgets.push_back(Factory::createWidget(option));
	}

	for (int nIdx = 0; nIdx < vecp2Widgets.size(); nIdx++)
	{
		vecp2Widgets[nIdx]->draw();
	}

	return(0);
}
