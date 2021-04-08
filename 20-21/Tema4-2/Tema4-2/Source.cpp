// Nombre del alumno .....
// Usuario del Juez ......
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Peli.h"
#include <algorithm>

using namespace std;
#pragma region Operators


ostream& operator << (ostream& o, const Hora& t)
{
    string hora = "", min = "", sec = "";
    if (t.GetHora() / 10 == 0) {
        hora = "0";
    }
    if (t.GetMin() / 10 == 0) {
        min = "0";
    }
    if (t.GetSec() / 10 == 0) {
        sec = "0";
    }

    o << hora << t.GetHora() << ":" << min << t.GetMin() << ":" << sec << t.GetSec();
    return o;
}

istream& operator >> (istream& i, Hora& p)
{
    int h, m, s;
    char d;
    i >> h >> d >> m >> d >> s;
    p = Hora(h, m, s);
    i.ignore();
    return i;

}

ostream& operator << (ostream& o, const Peli& p)
{
    o << p.GetFinal() << " " << p.GetTitulo();
    return o;
}

istream& operator >> (istream& i, Peli& p)
{
    Hora inicio, duracion;
    string tit;
    i >> inicio >> duracion;
    getline(i, tit);
    p = Peli(inicio,duracion,tit);
    return i;

}
#pragma endregion
// función que resuelve el problema
vector<Peli> resolver(vector<Peli> datos) {
 sort(datos.begin(),datos.end());
 return datos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int cantidadDeCasos;
    cin >> cantidadDeCasos;
    if (cantidadDeCasos==0)
        return false;
    vector<Peli>pelis;
    for (size_t i = 0; i < cantidadDeCasos; i++)
    {
        Peli p;
        cin >> p;
        pelis.push_back(p);
    }
    vector<Peli> sol = resolver(pelis);
    // escribir sol
    for (size_t i = 0; i < sol.size(); i++)
    {
        cout << sol.at(i)<<endl;
    }
    cout << "---" << endl;
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
