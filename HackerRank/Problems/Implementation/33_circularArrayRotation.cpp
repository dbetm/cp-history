#include <bits/stdc++.h>

using namespace std;

vector <int> circularArrayRotation(vector <int> a, vector <int> m, int k) {
    vector <int> result;
    int magicIndex, size = a.size(), temp = k % size;

    for(unsigned int i = 0; i < m.size(); i++) {
        magicIndex = (size + (m[i] - temp) )  % size;
        result.push_back(a[magicIndex]);
    }

    return result;
}

int main() {
    int n;
    int k;
    int q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector<int> m(q);
    for(int m_i = 0; m_i < q; m_i++){
       cin >> m[m_i];
    }
    vector <int> result = circularArrayRotation(a, m, k);
    for (unsigned int i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}
