// AbstractFactory.cpp

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

// Hierarchy of widgets

/*Button*/
class CButton
{
public:
	virtual void paint() = 0;
};

class CMacButton : public CButton
{
public:
	void paint() { cout << "Mac button\n"; }
};

class CWndButton : public CButton
{
public:
	void paint() { cout << "Windows button\n"; }
};

/*Scroll bar*/
class CScrollbar
{
public:
	virtual void paint() = 0;
};

class CMacScrollbar : public CScrollbar
{
public:
	void paint() { cout << "Mac scrollbar\n"; }
};

class CWndScrollbar : public CScrollbar
{
public:
	void paint() { cout << "Windows scrollbar\n"; }
};

// Implement a 
class CWidgetFactory
{
public:
	virtual CButton* createButton() = 0;
	virtual CScrollbar* createScrollbar() = 0;
};

class CWndWidgetsFactory : public CWidgetFactory
{
public:
	CButton* createButton() { return(new CWndButton); }
	CScrollbar* createScrollbar() { return(new CWndScrollbar); }
};

class CMacWidgetsFactory : public CWidgetFactory
{
public:
	CButton* createButton() { return(new CMacButton); }
	CScrollbar* createScrollbar() { return(new CMacScrollbar); }
};

// Client
int main()
{
	CButton *pButton;
	CScrollbar *pScrollbar;
	CWidgetFactory *pWidgetFactory;

	pWidgetFactory = new CMacWidgetsFactory;
	pButton = pWidgetFactory->createButton();
	pButton->paint();
	pScrollbar = pWidgetFactory->createScrollbar();
	pScrollbar->paint();

	pWidgetFactory = new CWndWidgetsFactory;
	pButton = pWidgetFactory->createButton();
	pButton->paint();
	pScrollbar = pWidgetFactory->createScrollbar();
	pScrollbar->paint();

	return(0);
}
