// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
vector<int> resolver(vector<int> datos1, vector<int> datos2) {
	int menorDato1; int menorDato2;
	bool datos1Acabado = true;
	bool datos2Acabado = true;
	if (!datos1.empty()) {
		menorDato1 = datos1.at(0);
		datos1Acabado = false;
	}
	if (!datos2.empty()) {
		datos2Acabado = false;
		menorDato2 = datos2.at(0);
	}
	int pos1 = 0;
	int pos2 = 0;
	vector<int> v;
	while (!datos1Acabado && !datos2Acabado)
	{
		if (menorDato1 < menorDato2) {
			v.push_back(menorDato1);
			pos1++;
			if (pos1 < datos1.size())
					menorDato1 = datos1.at(pos1);
				else
					datos1Acabado = true;
		}
		else if (menorDato1 == menorDato2) {
			pos1++;
			pos2++;
			v.push_back(menorDato1);
			if (pos1 < datos1.size())
				menorDato1 = datos1.at(pos1);
			else
				datos1Acabado = true;
			if (pos2 < datos2.size())
				menorDato2 = datos2.at(pos2);
			else
				datos2Acabado = true;
		}
		else
		{
			pos2++;
			v.push_back(menorDato2);
			if (pos2 < datos2.size())
				menorDato2 = datos2.at(pos2);
			else
				datos2Acabado = true;
		}
	}
	if (!datos1Acabado) {
		for (size_t i = pos1; i < datos1.size(); i++)
		{
			v.push_back(datos1.at(i));
		}
	}
	if (!datos2Acabado) {
		for (size_t i = pos2; i < datos2.size(); i++)
		{
			v.push_back(datos2.at(i));
		}
	}
	return v;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	size_t l1, l2;
	cin >> l1;
	cin >> l2;
	vector<int> v1, v2;
	for (size_t i = 0; i < l1; i++)
	{
		int n;
		cin >> n;
		v1.push_back(n);
	}
	for (size_t i = 0; i < l2; i++)
	{
		int n;
		cin >> n;
		v2.push_back(n);
	}
	vector<int> sol = resolver(v1, v2);
	// escribir sol

	for (size_t i = 0; i < sol.size(); i++)
	{
		cout << sol.at(i) << " ";
	}
	cout << endl;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}