#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int64_t num;
    cin >> n;
    vector<int> indices;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if(num % 3 == 0) indices.push_back(i+1);
    }
    int tam = indices.size();
    if(tam == 0) cout << "no hay triples" << endl;
    else {
        cout << tam << endl;
        for (int i = 0; i < tam-1; i++) {
            cout << indices[i] << " ";
        }
        cout << indices[tam-1] << endl;
    }
    return 0;
}
