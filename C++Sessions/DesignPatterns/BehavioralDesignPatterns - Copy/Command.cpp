// Command.cpp

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;

enum PhotoType { PASSPORT, CARD, LIFESIZE };

class Photo
{
public:
	Photo(PhotoType type) : photoType_(type) {}
	string getType()
	{
		if 		(photoType_ == 0) return(string("Passport"));
		else if (photoType_ == 1) return(string("Card"));
		else 					  return(string("LifeSize"));
	}
	void glossy() { cout << "Making " << getType() << " photo with glossy finish.\n"; }
	void matt()   { cout << "Making " << getType() << " photo with matt finish.\n"; }
	void crystal(){ cout << "Making " << getType() << " photo with crystal finish.\n"; }
private:
	PhotoType photoType_;
};

class Command
{
public:
	typedef void (Photo:: *finish)();
	Command(Photo *foto, finish finishType)
	{
		pFoto_ = foto;
		finishingType_ = finishType;
	}
	void execute() { (pFoto_->*finishingType_)(); }
private:
	Photo *pFoto_;
	finish finishingType_;
};

// Client
int main()
{
	Photo image1(PASSPORT);
	Photo image2(CARD);
	Photo image3(LIFESIZE);

	Command cmdObj1(&image1, &Photo::glossy);
	Command cmdObj2(&image1, &Photo::matt);
	cmdObj1.execute();
	cmdObj2.execute();

	Command cmdObj3(&image2, &Photo::matt);
	cmdObj3.execute();

	Command cmdObj4(&image3, &Photo::crystal);
	cmdObj4.execute();
	return(0);
}
