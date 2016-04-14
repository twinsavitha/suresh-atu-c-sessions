// BeforeObserver.cpp

#include <iostream>
using std::cout;
using std::endl;

class GoldTraders
{
public:
	void update(int stockIndexVal)
	{
		if (stockIndexVal > 12000 && stockIndexVal < 14000)
		{
			cout << "Exchange your ornaments before the prices increase.\n";
		}
		else if (stockIndexVal > 14000)
		{
			cout << "Avail quick loans on gold at a competitive rate.\n";
		}
	}
};

class SilverTraders
{
public:
	void update(int stockIndexVal)
	{
		if (stockIndexVal > 10000)
		{
			cout << "Get high returns on your silverware.\n";
		}
		else cout << "Buy silverware at very reasonable price.\n";
	}
};

// Subject
class StockMarketIndex
{
public:
	StockMarketIndex() {}
	StockMarketIndex(int indexVal) : stockIndex_(indexVal) {}
	void setIndex(int indexVal) { stockIndex_ = indexVal; notify(); }
	void notify()
	{
		goldTraderObj.update(stockIndex_);
		silverTraderObj.update(stockIndex_);

	}
private:
	int stockIndex_;
	GoldTraders goldTraderObj;
	SilverTraders silverTraderObj;
};

int main()
{
	StockMarketIndex stMktObj;
	stMktObj.setIndex(9000);
	stMktObj.setIndex(11000);
	stMktObj.setIndex(13000);
	stMktObj.setIndex(15000);
	return(0);
}
