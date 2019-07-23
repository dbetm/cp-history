#include <bits/stdc++.h>
// Time complexity: O(n log k)
// Proof: http://www.cs.umd.edu/~gasarch/BLOGPAPERS/eggold.pdf
using namespace std;
// Find sum of binomial coefficients xCi
// (where i varies from 1 to n).
int binomialCoefficient(int x, int n) {
    int sum = 0, term = 1;
    for (int i = 1; i <= n; i++) {
        term *= x - i + 1;
        term /= i;
        sum += term;
    }
    return sum;
}

// Do binary search to find minimum
// number of trials in worst case.
int eggDrop(int n, int k) {
    // Initialize low and high as 1st
    // and last floors
    int low = 1, high = k;

    // Do binary search, for every mid,
    // find sum of binomial coefficients and
    // check if the sum is greater than k or not.
    while(low < high) {
        int mid = (low + high) / 2;
        if(binomialCoefficient(mid, n) < k) low = mid + 1;
        else high = mid;
    }

    return low;
}

int main() {
    int n, k;
    cout << "Ingresa el número de huevos: ";
    cin >> n;
    cout << "Ingresa el número de pisos: ";
    cin >> k;
    cout << "El mínimo número de intentos en el peor caso es: ";
    cout << eggDrop(n ,k) << endl;
    return 0;
}
