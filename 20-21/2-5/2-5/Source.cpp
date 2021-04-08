// Agustín Moure Rodríguez
// V41

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
//cuando dividamos el vector dando igual su longitud sabremos cual es la parte que contiene el factor sin repetir ya que sera la zona que parta desde una posicion par 
//ejemplo aclaratorio con 1 vector de longitud 7 pero se da para todos los vectores
// 3 5 5 7 7 9 9 11 11 vector con 7 digitos cuando tomemos el medio nos dara el numero en la posicion 3 en este caso es el 1º 7 al ver que el siguiente tambien es un 7
//o bien buscamos desde 2 posiciones mas adelantes o desde 1 mas atrasada si buscasemos en las mas adelantadas partiriamos desde la posicion 5 (impar) si buscamos una mas atras es la 2
//(par) y como vemos se encuentra en esa zona poniendo un vector de 7 elementos pero el no repetido al final ocurre lo mismo 3 3 5 5 7 7 9 9 11 como vemos la posicion ahora es la del 
//2º 5 asique que sigue siendo la posicion 3 pero ahora o bien partimos de la posicion 1 (impar) dos mas atras ya que el anterior tambien es un 5 o desde la posicion 4 (par) que como vemos es 
//hacia donde se encuentra el numero no repetido

int resolver(vector<int> datos,int ini, int fin) {//O(log(n))
    if (fin-ini == 0)return ini;
    if (fin-ini == 2) {
        if (datos.at(ini) == datos.at(ini+1))return fin;
        return ini;
    }
    int mid = (fin + ini) / 2;
    if (datos.at(mid) != datos.at(mid + 1)) {
        if (datos.at(mid) != datos.at(mid - 1)) return mid;
        if ((mid + 1) % 2 == 0)return resolver(datos, mid + 1, fin);
        return resolver(datos, ini, mid - 2);
    }
    if ((mid - 1) % 2 == 0)return resolver(datos, ini, mid-1);
    return resolver(datos, mid+2, fin);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int l;
    cin >> l;
    vector<int> datos;
    for (int i = 0; i < l; i++) {
        int dato;
        cin >> dato;
        datos.push_back(dato);
    }
    int sol = resolver(datos,0,datos.size()-1);
    // escribir sol
    cout << sol << endl;

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