#include "Hora.h"
#include <iostream>
using namespace std;
Hora::Hora(int hor, int mi, int se) {
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

int Hora::GetHora()const {
	return hora;
}
int Hora::GetMin() const {
	return min;
}
int Hora::GetSec() const {
	return seg;
}
bool Hora::GetCorrect() const {
	return correcta;
}

bool operator <(const Hora& p1, const Hora& p2) {
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
bool operator >(const Hora& p1, const Hora& p2) {
	return p2 < p1;
}
Hora operator +(const Hora& p1, const Hora& p2)
{
	Hora t;
	int hE, mE;
	int h, m, s;
	mE = (p1.GetSec() + p2.GetSec()) / 60;
	s = (p1.GetSec() + p2.GetSec()) % 60;
	m = (p1.GetMin() + p2.GetMin()+mE) % 60;
	hE = (p1.GetMin() + p2.GetMin()+mE) / 60;
	h = (p1.GetHora() + p2.GetHora())+hE;
	t = Hora(h,m,s);
	return t ;
}
