#include <bits/stdc++.h>
//https://www.hackerrank.com/challenges/cut-the-sticks/problem
using namespace std;

void getCutSticks(vector <int>);
vector <int> cutSticks(vector <int>);
vector <int> discardShortestSticks(vector <int>);

int main(int argc, char* argv[]) {
    int n, aux;
    vector <int> A;

    cin >> n;
    for (size_t i = 0; i < n; i++) {
        cin >> aux;
        A.push_back(aux);
    }

    sort(A.begin(), A.end());

    getCutSticks(A);

    return 0;
}

void getCutSticks(vector <int> A) {
    if(A.size() == 0) return;
    else {
        cout << A.size() << endl;
        A = discardShortestSticks(cutSticks(A));
        return getCutSticks(A);
    }
}

vector <int> cutSticks(vector <int> A) {
    int s = A[0];
    for (size_t i = 0; i < A.size(); i++) A[i] -= s;
    return A;
}

vector <int> discardShortestSticks(vector <int> A) {
    A.erase(remove_if(A.begin(), A.end(),[](int i){ return i == 0;}), A.end());
    return A;
}
