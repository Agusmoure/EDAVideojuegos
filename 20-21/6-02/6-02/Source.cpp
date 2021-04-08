﻿// Agustín Moure Rodríguez
// V41

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Arbin.h"
using namespace std;



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    Arbin<int> arbol;
    arbol = arbol.readTree(-1);
    vector<int>sol = arbol.Fronteras();
    // escribir sol
    if (sol.empty())cout << endl;
    for (size_t i = 0; i < sol.size(); i++)
    {
        if(i==sol.size()-1)
        cout << sol.at(i)<<endl;
        else
        {
            cout << sol.at(i) << " ";
        }
        
    }

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