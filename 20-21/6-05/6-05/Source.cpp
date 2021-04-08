// Agustín Moure Rodríguez
// V41


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Arbin.h"

using namespace std;


// función que resuelve el problema
Arbin<int> resolver(vector<int>& pre,vector<int>&in,int inicio,int fin) {
    int raiz;
    if (!pre.empty()&&fin-inicio>=0) {
        raiz = pre[0];
        pre.erase(pre.begin());
    int i = inicio;
    while (i < fin && in[i] != raiz) {
        i++;
    };
    Arbin<int>hIzq;
    Arbin<int>hDer;
    if (fin - inicio <= 0) {
        hIzq = Arbin<int>();
        hDer = Arbin<int>();
    }
    else {
        hIzq = resolver(pre, in, inicio, i - 1);
        hDer = resolver(pre, in, i + 1, fin);
    }
    return Arbin<int>(hIzq, raiz, hDer);
    }
    return Arbin<int>();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int d;
    cin >> d;
    if (!std::cin)
        return false;
    vector<int>pre, in;
    for (int i = 0; i < d; i++) {
        int dato;
        cin >> dato;
        pre.push_back(dato);
    }
    for (int i = 0; i < d; i++) {
        int dato;
        cin >> dato;
        in.push_back(dato);
    }
    Arbin<int> sol = resolver(pre,in,0,d);

    // escribir sol
    List<int>* l=sol.postorden();
    for (int i = 0; i < l->size(); i++) {
        cout << l->at(i);
        if (i != l->size() - 1)cout << " ";
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