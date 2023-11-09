#include <bits/stdc++.h>

using namespace std;

// https://www.hackerrank.com/challenges/marcs-cakewalk/problem
// tags: math, greedy, sort


int main() {
    int n;
    cin >> n;
    vector<long int> calories(n);
    long long int minMiles = 0;

    for (int i = 0; i < n; ++i) {
        cin >> calories[i];
    }

    // sort descendent
    sort(calories.rbegin(), calories.rend());
    

    for (int i = 0; i < calories.size(); ++i) {
        minMiles += pow(2, i) * calories[i];
    }

    cout << minMiles << endl;

    return 0;
}