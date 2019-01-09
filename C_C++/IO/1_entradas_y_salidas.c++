#include <iostream>
// Programa para mostrar el uso de flujos
using namespace std;

/* Disponemos de varios flujos:
    cin: Para la entrada de distintos tipos de datos (std input).
    cout: Para la salida de distintos tipos de datos (std output).
    cer: Para la salida de errores (std error).
    clo: Para la salid de errores y redirección a ficheros tipo log.

    cin utiliza buffers y nos podemos llevar sopresas al recoger datos.
    Por ejemplo si el usuario no los mete bien, como cuando se pide una palabra
    y se meten dos, la siguiente vez que se pida otro dato se tomará el que se
    había metido, lo podemos evitar con cin.ignore
*/

// Función principal
int main(int argc, char const *argv[]) {
    //unsigned int i;
    char nombre_apellidos[25];
    char linea[80];
    int entero;
    char caracter;

    /* Atención:
    Hay que tener cuidado con los strings, prueba meter a nombre y apellido y verás
    que el string solo se llena hasta el primero espacio en blanco, o incluso
    para a la siguiente variable i y el programa casca.
    */
    cout << "Mete tu nombre y tus apellidos: " << endl;
    cin >> nombre_apellidos;
    cout << "Tu nombre y apellidos: " << nombre_apellidos << endl;

    // Con esta llamada evitamos que se tome en cuenta las sobras
    cin.ignore(255, '\n');

    // ¡Entrada múltiple!
    cout << "Mete una palabra y un número entero: ";
    cin >> nombre_apellidos >> entero;
    cout << "El texto: " << nombre_apellidos << " y el entero: " << entero << endl;

    /* Explicación: '>>' es un operador que se puede sobrecargar como hemos visto
    anteriormente, la expresión 'cin >> nombre_apellidos' devuelve otro objeto
    iostream y se podría reescribir así: (cin >> nombre_apellidos) >> entero;
    */
    cin.ignore(255, '\n');
    // cin.get(string, tamaño), para recoger strings completos
    cout << "Mete un string largo con espacios." << endl;
    cin.getline(linea, 80);
    cout << "Resultado: " << linea << endl;

    /*
    Hay veces que puede interesar ignorar un número de carácteres hasta llegar
    al final de la línea, para eso podemos usar la función cin.ignore(70, '\n');
    en lugar de '\n' podemos usar cualquier caracter de terminación que nos interese.
    No hay que olvidar que cin es un buffer. ¿Qué pasa si solo queremos leer un
    carácter sin tener que "sacarlo" del buffer? Podemos usar cin.peek() y si
    queremos meter un caracter podemos usar cin.putback('.') - metería un . en el
    buffer de cin.get() tomando un único carácter. Si metemos más imprimirá todos,
    puede usarse parámetrizando: cin.get(caracter)
    */
    cout << "Ve metiendo carácteres, y termina con un punto:" << endl;
    while ((caracter = cin.get()) != EOF) {
        if(cin.peek() == '.') {
            cout << caracter << endl;
            cout << "Nos vamos" << endl;
            break;
        }
        cout << caracter;
    }
    cin.ignore(255, '\n');

    return 0;
}
