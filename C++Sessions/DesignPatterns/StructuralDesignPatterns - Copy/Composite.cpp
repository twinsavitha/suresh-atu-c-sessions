// Composite.cpp

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Iterate
{
public:
    virtual void traverse() = 0;
};

class Node : public Iterate
{
public:
	Node(int val) : nValue_(val) {}
	void traverse() { cout << nValue_ << ' '; }
private:
	int nValue_;
};

class Collection : public Iterate
{
public:
	void add(Iterate *element) { elements_.push_back(element); }
	void traverse()
	{
		for (int nIdx = 0; nIdx < elements_.size(); nIdx++)
		{
			elements_[nIdx]->traverse();
		}
	}
private:
	vector<Iterate *> elements_;
};

int main()
{
	Node *pNode1 = new Node(1);
	Node *pNode2 = new Node(2);
	Node *pNode3 = new Node(3);

	Collection subContainer;
	Node *pNode4 = new Node(4);
	Node *pNode5 = new Node(5);
	Node *pNode6 = new Node(6);

	subContainer.add(pNode4);
	subContainer.add(pNode5);
	subContainer.add(pNode6);

	Collection finalCollection;
	finalCollection.add(pNode1);
	finalCollection.add(pNode2);
	finalCollection.add(pNode3);
	finalCollection.add(&subContainer);

	finalCollection.traverse();

	return(0);
}