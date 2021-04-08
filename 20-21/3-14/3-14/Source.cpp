// Agustín Moure Rodríguez
// V41
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
struct canciones {
public: int duracion;
public: int valor;
};
istream& operator >> (istream& i, canciones& p)
{
	i >> p.duracion >> p.valor;
	i.ignore();
	return i;
}
// función que resuelve el problema
void resolver(const vector<canciones>& datos, int maxT, int& solAct,int valActual,int caraA, int caraB,int i) {
	caraA += datos[i].duracion;
	valActual += datos[i].valor;
	if (caraA <= maxT) {
		if (i == datos.size() - 1) {
			if (valActual > solAct)solAct = valActual;
		}
		else
		{
			resolver(datos, maxT, solAct, valActual, caraA, caraB, i + 1);
		}
	}
	caraA -= datos[i].duracion;
	caraB += datos[i].duracion;
	if (caraB <= maxT) {
		if (i == datos.size() - 1) {
			if (valActual > solAct)solAct = valActual;
		}
		else
		{
			resolver(datos, maxT, solAct, valActual, caraA, caraB, i + 1);
		}
	}

	caraB -= datos[i].duracion;
	valActual -= datos[i].valor;

	if (i == datos.size() - 1) {
		if (valActual > solAct)solAct = valActual;
	}
	else
	{
		resolver(datos, maxT, solAct, valActual, caraA, caraB, i + 1);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
		// leer los datos de la entrada
	int dato;
	cin >> dato;
	if (dato == 0)
		return false;
	int maxTiePos;
	cin >> maxTiePos;
	vector<canciones> datos;
	for (int i = 0; i < dato; i++) {
		canciones c;
		cin >> c;
		datos.push_back(c);
	}

	int sol = 0, tActual = 0;
	resolver(datos, maxTiePos, sol, 0,0,0,0);

	// escribir sol
	cout << sol << endl;
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
