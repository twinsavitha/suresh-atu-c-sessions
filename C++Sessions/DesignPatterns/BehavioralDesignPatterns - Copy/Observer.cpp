// Observer.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;

class Observer
{
public:
	virtual void update(int stockIndexVal) = 0;
};

// Subject
class StockMarketIndex
{
public:
	void setIndex(int indexVal) { stockIndex_ = indexVal; notify(); }
	void registerObs(Observer *pObs) { vecObs.push_back(pObs); }
	void deRegisterObs(Observer *pObs)
	{
		for (int nIdx = 0; nIdx < vecObs.size(); nIdx++)
		{
			if (vecObs[nIdx] == pObs)
			{
				vecObs.erase(vecObs.begin()+nIdx);
			}
		}
	}
	void notify()
	{
		for (int nIdx = 0; nIdx < vecObs.size(); nIdx++)
		{
			vecObs[nIdx]->update(stockIndex_);
		}
	}
private:
	int stockIndex_;
	vector<Observer*> vecObs;
};

class GoldTraders : public Observer
{
public:
	GoldTraders(StockMarketIndex *pStocMkt)
	{
		pStocMkt_ = pStocMkt;
		pStocMkt_->registerObs(this);
	}
	~GoldTraders()
	{
		pStocMkt_->deRegisterObs(this);
		delete pStocMkt_;
	}
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
private:
	StockMarketIndex *pStocMkt_;
};

class SilverTraders : public Observer
{
public:
	SilverTraders(StockMarketIndex *pStocMkt)
	{
		pStocMkt_ = pStocMkt;
		pStocMkt_->registerObs(this);
	}
	~SilverTraders()
	{
		pStocMkt_->deRegisterObs(this);
		delete pStocMkt_;
	}
	void update(int stockIndexVal)
	{
		if (stockIndexVal > 10000)
		{
			cout << "Get high returns on your silverware.\n";
		}
		else cout << "Buy silverware at very reasonable price.\n";
	}
private:
	StockMarketIndex *pStocMkt_;
};

int main()
{
	StockMarketIndex stocMktObj;
	GoldTraders goldTraderObj(&stocMktObj);
	SilverTraders silverTraderObj(&stocMktObj);


	stocMktObj.setIndex(9000);
	stocMktObj.setIndex(11000);
	stocMktObj.setIndex(13000);
	stocMktObj.setIndex(15000);
	return(0);
}
