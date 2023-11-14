#include <bits/stdc++.h>

using namespace std;

// https://www.hackerrank.com/challenges/sherlock-and-the-beast/problem
// tags: greedy, implementation


pair<int, int> compute(int n) {
    if(n < 3) {
        return make_pair(0, 0);
    }

    int numFives = n;
    int numThrees = 0;
    bool itWasPossible = false;

    for(int i = 0; i <= n; ++i) {
        if(numFives % 3 == 0 and numThrees % 5 == 0) {
            itWasPossible = true;
            break;
        }
        numFives--;
        numThrees++;
    }

    return itWasPossible ? make_pair(numFives, numThrees) : make_pair(0, 0);
}


void renderSol(pair<int, int> ans) {
    // the first element is the number of 5s
    // the second element is the number of 3s

    int numFives = ans.first;
    int numThrees = ans.second;

    if(numFives == 0 and numThrees == 0) {
        cout << "-1";
    }

    while(numFives--) {
        cout << "5";
    }

    while(numThrees--) {
        cout << "3";
    }

    cout << endl;
}


int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        renderSol(compute(n));
    }

    return 0;
}