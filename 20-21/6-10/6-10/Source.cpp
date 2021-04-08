// Agustín Moure Rodríguez
// V41

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbin.h"

using namespace std;

// función que resuelve el problema
//TipoSolucion resolver(TipoDatos datos) {
//
//
//}
Arbin<int> LeerArbol() {
    int raiz;
    cin >> raiz;
    if (raiz == -1)
        return Arbin<int>();
    Arbin<int>hIz = LeerArbol();
    Arbin<int>hDe = LeerArbol();
    return Arbin<int>(hIz, raiz, hDe);
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    Arbin<int>t = LeerArbol();

    //TipoSolucion sol = resolver(datos);
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