#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, aux, pos, a, b;
    cin >> N;
    cin.get();
    vector < int > A(N);
    for(int i = 0; i < N; i++) {
        cin >> aux;
        A[i] = aux;
    }
    cin >> pos;
    A.erase(A.begin()+pos-1);
    cin >> a >> b;
    A.erase(A.begin()+a-1, A.begin()+b-1);
    cout << A.size() << endl;
    for(int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    return 0;
}
