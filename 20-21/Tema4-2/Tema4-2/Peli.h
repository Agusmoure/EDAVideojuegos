#include "Hora.h";
#include <string>
class Peli
{
private:
	Hora hora;
	Hora duracion;
	Hora horaFinal;
	std::string titulo;
public:
	Peli() {};
	Peli(Hora h,Hora d,std::string tit);
	Hora GetHora()const;
	Hora GetDuracion()const;
	Hora GetFinal()const;
	std::string GetTitulo()const;
	friend bool operator <(const Peli& p1, const Peli& p2);
	friend bool operator >(const Peli& p1, const Peli& p2);
};

