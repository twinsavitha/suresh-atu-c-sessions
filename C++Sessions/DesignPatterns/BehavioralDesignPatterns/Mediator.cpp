// Mediator.cpp

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;

class Node
{
public:
	Node(int val) { nValue_ = val; }
	int getValue() { return(nValue_); }
private:
	int nValue_;
};

// Mediator
class List
{
public:
	void addNode(Node *pNode) { nodeList_.push_back(pNode); }
	void traverse()
	{
		for (int nIdx = 0; nIdx < nodeList_.size(); nIdx++)
		{
			cout << nodeList_[nIdx]->getValue() << " ";
		}
		cout << "\n";
	}
	void removeNode(int val)
	{
		for (vector<Node*>::iterator iter = nodeList_.begin();
			 iter != nodeList_.end(); iter++)
		{
			if ((*iter)->getValue() == val)
			{
				nodeList_.erase(iter); break;
			}
		}
	}
private:
	vector<Node*> nodeList_;
};

int main()
{
	List nodeList;
	Node n1(13);
	Node n2(23);
	Node n3(33);
	Node n4(43);

	nodeList.addNode(&n1);
	nodeList.addNode(&n2);
	nodeList.addNode(&n3);
	nodeList.addNode(&n4);

	nodeList.traverse();
	nodeList.removeNode(43);
	nodeList.traverse();
	nodeList.removeNode(13);
	nodeList.traverse();

	return(0);
}

