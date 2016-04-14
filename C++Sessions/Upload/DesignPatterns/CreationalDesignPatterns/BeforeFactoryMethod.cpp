// BeforeFactoryMethod.cpp

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

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

// Client
int main()
{
	vector<CButton *> vecPtrButtons;
	int nChoice;

	while (true)
	{
		cout << "(1)Mac button\n(2)Windows button\n(0)None\n";
		cout << "Enter your choice\n";
		cin >> nChoice;
		
		// Client has knowledge of the actual classes responsible for the
		// objects it need.
		if      (nChoice == 1) { vecPtrButtons.push_back(new CMacButton); }
		else if (nChoice == 2) { vecPtrButtons.push_back(new CWndButton); }
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
