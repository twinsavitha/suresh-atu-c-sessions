// BeforeCommand.cpp

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

int main()
{
	Photo image1(PASSPORT);
	image1.glossy();

	Photo image2(CARD);
	image2.matt();

	Photo image3(LIFESIZE);
	image3.crystal();

	return(0);
}
