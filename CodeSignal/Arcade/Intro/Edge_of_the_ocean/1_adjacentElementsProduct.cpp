/* Given an array of integers, find the pair of adjacent elements that has
the largest product and return that product.

Constraints:
2 ≤ inputArray.length ≤ 10,
-1000 ≤ inputArray[i] ≤ 1000.
*/
#include <bits/stdc++.h>

using namespace std;

int adjacentElementsProduct(vector <int> A) {
    int prod = A[0] * A[1];
    for (size_t i = 1; i < A.size() - 1; i++) {
        if(A[i] * A[i + 1] > prod) {
            prod = A[i] * A[i + 1];
        }
    }

    return prod;
}

int main() {
    vector <int> A;
    int n, num;
    cin >> n;

    while(n--) {
        cin >> num;
        A.push_back(num);
    }
    cout << adjacentElementsProduct(A) << endl;
    return 0;
}
