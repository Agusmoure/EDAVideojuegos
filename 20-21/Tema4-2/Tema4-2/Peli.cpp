#include "Peli.h"
using namespace  std;
Peli::Peli(Hora h, Hora d, std::string tit) {
	hora = h;
	duracion = d;
	titulo = tit;
	horaFinal = h + d;
}
Hora Peli::  GetHora()const {
	return hora;
}
Hora Peli:: GetDuracion()const {
	return duracion;
}
Hora Peli:: GetFinal()const {
	return horaFinal;
}
string Peli:: GetTitulo()const {
	return titulo;
}

bool operator <(const Peli& p1, const Peli& p2) {
	if (p1.GetFinal() < p2.GetFinal())return true;
	else {
		if (p1.GetFinal() > p2.GetFinal()) return false;
		else {
			if (p1.GetTitulo().compare(p2.GetTitulo()) <= 0)return true;
			return false;
		}
	}
}
bool operator >(const Peli& p1, const Peli& p2) {
	return p2 < p1;
}