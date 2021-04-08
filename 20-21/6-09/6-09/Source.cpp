// Agustín Moure Rodríguez
// V41

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Arbin.h"

using namespace std;
//funcion auxiliar
void Test(int raiz, int vMax, int vMin) {

}
// función que resuelve el problema
Arbin<int> resolver(int raiz, bool& ordenado,int max,int min) {
	int hijo;
	Arbin<int> arbol;
	Arbin<int> hIzquierdo;
	Arbin<int> hDerecho;
	cin >> hijo;
	if (hijo == -1) {
		hIzquierdo = Arbin<int>();
	}
	else {
		if (ordenado) 
			ordenado = hijo < raiz&&hijo<max&&hijo>min;
		hIzquierdo = resolver(hijo, ordenado,raiz,min);
	}
	cin >> hijo;
	if (hijo == -1) {
		hDerecho = Arbin<int>();
	}
	else {
		if (ordenado)
			ordenado = hijo > raiz&&hijo>min&&hijo<max;
		
		hDerecho = resolver(hijo, ordenado,max,raiz);
	
	}
	arbol = Arbin<int>(hIzquierdo, raiz, hDerecho);
	return arbol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int raiz;
	cin >> raiz;
	if (raiz == -1)
		cout << "SI" << endl;
	else
	{
		bool ordenado = true;
		Arbin<int> arbol = resolver(raiz, ordenado,  2147483647,-1);
		if (ordenado)
			cout << "SI" << endl;
		else
			cout << "NO" << endl;
	}
	// escribir sol


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