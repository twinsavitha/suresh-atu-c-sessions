// Bridge.cpp

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Implementation hierarchy

class TimeImp
{
public:
	TimeImp(int hr, int min): hr_(hr), min_(min) {}
	virtual void showTime() { cout << "Hour: " << hr_ << "  Minutes: " << min_ << endl; }
protected:
	int hr_, min_;
};

enum hrSystem{ TwelveHr = 12, TwentyFourHr = 24 };
class TwelveHrTimeImp : public TimeImp
{
public:
	TwelveHrTimeImp(int hr, int min, hrSystem meridian)
		: TimeImp(hr, min)
	{
		if (meridian == TwelveHr)
		{
			if (hr_ > 12)
			{
				hr_ -= 12;
				strcpy(strMeridian_, " pm");
			}
			else { strcpy(strMeridian_, " am"); }
		}
		else
			strcpy(strMeridian_, "");
	}
	void showTime() { cout << "Hour: " << hr_ << "  Minutes: " << min_ << strMeridian_ << endl; }
private:
	char strMeridian_[4];
};

enum TimeZones{EST = -5, GMT = 0, RST = 4, IST = 5};
class ZonalTimeImp : public TimeImp
{
public:
	ZonalTimeImp(int hr, int min, TimeZones timeZone)
		: TimeImp(hr, min)
	{
		if (timeZone == -5)    { strcpy(strTimeZone_, " Eastern Standard Time"); }
		else if (timeZone == 0){ strcpy(strTimeZone_, " Greenwich Mean Time"); }
		else if (timeZone == 4){ strcpy(strTimeZone_, " Russian Standard Time"); }
		else if (timeZone == 5){ strcpy(strTimeZone_, " Indian Standard Time"); }
	}
	void showTime() { cout << "Hour: " << hr_ << "  Minutes: " << min_ << strTimeZone_ << endl; }
private:
	char strTimeZone_[30];
};

// Interface hierarchy
class Time
{
public:
	Time(){}
	Time(int hr, int min) { pTimeImp_ = new TimeImp(hr, min); }
	virtual void showTime() { pTimeImp_->showTime(); }
protected:
	TimeImp *pTimeImp_;
};

class TwelveHrTime : public Time
{
public:
	TwelveHrTime(int hr, int min, int meridian)
	{
		pTimeImp_ = new TwelveHrTimeImp(hr, min, static_cast<hrSystem>(meridian));
	}
};

class ZonalTime : public Time
{
public:
	ZonalTime(int hr, int min, int zone)
	{
		pTimeImp_ = new ZonalTimeImp(hr, min, static_cast<TimeZones>(zone));
	}
};

// Client
int main()
{
	Time *pTimes[3];
	pTimes[0] = new Time(15, 45);
	pTimes[1] = new TwelveHrTime(15, 45, 12);
	pTimes[2] = new ZonalTime(15, 45, 5);

	for (int nIdx = 0; nIdx < 3; nIdx++)
	{
		pTimes[nIdx]->showTime();
	}
	return(0);
}