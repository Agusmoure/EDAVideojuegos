#include <iostream>
#include "Time.h"
using namespace std;
Time::Time(int hor, int mi, int se) {
	if (hor <= 23 && hor >= 0 && mi <= 59 && mi >= 0 && se <= 59 && se >= 0) {

		hora = hor;
		min = mi;
		seg = se;
		correcta = true;
	}
	else
	{
		//cout << "ERROR" << endl;
		correcta = false;
	}
}

int Time::GetHora()const {
	return hora;
}
int Time::GetMin() const {
	return min;
}
int Time::GetSec() const {
	return seg;
}
bool Time::GetCorrect() const {
	return correcta;
}

bool operator <(const Time& p1, const Time& p2) {
	if (p1.GetHora() < p2.GetHora()) {

	return true;
	}
	else {
		if (p1.GetHora() > p2.GetHora()) {

			return false;
		}
		else {

		if (p1.GetMin() < p2.GetMin()) {
			return true;
		}
		else
		{
			if (p1.GetMin() > p2.GetMin()) {

				return false;
			}
			else {
				if (p1.GetSec() < p2.GetSec()) {
					return true;
				}
				return false;
			}
		}
		}
	}
}
bool operator >(const Time& p1, const Time& p2) {
	return p2 < p1;
}
//Time& operator +(const Time& p1, const Time& p2)
//{
//	Time t;
//	int hE, mE;
//	int h, m, s;
//	mE = (p1.GetSec() + p2.GetSec()) / 60;
//	hE = (p1.GetMin() + p2.GetMin()) / 60;
//	s = (p1.GetSec() + p2.GetSec()) % 60;
//	m = (p1.GetMin() + p2.GetMin()) % 60;
//	h
//	return *();
//}
