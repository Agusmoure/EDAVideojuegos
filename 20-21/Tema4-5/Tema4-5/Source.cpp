// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include"SetOfInts.h"
using namespace std;
// función que resuelve el problema

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int dato;
	cin >> dato;
	if (dato == 0)
		return false;
	int d;
	SetOfInts s;
	do {
		cin >> d;
		if (d != -1)s.add(d);
	} while (s.Size()<dato);
	do {
		cin >> d;
		if (d!=-1&&!s.contains(d))s.add(d);
	} while (d!=-1);
	// escribir sol
	for (int i = 0; i < dato; i++) {
		cout << s.GetMin();
		s.RemoveMin();
		if (i != dato - 1)cout << " ";
	}
	cout << endl;
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
