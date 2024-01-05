#include <bits/stdc++.h>
// Incompleto
// Tag(s):
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
#define EPS 1.19209e-07
#define fastIO ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<double> vd;
lli MAX = 1e9+7;

int main() {
	fastIO
    int cajas, tamCaja, val;
    cin >> cajas;
    map<int, vector<int>> rel;
    int sumas[cajas+1];
    int64_t sumaAux, sumaTotal = 0;
    int64_t promedio;
    vector<pair<int64_t, int64_t>> ans;

    for (int i = 1; i <= cajas; i++) {
        cin >> tamCaja;
        sumaAux = 0;
        for (int j = 0; j < tamCaja; j++) {
            cin >> val;
            sumaAux += val;
            rel[i].push_back(val);
        }
        sumas[i] = sumaAux;
        sumaTotal += sumaAux;
    }
    promedio = sumaTotal / cajas;
    //watch(sumaTotal)
    //watch(promedio)

    map<int, vector<int>>::iterator it;

    vector<int> temp = rel[1];
    int tamTemp = temp.size();


    bool flag = false;

    for (int i = 0; i < tamTemp; i++) {
        int val = temp[i];
        int sumita = sumas[i+1];
        for (it = rel.begin(); it != rel.end(); ++it) {
            for (int j = 0; j < rel->second.size(); j++) {
                if(sumita - val + rel->second[j]  == promedio) {
                    flag = true;
                    ans.push_back(make_pair(rel->second[j], rel->first));
                    rel.erase(i);
                    it = rel.end();
                    i = tamTemp;
                    break;
                }
            }
        }
    }

    if(!flag) {
        flag = false;
        map<int, vector<int>>::iterator it2;

        for (it2 = rel.begin() + 1; it2 != rel.end(); ++it2) {
            int cajaId = it2->first;
            int sumita = sumas[cajaId];

            for (it = it2; it != rel.end(); ++it) {
                for (int j = 0; j < rel->second.size(); j++) {
                    if(sumita - val + rel->second[j]  == promedio) {
                        flag = true;
                        ans.push_back(make_pair(rel->second[j], rel->first));
                        rel.erase(i);
                    }
                }
            }

        }
    }


    // map<int, vector<int>>::iterator it;
    // for (it = rel.begin(); it != rel.end(); ++it) {
    //     cout << it->first << endl;
    //     int n = it->second.size();
    //     for (int j = 0; j < n; j++) {
    //         cout << it->second[j] << " ";
    //     }
    //     cout << endl;
    // }

    if(flag) {
        cout << "Yes" << endl;
        int n = ans.size();
        for (int i = 0; i < ans; i++) {
            cout << ans.first << " " << ans.second << endl;
        }
    }
    else cout << "No" << endl;


	return 0;
}
