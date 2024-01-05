#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    int64_t li;
    vector <int> indices;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> li;
        if(li % 3 == 0) indices.push_back(i);
    }
    int tam = indices.size();
    if(tam != 0) {
        cout << indices.size() << "\n";
        for (unsigned int i = 0; i < indices.size() - 1; i++) {
            cout << indices[i] << " ";
        }
        cout << indices[indices.size()-1] << "\n";
    }
    else cout << "No hay triples." << endl;
    return 0;
}
