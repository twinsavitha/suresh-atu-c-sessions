// Demonstrating the friend declarations in class templates
#include <iostream>
using std::cout;
using std::endl;

// Forward declarations
template <typename T>
class CMakeFriends;

// template friend function and friend class 
template <typename T>
void friendFunc(CMakeFriends<T>);
template <typename T>
class CFriendClass;

template<typename T>
class CMakeFriends
{
	friend void friendFunc<>(CMakeFriends<T>);
	friend class CFriendClass<T>;
private:
	void fnSecret()
	{
		cout << "A secret function in the class.\n";	
	}
};

// Template friend function and friend class
template <typename T>
void friendFunc(CMakeFriends<T> friendsObj)
{
	cout << "A friend in need is a friend in deed.\n";
	friendsObj.fnSecret();
}

template <typename T>
class CFriendClass
{
public:
	CFriendClass(T value):tValue_(value) {}
	void displayMsg()
	{
		cout << "Friend class templatized to " << tValue_ << endl;
		cout << "This is a friendly class.\n";
		CMakeFriends<int> makeFriendsObj;
		makeFriendsObj.fnSecret();
	}
private:
	T tValue_;
};


int main()
{
	CMakeFriends<int> friendObj;
	friendFunc(friendObj);
	CFriendClass<int> friendObject(5);
	friendObject.displayMsg();
	return(0);
}
