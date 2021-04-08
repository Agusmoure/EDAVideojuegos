// Agustín Moure Rodríguez
// V41


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
int resolver(vector<int> datos, int ini,int fin, int menor) {
    if (datos.size() == 1)return datos.at(0);
    else {
        if (datos.size() == 2) {
            if (datos.at(0) < datos.at(1))return datos.at(0);
            else return datos.at(1);
        }
        else {
            int mid;
            mid = (fin + ini) / 2;
            if (mid == 0)
            {
                if (datos.at(mid) < datos.at(mid + 1))return datos.at(mid);
                else return datos.at(mid + 1);
            }
            if (datos.at(mid - 1) < datos.at(mid)) return datos.at(mid - 1);
            
            else {
                if (mid == fin)return datos.at(mid);
                if (menor < datos.at(mid))return resolver(datos, ini, mid-1, menor);
                return resolver(datos, mid+1, fin, datos.at(mid));
            }
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int d;
    cin >> d;
    if (!std::cin)
        return false;
    vector<int> datos;
    for (int i = 0; i < d; i++) {
        int dato;
        cin >> dato;
        datos.push_back(dato);
    }
    int sol;
    if (!datos.empty())
        sol = resolver(datos, 0, datos.size()-1, datos.at(0));
    else sol = 0;
    // escribir sol
    cout << sol<<endl;

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