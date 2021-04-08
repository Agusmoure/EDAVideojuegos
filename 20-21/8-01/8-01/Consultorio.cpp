#include "Consultorio.h"
using namespace std;
void Consultorio::nuevoMedico(Medico m) {
	plantilla.insert({ m, map<Fecha, Paciente>() });
}
void Consultorio::pideConsulta(Paciente p, Medico m, Fecha f) {
	auto it = plantilla.find(m);
	if (it == plantilla.cend())
		throw invalid_argument("Medico no existente");
	else {
		auto it2 = it->second.find(f);
		if (it2 == it->second.end())
			it->second.insert({ f, p });
		else 
			throw invalid_argument("Fecha ocupada");
	}
}
Paciente Consultorio::siguientePaciente(Medico m) {
	auto it = plantilla.find(m);
	if (it == plantilla.cend())
		throw invalid_argument("Medico no existente");
	else {
		if (!it->second.empty()) {
			auto it2 = it->second.begin();
			Paciente p = it2->second;

			return p;
		}
		else throw invalid_argument("No hay pacientes");
	}
}
void  Consultorio::atiendeConsulta(Medico m) {
	auto it = plantilla.find(m);
	if (it == plantilla.cend())
		return;
	else {
		if (!it->second.empty())
			it->second.erase(it->second.begin()->first);
		else
			throw invalid_argument("No hay pacientes");
	}
}
list<string>  Consultorio::listaPacientes(Medico m, int dia) {
	list<string> pacientes;
	string p;
	auto it = plantilla.find(m);
	if (it == plantilla.end())
		throw invalid_argument("Medico no existente");
	else
	{

		auto it2 = it->second.begin();
		while (it2 != it->second.end()) {
			Fecha f = it2->first;
			if (f.GetDia() == dia) {
				p = it2->second + " " + string(2 - to_string(f.GetHora()).length(), '0').append(to_string(f.GetHora())) + ":" + string(2 - to_string(f.GetMin()).length(), '0').append(to_string(f.GetMin()));
				pacientes.push_back(p);
			}
			++it2;
		}
		return pacientes;
	}
}