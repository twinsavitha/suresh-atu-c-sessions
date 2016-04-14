// BeforeAbstractFactory.cpp

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

// Client
int main()
{
	CButton *pButton = new CMacButton;
	pButton->paint();
	delete pButton;
	
	CScrollbar *pScrollbar = new CMacScrollbar;
	pScrollbar->paint();
	delete pScrollbar;
	
	pButton = new CWndButton;
	pButton->paint();
	delete pButton;

	pScrollbar = new CWndScrollbar;
	pScrollbar->paint();
	delete pScrollbar;
	
	return(0);
}
