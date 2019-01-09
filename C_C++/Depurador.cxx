/* Programa que muestra el uso del preprocesador
depurar */

// include de utiliza para poder usar código externo
// generalmente las bibliotecas estándar o propias.

using namespace std;

#include <iostream>

// Disponemos de estas variables de macro definidas, muy útiles para depurar
/* __DATE__ : Sustituye esa var por la fecha
*  __TIME__ : Sustituye esa var por la hora
*  __LINE__ : Sustituye esa var por la línea del programa
*  __FILE__ : Sustituye esa va por el nombre del fichero del programa
*/

// Definimos la var DEBUG para activar la depuración
#define DEBUG
/* Y mostramos el uso de assert(), su disponibilidad dependerá del
compilador cuando invocamos la función assert, si lo que tiene como
parámetro es TRUE no habrá problema, pero si es false saltará un código de
depuración que le digamos. */
#ifndef DEBUG
    #define ASSERT(x)
#else
    #define ASSERT(x) \
        if(!(x)) { \
            cout << "Error detectado, fallo: " << #x << "\n"; \
            cout << "Línea: " << __LINE__ << " del fichero " << __FILE__ << "\n"; \
        }
#endif

int main() {
    int i = 345;

    cout << "Hola, hoy es: " << __DATE__ << endl;
    // Es verdadero
    ASSERT(i>5);

    cout << "Este es el fichero: " << __FILE__ << endl;
    cout << "Estamos en la línea: " << __LINE__ << endl;
    // Es falso
    ASSERT(i == 0);
    return 0;
}
