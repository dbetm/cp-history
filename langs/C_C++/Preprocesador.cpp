// Programa que muestra el uso del preprocesador.

/* Include se utiliza para poder utilizar código externo, generalmente las
bibliotecas estándar o nuestras propias librerías
*/
#include <iostream>
using namespace std;

/* Las variables de preprocesador sirven para que el compilador haga ciertas
modificaciones en el código fuente
*/
#define PI 3.1415
#define BATMAN "Bruce Wayne"
#define MISTERX "Felipe González"
#define REVELAR
#define BUFFER 255

/* Podemos definir funciones, aunque sin compliecarlas ya que dificulta la
depuración y se pasa el tipado de variables
*/
#define PORCENTAJE(a, b) (a * b) / 100

/* Guardias de inclusión
Estructura condicional para evitar múltiples inclusiones.
La siguiente estructura comprueba SI NO se ha definido la variable FSTREAM
*/
#ifndef FSTREAM
// Si no se ha definido la definimos
#define FSTREAM
#include <fstream>
// Fin de la condición
#endif

// Macro de comillas
#define write(x) cout << #x << endl;

int main() {
    int i = 345;
    float var = 4.67;
    char buffer[BUFFER]; // automáticaente el compilador traduce: buffer[255]

    #ifdef PI
        cout << "El valor PI es: " << PI << ": ten fe en el caos" << endl;
    #else
        cout << "PI no está definido..." << endl;
    #endif

    // Ahora miramos una variable de preprocesador que no está:
    // y así en este caso no se revela quien es BATMAN...
    #ifdef REVELAR2
        cout << "Batman realmente se trata de: " << BATMAN << endl;
    #endif

    // Con esta orden eliminados la variable:
    #undef REVELAR

    // Y este es el efecto
    #ifdef REVELAR
        cout << "Mistery realmente es: " << MISTERX << endl;
    #endif

    cout << "var * PI = " << (var * PI) << endl;

    // Mostramos la llamada a la función
    cout << "Porcentaje 15% de " << i << " es: " << PORCENTAJE(i, 15) << endl;

    // Llamada a la MACRO. ¿Convertirá a MISTERX?
    write(Hay que ver que lujo verdad MISTERX);

    return 0;
}
