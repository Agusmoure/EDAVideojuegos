// Agustín Moure Rodríguez
// V41


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <queue>

using namespace std;
// función que resuelve el problema
queue<int> resolver(queue<int>&pos,stack<int>&neg) {
    queue<int>ret;
    while (!neg.empty())
    {
        ret.push(neg.top());
        neg.pop();
    }
    while (!pos.empty())
    {
        ret.push(pos.front());
        pos.pop();
    }
    return ret;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int cant;
    cin >> cant;
    if (cant == 0)
        return false;
    stack<int> nega;
    queue<int>pos;
    for (size_t i = 0; i < cant; i++)
    {
        int dato;
        cin >> dato;
        if (dato < 0)nega.push(dato);
        else pos.push(dato);
    }
    // escribir sol
    while (!nega.empty())
    {
        cout<<nega.top();
        nega.pop();
        if (!nega.empty())cout << " ";
    }
    if (!pos.empty())cout << " ";
    while (!pos.empty())
    {
        cout<<pos.front();
        pos.pop();
        if (!pos.empty())cout << " ";
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
