#pragma once
class Fecha
{
private:
	int dia, mes, anio;
public:
	Fecha(int diaA=0, int mesA=0, int anioA=0) { dia = diaA; mes = mesA; anio = anioA; }
	int GetDia()const { return dia; }
	int GetMes()const { return mes; }
	int GetAnio()const { return anio; }
};

