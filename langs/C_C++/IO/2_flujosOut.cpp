#include <bits/stdc++.h>
/**
    Programa para mostrar el uso de flujos de salida
*/
using namespace std;

/* Cout también utiliza buffers y nos podemos llevar una sopresa al recoger
datos, aunque si queremos tirar de la cadena ejecutamos: cout << flush; */

int main(int argc, char const *argv[]) {
    unsigned int i;
    char nombre_apellidos[25];
    char linea[80];
    int entero;
    char caracter;

    char frase[] = "Clatu verata nictu\n";
    // Si para cin tenemos get, para cout tenemos: put
    // Mandamos un saludo
    cout.put('K').put('a').put('i').put('x').put('o').put('\n');

    // Vamos a mostrar la línea
    entero = strlen(frase);
    // Con esto la mostraremos entera
    cout.write(frase, entero);
    // Con esto...no
    cout.write(frase, (entero - 5));

    cout << " ahora con formato: " << endl;
    // Vamos a ponerla con cierto formato: width y fill
    cout.width(30); // Esto mete espacios en blanco, equivalente a setw(30)
    cout << frase << endl;

    cout.width(30); // Esto vuelve a meter espacios
    //cout.fill('>'); // Y esto rellena los espacios
    cout << frase << endl;

    // Estableciendo el estado de cout con setf
    // Alineación: setf(ios::left) y setf(ios::right)
    // Hay más para investigar: ios::showbase, ios::internal, etc.

    cout.setf(ios::right);
    entero = 999;
    // y podemos alterar la base con dec, oct y hex
    cout << "Entero hexadécimal alineado a la derecha: " << hex << entero << endl;
    return 0;
}
