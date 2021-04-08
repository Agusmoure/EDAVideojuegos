#pragma once
#include "Fecha.h"
class Accidentes
{
private:
	int fallecidos;
	Fecha fecha;
public:
	Accidentes(int fallecido=0, Fecha f=Fecha()) { fallecidos = fallecido; fecha = f; }
	int GetFallecidos()const;
	Fecha GetFecha()const;
};

