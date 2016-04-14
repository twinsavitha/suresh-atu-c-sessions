// Iterator.cpp

#include <iostream>
using std::cout;
using std::cin;

const int MAX_SIZE = 10;

class StackIter;

class Stack
{
public:
	Stack() { top_ = -1; }
	void push(int val) { elements_[++top_] = val; }
	int pop() { return(elements_[top_--]); }
	bool isEmpty() { return(top_ == -1); }

	friend class StackIter;
	StackIter* createIter() const;

private:
	int elements_[MAX_SIZE];
	int top_;
};

class StackIter
{
public:
	StackIter(const Stack* pStac) { pStack_ = pStac; }
	void begin() { nIndex_ = 0; }
	bool isEnd() { return(nIndex_ == pStack_->top_ + 1); }
	void next() { nIndex_++; }
	int currentElem() { return(pStack_->elements_[nIndex_]); }

private:
	int nIndex_;
	const Stack *pStack_;
};

StackIter* Stack::createIter() const { return(new StackIter(this)); }


int main()
{
	Stack stac1, stac2;
	for (int nIdx = 1; nIdx < 6; nIdx++)
	{
		stac1.push(nIdx); stac2.push(nIdx);
	}

	// Compare stac1 and stac2
	StackIter* stacIter1 = stac1.createIter();
	StackIter* stacIter2 = stac2.createIter();

	for (stacIter1->begin(), stacIter2->begin();
		 !stacIter1->isEnd();
		 stacIter1->next(), stacIter2->next())
	{
		if (stacIter1->currentElem() != stacIter2->currentElem())
			break;
	}
	if (stacIter1->isEnd() && stacIter2->isEnd())
	{
		cout << "Stacks are same.\n";
	}
	else cout << "Stacks are different.\n";


	// Compare stac1 and stac3
	Stack stac3(stac1);
	stac3.pop();
	StackIter* stacIter3 = stac3.createIter();

	for (stacIter1->begin(), stacIter3->begin();
		 !stacIter1->isEnd();
		 stacIter1->next(), stacIter3->next())
	{
		if (stacIter1->currentElem() != stacIter3->currentElem())
			break;
	}
	if (stacIter1->isEnd() && stacIter3->isEnd())
	{
		cout << "Stacks are same.\n";
	}
	else cout << "Stacks are different.\n";

	delete stacIter1;
	delete stacIter2;
	delete stacIter3;

	return(0);
}

