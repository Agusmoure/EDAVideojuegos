// Agustín Moure Rodríguez
// V41


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
int resolver(vector<int> datos, int ini, int fin) {
    if (datos.size() == 1)return datos.at(0);
    if (datos.size() == 2) {
        if (datos.at(0) % 2 == 0)return datos.at(1);
        else return datos.at(0);
    }
    int mid = (fin + ini) / 2;
    if (datos.at(mid) % 2 != 0)return datos.at(mid);
    else {
    if(fin-ini<2){
        if (datos.at(fin) % 2 != 0)return datos.at(fin);
        else return datos.at(ini);
    }
        int valor = resolver(datos,ini,mid-1);
        if (valor % 2 != 0) return valor;
        return resolver(datos, mid + 1, fin);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int dato;
    cin >> dato;
    if (dato == 0)
        return false;
    vector<int> datos;
    for (int i = 0; i < dato; i++) {
        int d;
        cin >> d;
        datos.push_back(d);
    }
    int sol = resolver(datos,0,dato-1);
    cout << sol << endl;
    // escribir sol

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
