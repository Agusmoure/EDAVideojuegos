#pragma once
#include <map>
#include <unordered_map>
#include "Fecha.h"
#include <stdexcept>
#include <string>
#include <list>
using namespace std;
using Medico = string;
using Paciente = string;
class Consultorio
{
private:
	unordered_map<Medico,map<Fecha,Paciente>> plantilla;
public:
	void nuevoMedico(Medico m);
	void pideConsulta(Paciente p,Medico m,Fecha f);
	Paciente siguientePaciente(Medico m);
	void atiendeConsulta(Medico m);
	list<string> listaPacientes(Medico m,int dia);
};

