#pragma once
class Fecha
{
public:
	Fecha() {};
	Fecha(int d, int h, int m) {
		dia = d;
		hora = h;
		min = m;
	};
	~Fecha()
	{
	};
	int GetDia() {
		return dia;
	};
	int GetHora() {
		return hora;
	};
	int GetMin() {
		return min;
	};
	bool operator<(const Fecha& date) const {
		return (dia < date.dia ||
			(dia == date.dia && (hora < date.hora || (hora == date.hora && min < date.min))));
	};
private:
	int dia=0;
	int min=0;
	int hora=0;
};
