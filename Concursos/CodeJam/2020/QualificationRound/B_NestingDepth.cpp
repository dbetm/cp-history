#include <bits/stdc++.h>
// Test 1/2: Accepted, Test 2/2: WA
// Tag(s): Implementation, strings
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

struct nodo {
    int numero;
    int repeticiones;
    int l;
    int r;
    // Constructor
    nodo(int n) {
        numero = n;
        repeticiones = 0;
        l = numero;
        r = numero;
    }
    // Helpers
    void print() {
        cout << "# " << numero << ", rep: " << repeticiones << ", l: ";
        cout << l << ", r: " << r << endl;
    }

    bool esBalanceado() {
        return (l == r);
    }

    bool esCero() {
        return (l == 0 && r == 0);
    }
};

vector<nodo> generarLista(string aux);
string compute(vector<nodo> &lista);
string formatear(vector<nodo> &lista);

int main() {
    fastIO
    int t, cont = 1;
    string aux;
    cin >> t;
    while(t--) {
        // input dim of matrix
        cin >> aux;
        vector<nodo> lista = generarLista(aux);
        aux = compute(lista);
        cout << "Case #" << (cont++) << ": " << aux << endl;
    }
	return 0;
}

vector<nodo> generarLista(string aux) {
    int n = aux.size();
    vector<nodo> ans;
    int j;
    for (int i = 0; i < n; i++) {
        nodo elemento = {int(aux[i]-48)};
        j = i;
        while(j < n && elemento.numero == int(aux[j]-48)) {
            j++;
            elemento.repeticiones++;
        }
        i = j - 1;

        ans.push_back(elemento);
        // elemento.pri
    }

    return ans;
}

string compute(vector<nodo> &listaOriginal) {

    int n = listaOriginal.size();
    string ans = "";
    int global = INT_MAX;

    for (int p = 0; p < n; p++) {
        vector<nodo> lista = listaOriginal;
        for (int i = p; i < n; i++) {
            if(!lista[i].esBalanceado() || lista[i].esCero()) continue;
            //watch(lista[i].numero)
            // 1) Afectar elementos a su izquierda
            // 1.1) Encontrar el elemento más a la izquierda que cumple
            int izq = i;
            int minIzq = 9;
            while(izq - 1 >= 0) {
                //watch(lista[izq-1].numero)
                if(lista[izq-1].esBalanceado() && lista[izq-1].numero <= lista[i].numero && !lista[izq-1].esCero()) {
                    izq--;
                    minIzq = min(minIzq, lista[izq].l);
                }
                else break;
            }
            // 1.2) Propagar el efecto de anidarlo con el más grande
            if(i != izq) {
                int delta = minIzq;
                //watch(delta)
                lista[i].l -= delta;
                lista[izq].r = max(0, lista[izq].r - delta);
                for (int k = izq+1; k < i; k++) {
                    lista[k].l = max(0, lista[k].l - delta);
                    lista[k].r = max(0, lista[k].r - delta);
                }
            }
            // 2) Afectar elementos a su derecha
            // 2.1) Encontrar el elemento más a la derecha que cumple
            int der = i;
            int minDer = 9;
            while(der + 1 < n) {
                //watch(lista[der+1].numero)
                if(lista[der+1].esBalanceado() && lista[der+1].numero <= lista[i].numero && !lista[der+1].esCero()) {
                    der++;
                    minDer = min(minDer, lista[der].r);
                }
                else break;
            }
            // 2.2) Propagar el efecto de anidarlo con el más grande
            if(i != der) {
                int delta = minDer;
                //watch(delta)
                lista[i].r -= delta;
                lista[der].l = max(0, lista[der].l - delta);
                for (int k = der-1; k > i; k--) {
                    lista[k].l = max(0, lista[k].l - delta);
                    lista[k].r = max(0, lista[k].r - delta);
                }
            }
            // cout << formatear(lista) << endl;
            // cin.get();
        }

        string aux = formatear(lista);
        if(aux.size() < global) {
            ans = aux;
            global = aux.size();
        }
    }


    return ans;
}

string formatear(vector<nodo> &lista) {
    string aux = "";
    int n = lista.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < lista[i].l; j++) {
            aux += "(";
        }
        for (int j = 0; j < lista[i].repeticiones; j++) {
            aux += to_string(lista[i].numero);
        }
        for (int j = 0; j < lista[i].r; j++) {
            aux += ")";
        }
    }

    return aux;
}
