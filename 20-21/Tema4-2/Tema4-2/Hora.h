#pragma once
class Hora
{
private:
	int hora = -5;
	int min = -5;
	int seg = -5;
	bool correcta;
public:
	Hora(int hora = 0, int min = 0, int sec = 0);
	int GetHora()const;
	int GetSec()const;
	int GetMin()const;
	bool GetCorrect() const;
	friend bool operator <(const Hora& p1, const Hora& p2);
	friend bool operator >(const Hora& p1, const Hora& p2);
	friend Hora operator +(const Hora& p1, const Hora& p2);
};

