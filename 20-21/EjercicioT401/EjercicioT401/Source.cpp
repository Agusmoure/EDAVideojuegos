// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>
#include "Time.h"

using namespace std;
ostream& operator << (ostream& o, const Time& t)
{
    string hora="", min="", sec="";
    if (t.GetHora() / 10 == 0) {
        hora = "0";
    }
    if (t.GetMin() / 10 == 0) {
        min = "0";
    }
    if (t.GetSec() / 10 == 0) {
        sec = "0";
    }

    o <<hora<< t.GetHora() << ":"<<min << t.GetMin() << ":"<<sec << t.GetSec();
    return o;
}

istream& operator >> (istream& i, Time& p)
{
    int h, m, s;
    char d;
    i >> h >> d >> m >> d >> s;
    p = Time(h, m, s);
    i.ignore();
    return i;

}

// función que resuelve el problema
void resolver(vector<Time> datos,Time h) 
{
    if (h.GetCorrect()) {

    int i = 0;
    bool flag = true;
    while(i<datos.size()&&flag){
        if (h > datos.at(i)) {
            i++;
    }
        else
        {
            flag = false;
        }
    }
    if (!flag)cout << datos.at(i)<<endl;
    else
    {
        cout << "NO" << endl;
    }
    }

    else {
        cout << "ERROR"<<endl;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    vector<Time>datos;
    vector<Time>horas;
    int cant=0;
    int h=0;
    cin >> cant;
    cin >> h;
    for (size_t i = 0; i < cant; i++)
    {
        Time t;
        cin >> t;
        datos.push_back(t);
    }
    for (size_t i = 0; i < h; i++)
    {
        Time t;
        cin >> t;
        horas.push_back(t);
    }
    if (cant==0&&h==0)
        return false;
    for (size_t i = 0; i < h; i++)
    {
    resolver(datos,horas.at(i));
    }
    cout << "---" << endl;
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