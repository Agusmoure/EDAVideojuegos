// Agustín Moure Rodríguez
// V41

#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include"Set.h"

using namespace std;


// función que resuelve el problema
template<class T>
T AniadeDato(Set<T>& datos,T dato) {// O(nlog(k)) siendo n=datos.size
	if (!datos.contains(dato))//log(k)
	{
		if (dato > datos.getMin()) {//O(1)
			datos.add(dato);//O(n) siendo n=datos.size
			datos.removeMin();//O(n) siendo n=datos.size
		}
	}
	return dato;
}

void resolver(Set<int>& datos, int cant) {//O(k*n*log(k))
	int dato = 0;
	while (datos.Size() < cant) {

		cin >> dato;
		if(!datos.contains(dato)) //log(k)
		datos.add(dato);//O(k)
	} 
	
	while (dato != -1)
	{
		cin >> dato;
		if(dato!=-1)AniadeDato(datos,dato);//O(k*log(k))
	}
}
void resolver(Set<string>& datos, int cant) {//O(n*k*log(k))
	string dato = "";
	while (datos.Size() < cant) {
		cin >> dato;
		if (!datos.contains(dato))//log(k)
			datos.add(dato);//O(k)
	}
	while (dato != "FIN")
	{
		cin >> dato;
		if (dato != "FIN") AniadeDato(datos,dato);//O(k*log(k))
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	char d;
	cin >> d;
	if (!std::cin)
		return false;
	int cant;
	cin >> cant;
	if (d == 'N') {
		Set<int> sol;
		resolver(sol, cant);
		cout << sol << endl;
	}
	else
	{
		if (d == 'P') {
			Set<string> sol;
			resolver(sol, cant);
			cout << sol << endl;
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
	/*
	4) Se podría en lugar de ordenar de menor a mayor ordenar de mayor a menor pasando a ser el elemento elem[size-1] el menor de todosy pudiedo hacer void removeMin(){size--;} 
	claro que eso conllevaría que el removeMax ya no es de coste constante.
	No es posible tener ambos remove en complejidad constante sin incrementar la complejidad de otras funciones y sin reducir la cantidad maxima de elementos
	*/

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}