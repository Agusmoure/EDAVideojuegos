#include <set>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

// función que resuelve el problema
vector<int> resolver(int datos) {
    set<int> set;
    vector<int>v;
    //Guardamos el primer dato
    v.push_back(datos);
    set.insert(datos);
    int actual=datos;
    int valor=0;
    bool flag = false;
    if (datos == 1)v.push_back(1);
    else {

    do {
        //obtenemos el valor
    do {
        valor += pow(actual % 10, 2);
        actual /= 10;
    } while (actual>0);
    v.push_back(valor);
    if (valor == 1 || valor == 0) {
        flag = true;
        v.push_back(valor);
    }
    else {
        auto it = set.find(valor);
        if (it != set.end()) {
            flag = true;
            v.push_back(0);
        }
        else {
            set.insert(valor);
        }
        actual = valor;
        valor = 0;
    }
    } while (!flag);

    }
    return v;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int dato;
    cin >> dato;
    if (!std::cin)
        return false;

    vector<int> sol = resolver(dato);

    // escribir sol
    for (size_t i = 0; i < sol.size(); i++)
    {
        cout << sol.at(i);
        if (i != sol.size() - 1)
            cout << " ";
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