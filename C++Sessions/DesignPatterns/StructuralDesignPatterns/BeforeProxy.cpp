// BeforeProxy.cpp

#include <iostream>

using std::cout;
using std::cin;

class Image
{
public:
	Image()
	{
		nId_ = nCnt_++;
		cout << "Constructing Image " << nId_ << '\n';
	}
	~Image()
	{
		cout << "Destructing Image " << nId_ << '\n';
	}
	void draw() { cout << "Rendering image " << nId_ << '\n'; }
private:
	int nId_;
	static int nCnt_;
};

int Image::nCnt_ = 1;

int main()
{
	Image images[3];
	int nChoice;

	while (true)
	{
		cout << "(1)Image1\n(2)Image2\n(3)Image3\n(0)Exit\n";
		cout << "Enter your choice" << '\n';
		cin >> nChoice;
		if (nChoice == 0) break;
		images[nChoice-1].draw();
	}
	return(0);
}