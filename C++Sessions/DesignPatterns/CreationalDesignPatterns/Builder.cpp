// Builder.cpp

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

// "Product"
class CSnacks
{
public:
	void setBurger(const string &strBurger) { burger_ = strBurger; }
	void setDrink(const string &strDrink) { drink_ = strDrink; }
	void setToy(const string &strToy) { toy_ = strToy; }
	void eatSnacks() const
	{
		cout << "Snacks with " << burger_ << " burger, " << drink_ << " and " << toy_ << " is ready.\n"; 
	}
private:
	string burger_;
	string drink_;
	string toy_;
};

// "Abstract Builder"
class CSnacksBuilder
{
public:
	CSnacks* getSnack() { return(pSnack); }
	void createNewSnack() { pSnack = new CSnacks; }
	virtual void buildBurger() = 0;
	virtual void buildDrink() = 0;
	virtual void buildToy() = 0;
protected:
	CSnacks *pSnack;
};

class CItalianSnacksBuilder : public CSnacksBuilder
{
public:
	void buildBurger() { pSnack->setBurger("Italian"); }
	void buildDrink() { pSnack->setDrink("Thums up"); }
	void buildToy() { pSnack->setToy("Car"); }
};

class CSpanishSnacksBuilder : public CSnacksBuilder
{
public:
	void buildBurger() { pSnack->setBurger("Spanish"); }
	void buildDrink() { pSnack->setDrink("Frooti"); }
	void buildToy() { pSnack->setToy("Bike"); }
};

class CChef
{
public:
	void setSnackBuilder(CSnacksBuilder *pSB) { pSnackBuilder_ = pSB; }
	void prepareSnack()
	{
		pSnackBuilder_->createNewSnack();
		pSnackBuilder_->buildBurger();
		pSnackBuilder_->buildDrink();
		pSnackBuilder_->buildToy();
	}
	CSnacks* getSnack() { return(pSnackBuilder_->getSnack()); }
private:
	CSnacksBuilder* pSnackBuilder_;
};


// Client
int main()
{
	CChef chef;

	CSnacksBuilder* pItalianSnackBuilder = new CItalianSnacksBuilder;
	chef.setSnackBuilder(pItalianSnackBuilder);
	chef.prepareSnack();
	CSnacks* pItalianSnack = chef.getSnack();
	pItalianSnack->eatSnacks();

	CSnacksBuilder* pSpanishSnackBuilder = new CSpanishSnacksBuilder;
	chef.setSnackBuilder(pSpanishSnackBuilder);
	chef.prepareSnack();
	CSnacks* pSpanishSnack = chef.getSnack();
	pSpanishSnack->eatSnacks();

	return(0);
}
