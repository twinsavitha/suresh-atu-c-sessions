// BeforeMediator.cpp

#include <iostream>
using std::cout;
using std::cin;

class Node
{
public:
	Node(int val) { nValue_ = val; pNext_ = NULL; }
	void addNode(Node *pNode)
	{
		if (pNext_) pNext_->addNode(pNode);
		else        pNext_ = pNode;
	}
	void traverse()
	{
		cout << nValue_ << " ";
		if (pNext_) pNext_->traverse();
		else cout << '\n';
	}
	void removeNode(int val)
	{
		if (pNext_)
			if (pNext_->nValue_ == val) pNext_ = pNext_->pNext_;
			else						pNext_->removeNode(val);
	}
private:
	int nValue_;
	Node *pNext_;
};

int main()
{
	Node nodeList(13);
	Node n2(23);
	Node n3(33);
	Node n4(43);

	nodeList.addNode(&n2);
	nodeList.addNode(&n3);
	nodeList.addNode(&n4);

	nodeList.traverse();
	nodeList.removeNode(43);
	nodeList.traverse();

	nodeList.removeNode(13); // This node cannot be deleted as it is the object communicating with others.
	nodeList.traverse();
	return(0);
}
