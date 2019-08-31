#include <bits/stdc++.h>
//
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO() ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

int main() {
	fastIO();
    // Leer n
    // Leer los valores del arreglo de tamaño n
    // Iterar, y guardar en un map(valor, vector de pares)
    // Si el tamaño del mapa es igual a n, entonces -1
    // De otra forma:
        // Definir de hipótesis un mínimo de 1001
        // iterar el mapa, hacer todos vs todos en cada vector de valores
            // Ir viendo si encontramos un 'mínimo' menor
        // Mostrar el mínimo
    int n, num;
    cin >> n;
    map<int, vector<int>> dic;
    for (int i = 0; i < n; i++) {
        cin >> num;
        try {
            dic[num].push_back(i);
        }
        catch(...) {
            vector<int> aux;
            aux.push_back(num);
            dic.insert(pair<int, vector <int>>(num, aux));
        }
    }
    if((int)dic.size() == n) cout << -1 << endl;
    else {
        int minimo = 1001;
        map<int, vector<int>>::iterator itr;
        for (itr = dic.begin(); itr != dic.end(); ++itr) {
            vector<int> matching = itr->second;
            int tam = matching.size();
            if(tam == 1) continue;
            else {
                for (int i = 0; i < tam-1; i++) {
                    for (int j = i+1; j < tam; j++) {
                        minimo = min(minimo, abs(matching[i] - matching[j]));
                    }
                }
            }
        }
        cout << minimo << endl;
    }
	return 0;
}
