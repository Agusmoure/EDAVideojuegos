// Agustín Moure Rodríguez
// V41

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Arbin.h"

using namespace std;

// función que resuelve el problema
Arbin<char> resolver(char raiz) {
    char hijo;
    Arbin<char> arbol;
    Arbin<char> hIzquierdo;
    Arbin<char> hDerecho;
    cin >> hijo;
    if (hijo == '.') {
        hIzquierdo = Arbin<char>();
    }
    else {
        hIzquierdo = resolver(hijo);
    }
    cin >> hijo;
    if (hijo == '.') {
        hDerecho = Arbin<char>();
    }
    else {
        hDerecho = resolver(hijo);
    }
    arbol = Arbin<char>(hIzquierdo, raiz, hDerecho);
    return arbol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    char raiz;
    cin >> raiz;
    if (raiz == '.')
        cout << "0 0 0" << endl;
    else
    {
      Arbin<char> arbol=resolver('*');
      cout << arbol.numNodos() << " " << arbol.numHojas() << " " << arbol.talla() << endl;
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