// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

using namespace std;
// función que resuelve el problema
bool resolver(vector<int> datos,int pos) {
    if (pos == datos.size() - 1)return true;
    int maxIzq = datos.at(0);
    int minDer = datos.at(pos+1);

    for (int i = 0; i <= pos; i++)
    {
        if (datos.at(i) > maxIzq)maxIzq = datos.at(i);
    }
    for (int i = pos+1; i < datos.size(); i++)
    {
        if (datos.at(i) < minDer)minDer = datos.at(i);
    }
    return maxIzq < minDer;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    vector<int>v;
    int pos;
    int cant;
    cin >> cant >> pos;
    for (size_t i = 0; i < cant; i++)
    {
        int dato;
        cin >> dato;
        v.push_back(dato);
    }

    if (resolver(v,pos))cout << "SI" << endl;
    else cout << "NO" << endl;
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