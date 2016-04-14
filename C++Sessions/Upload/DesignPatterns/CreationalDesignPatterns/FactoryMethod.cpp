// FactoryMethod.cpp

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;


// Hierarchy of widgets
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

// Implement an interface for creating objects
// and let subclasses decide the creation of objects
class CWidget
{
public:
	virtual CButton* createButton(string) = 0;
};

// virtual constructor??? kind of
class CWidgetFactory : public CWidget
{
public:
	CButton* createButton(string strOStype)
	{
		if      (strOStype.compare("Mac") == 0) { return(new CMacButton); }
		else if (strOStype.compare("Windows") == 0) { return(new CWndButton); }
	}
};

// Client
int main()
{
	vector<CButton *> vecPtrButtons;
	CWidget *pWidgetFactory = new CWidgetFactory;
	int nChoice;

	while (true)
	{
		cout << "(1)Mac button\n(2)Windows button\n(0)None\n";
		cout << "Enter your choice\n";
		cin >> nChoice;
		
		// Client now does not have knowledge of the actual classes responsible for the
		// objects it need.
		if      (nChoice == 1) { vecPtrButtons.push_back(pWidgetFactory->createButton("Mac")); }
		else if (nChoice == 2) { vecPtrButtons.push_back(pWidgetFactory->createButton("Windows")); }
		else if (nChoice == 0) { break; }
	}
	for (int nIdx = 0; nIdx < vecPtrButtons.size(); nIdx++)
	{
		vecPtrButtons[nIdx]->paint();
	}

	for (int nIdx = 0; nIdx < vecPtrButtons.size(); nIdx++)
	{
		delete vecPtrButtons[nIdx];
	}
	
	return(0);
}
