#include <bits/stdc++.h>
// WA
using namespace std;

int countMaxPairs(vector<string> &aux, int n);
vector<vector<string>> getSuffixes(vector<string> &aux);
int getNumSuffixes(vector <string> a, vector <string> b);

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t, n;
    cin >> t;
    string w;
    for (int i = 1; i <= t; i++) {
        cin >> n;
        vector<string> aux(n);
        for (int j = 0; j < n; j++) cin >> aux[j];
        cout << "Case #" << i << ": " << countMaxPairs(aux, n) << endl;
    }
    return 0;
}

// Greedy approach
int countMaxPairs(vector<string> &aux, int n) {
    int ans = 0;
    // process all suffixes
    vector <vector<string> > suffixes = getSuffixes(aux);
    // create hash
    bool hashTable[n] = {};
    int numPairs = n/2, contPairs = 0;
    // compare
    for (int i = 0; i < n-1; i++) {
        if(hashTable[i] == 1) continue;
        int max = 0;
        int indexi = i, indexj = i+1;
        for (int j = i+1; j < n; j++) {
            if(hashTable[j] == 1) continue;
            int tmp = getNumSuffixes(suffixes[i], suffixes[j]);
            if(tmp > max) {
                indexj = j;
                max = tmp;
            }
        }
        if(max != 0) {
            // mark hash
            hashTable[indexi] = 1;
            hashTable[indexj] = 1;
            ans += max;
            contPairs++;
            if(contPairs == numPairs) break;
        }
    }
    // return ans
    return ans;
}

vector<vector<string>> getSuffixes(vector<string> &aux) {
    int n = aux.size();
    vector <vector<string> > suffixes(n);

    for (int i = 0; i < n; i++) {
        int tam = aux[i].size();
        vector <string> ss(tam);
        ss[0] = aux[i][tam-1];
        for (int j = 1; j < tam; j++) {
            ss[j] = aux[i][tam-1-j] + ss[j-1];
        }
        suffixes[i] = ss;
    }

    return suffixes;
}

int getNumSuffixes(vector <string> a, vector <string> b) {
    int n = min(a.size(), b.size());
    int numSuffixes = 0;
    for (int i = 0; i < n; i++) {
        if(a[i] == b[i]) numSuffixes++;
        else break;
    }
    return numSuffixes;
}
