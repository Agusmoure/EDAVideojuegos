#include "Header.h"
#include "Accidentes.h"
// Agustín Moure Rodríguez
// V41


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
int resolver(const List<Accidentes>& datos,int j) {
    int i = j;
    int muertos = datos.at(j).GetFallecidos();
    bool found = false;
do{
    if(i!=0)
        i--;
    if (datos.at(i).GetFallecidos() > muertos)found = true;
} while (i > 0 && !found);
if (!found)i--;
return i;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int d;
    cin >> d;
    if (!std::cin)
        return false;
    List<Accidentes> datos;
    for (size_t i = 0; i < d; i++)
    {
        int dia, mes, anio, muertes;
        char c;
        cin >> dia;
        cin >> c;
        cin >> mes;
        cin >> c;
        cin >> anio;
        cin >> muertes;
        datos.push_back(Accidentes(muertes, Fecha(dia, mes, anio)));
    }
    for (size_t i = 0; i < d; i++)
    {
    int sol= resolver(datos,i);
    if (sol != -1) {
        Fecha fec = datos.at(sol).GetFecha();
        cout << fec.GetDia() << "/" << fec.GetMes() << "/" << fec.GetAnio() << endl;
    }
    else
    {
        cout << "NO HAY" << endl;
    }
    }

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