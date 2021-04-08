// Agustín Moure Rodríguez
// V41

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Header.h"

using namespace std;

// función que resuelve el problema
void resolver(List<int>& datos,int& elem) {
    datos.eliminaElementoRepe(elem);

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int dato;
    cin >> dato;
    List<int> list =List<int>();
    while (dato!=-1)
    {
        list.push_back(dato);
        cin >> dato;
    }
    int repe;
    cin >> repe;
    int i = 0;
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        if(i<list.size()){
        cout << it.elem() + " ";
        }
        else {

            cout << it.elem() <<endl;
        }
        i++;
    }
    resolver(list,repe);
    // escribir sol
    i = 0;
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        if (i < list.size()) {
            cout << it.elem() + " ";
        }
        else {

            cout << it.elem() << endl;
        }
        i++;
    }
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    cout << "HOLA";
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