#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
// NOTA: Las operaciones de multiplicación y división son posición a posición
/*
    Autor: David Betancourt Montellano
    Fecha: 10-01-2018
*/
using namespace std;

int menu();

class Calculadora {
    private:
        int columnas;
        int filas;
        int numeroMatrices;
        vector < vector < int > > inicializar();
    public:
        Calculadora(int, int, int);
        static string mostrarInit();
        void mostrarResultado(vector < vector < int > >);
        void sumarRestar(bool);
        void multiplicarDividir(bool);
        void transponer();
        ~Calculadora();
};

Calculadora::Calculadora(int c, int f, int n) {
    columnas = c;
    filas = f;
    numeroMatrices = n;
}

vector < vector < int > > Calculadora::inicializar() {
    vector < vector < int > > init(filas);
    for (int i = 0; i < filas; i++) {
        vector < int > fila;
        for (int j = 0; j < columnas; j++) {
            fila.push_back(0);
        }
        init[i] = fila;
    }
    return init;
}

string Calculadora::mostrarInit() {
    system("clear");
    return "\tCALCULADORA DE MATRICES\n";
}

void Calculadora::mostrarResultado(vector < vector < int > > resultado) {
    for(int i = 0; i < resultado.size(); i++) {
        for(int j = 0; j < resultado[i].size(); j++) {
            cout << resultado[i][j] << (j !=  resultado[i].size() - 1 ? " ":"\n");
        }
    }
    cin.get();
}

void Calculadora::sumarRestar(bool flag) {
    int n;
    vector < vector < int > > resultado = inicializar();
    for(int i = 0; i < numeroMatrices; i++) {
        cout << "\nMatriz número " << i+1 << endl;
        for(int j = 0; j < filas; j++) {
            for(int k = 0; k < columnas; k++) {
                cin >> n;
                if(i == 0) {
                    if(flag) resultado[j][k] = n;
                    else resultado[j][k] = n;
                }
                else {
                    if(flag) resultado[j][k] += n;
                    else resultado[j][k] -= n;
                }
            }
        }
    }
    if(flag) cout << "\nEl resultado de la suma es: " << endl;
    else cout << "\nEl resultado de la resta es: " << endl;
    mostrarResultado(resultado);
}


void Calculadora::multiplicarDividir(bool flag) {
    int n;
    vector < vector < int > > resultado = inicializar();
    for(int i = 0; i < numeroMatrices; i++) {
        cout << "\nMatriz número " << i+1 << endl;
        for(int j = 0; j < filas; j++) {
            for(int k = 0; k < columnas; k++) {
                cin >> n;
                if(i == 0) {
                    if(flag) resultado[j][k] = n;
                    else resultado[j][k] = n;
                }
                else {
                    if(flag) resultado[j][k] *= n;
                    else {
                        if(n != 0) resultado[j][k] /= n;
                        else {
                            cout << "Error al tratar de dividir entre 0" << endl;
                            return;
                        }
                    }
                }
            }
        }
    }
    if(flag) cout << "\nEl resultado de la multiplicación es: " << endl;
    else cout << "\nEl resultado de la división es: " << endl;
    mostrarResultado(resultado);
}

void Calculadora::transponer() {
    vector < vector < int > > resultado(columnas, vector < int > (filas));
    cout << "Escriba la matriz:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cin >> resultado[j][i];
        }
    }
    cout << "\nLa matriz transpuesta es la siguiente: " << endl;
    mostrarResultado(resultado);
}

Calculadora::~Calculadora() {
}

int main(int argc, char const *argv[]) {
    int opc, col, fil, num;
    bool control = true;

    do {
        cout << Calculadora::mostrarInit();
        opc = menu();
        if(opc > 0 && opc < 6) {
            if(opc == 5) num = 1;
            else {
                cout << "\nNúmero de matrices: ";
                cin >> num;
            }
            cout << "Filas: ";
            cin >> fil;
            cout << "Columnas: ";
            cin >> col;
        }

        Calculadora c1(col, fil, num);
        switch(opc) {
            case 1:
                cout << "Usted ha elegido la operación suma" << endl;
                c1.sumarRestar(true);
                break;
            case 2:
                cout << "Usted ha elegido la operación resta" << endl;
                c1.sumarRestar(false);
                break;
            case 3:
                cout << "Usted ha elegido la operación multiplicación" << endl;
                c1.multiplicarDividir(true);
                break;
            case 4:
                cout << "Usted ha elegido la operación división" << endl;
                c1.multiplicarDividir(true);
                break;
            case 5:
                cout << "Usted va a transponer una matriz" << endl;
                c1.transponer();
                break;
            case 6:
                control = false;
                break;
            default:
                cout << "¡Opción no válida!" << endl;
                break;
        }
        cout << "\nPresione enter para continuar..." << endl;
        cin.get();
    } while(control);

    return 0;
}

int menu() {
    int ans;
    cout << "\n\tElija una opción" << endl;
    cout << "1. Sumar n matrices" << endl;
    cout << "2. Restar n matrices" << endl;
    cout << "3. Multiplicar n matrices posición a posición" << endl;
    cout << "4. Dividir n matrices posición a posición" << endl;
    cout << "5. Tranponer una matriz" << endl;
    cout << "6. Salir" << endl;
    cout << "->> ";
    cin >> ans;
    return ans;
}
