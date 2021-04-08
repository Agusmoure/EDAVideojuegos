#pragma once
class Time
{
private:
	int hora=-5;
	int min=-5;
	int seg=-5;
	bool correcta;
public:
	Time(int hora=0,int min=0,int sec=0);
	int GetHora()const;
	int GetSec()const;
	 int GetMin()const;
	 bool GetCorrect() const;
	 friend bool operator <(const Time& p1, const Time& p2);
	 friend bool operator >(const Time& p1, const Time& p2);
};

