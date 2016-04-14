// Demonstrating the member templates
#include <iostream>
using std::cout;
using std::endl;

template <typename U>
class Queue
{
public:
	//function member template
	template <typename Iter>
	void assign(Iter first, Iter last)
	{
		while (!isEmpty())
		{
			remove(); // calls Queue<T>::remove()
		}
		for (; first != last; ++first)
		{
			add(*first); // calls Queue<T>::add(const T &)
		}
	}
private:
	//class member template
	template <typename V>
	class QueueItem
	{
		V flagOnOff; // V could be instantiated with a boolean
		T value;
	};
};
