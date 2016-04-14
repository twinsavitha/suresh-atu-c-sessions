// Demonstrating the friend declarations in class templates
#include <iostream>
using std::cout;
using std::endl;

// Forward declaration of 
// Non-template friend function and friend class 
void friendFunc();
class CFriendClass;

template<typename T>
class CMakeFriends
{
	friend void friendFunc();
	friend class CFriendClass;
private:
	void fnSecret()
	{
		cout << "A secret function in the class.\n";	
	}
};

// Non-template friend function and friend class
void friendFunc()
{
	cout << "A friend in need is a friend in deed.\n";
	CMakeFriends<int> makeFriendsObj;
	makeFriendsObj.fnSecret();
}

class CFriendClass
{
public:
	void displayMsg()
	{
		cout << "This is a friendly class.\n";
		CMakeFriends<char> makeFriendsObj;
		makeFriendsObj.fnSecret();
	}
};


int main()
{
	friendFunc();
	CFriendClass friendObj;
	friendObj.displayMsg();
	return(0);
}
