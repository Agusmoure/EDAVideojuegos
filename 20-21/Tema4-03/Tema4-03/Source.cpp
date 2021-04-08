// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Polinomio.h"

using namespace std;
ostream& operator << (ostream& o, const Monomio& t)
{
	return o;
}

istream& operator >> (istream& i, Monomio& p)
{
	int e, c;
	i >> c >> e;
	p = Monomio(e, c);
	i.ignore();
	return i;

}
// función que resuelve el problema
vector<int> resolver(Polinomio datos, vector<int> d) {
	vector<int> v;
	for (size_t i = 0; i < d.size(); i++)
	{
		int s;
		s = datos.GetValor(d.at(i));
		v.push_back(s);
	}
	return v;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	Polinomio p;
	Monomio m;
	do {
		cin >> m;
		if (!std::cin)
			return false;
		if (!m.Falla())p.AgregarMonomio(m);
	} while (!m.Falla());
	int casos;
	cin >> casos;
	vector<int>v;
	for (size_t i = 0; i < casos; i++)
	{
		int d;
		cin >> d;
		v.push_back(d);
	}
	vector<int> sol = resolver(p, v);
	// escribir sol
	for (size_t i = 0; i < sol.size(); i++)
	{
		cout << sol.at(i);
		if (i != sol.size() - 1) cout << " ";
		else
		{
			cout << endl;
		}
	}

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}