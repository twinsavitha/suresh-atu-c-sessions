// Proxy.cpp

#include <iostream>

using std::cout;
using std::cin;

class RealImage
{
public:
	RealImage(int nIndex)
	{
		nImageId_ = nIndex;
		cout << "Constructing image " << nImageId_ << '\n';
	}
	~RealImage() { cout << "Destructing image " << nImageId_ << '\n'; }
	void draw() { cout << "Rendering image " << nImageId_ << '\n'; }
private:
	int nImageId_;
};

class Image
{
public:
	Image() { nId_ = nCnt_++; pRealImage_ = 0; }
	~Image() { delete pRealImage_; }
	void draw()
	{
		if (!pRealImage_) 
			pRealImage_ = new RealImage(nId_);
		pRealImage_->draw();
	}
private:
	int nId_;
	static int nCnt_;
	RealImage *pRealImage_;
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