// Agustín Moure Rodríguez
// V41

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Queue.h"

using namespace std;

// función que resuelve el problema
template<class T>
void resolver(Queue<T>& datos, Queue<T>&datos2, T pringado) {
	datos.insert(datos2, pringado);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	Queue<int>cola;
	int dato;
	cin >> dato;
	while (dato != -1) {
		cola.push_back(dato);
		cin >> dato;
	}
	int pringado;
	cin >> pringado;
	Queue<int>colaAmigos;
	cin >> dato;
	while (dato != -1) {
		colaAmigos.push_back(dato);
		cin >> dato;
	}
	cola.write(cout);
	cout << endl;

	resolver(cola, colaAmigos, pringado);
	// escribir sol
	cola.write(cout);
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
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}