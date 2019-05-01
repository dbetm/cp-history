#include <bits/stdc++.h>
// GFG
// Exponential time complexity!

/*A naive recursive implementation that simply
follows the above optimal substructure property*/
using namespace std;

// Matrix Ai has dimension p[i-1]*p[i]
// for i = 1...n
int matrixChainOrder(int p[], int i, int j) {
    if(i == j) return 0; // trivial case
    int minn = INT_MAX;
    int count;
    /* Place parenthesis at different places between first and last matrix,
    recursively calculate count of multiplications for each parenthesis
    placement and return the minimum count */
    for(int k = i; k < j; k++) {
        count = matrixChainOrder(p, i, k) +
                matrixChainOrder(p, k+1, j) +
                p[i-1] * p[k] * p[j];
        minn = min(count, minn);
    }

    return minn;
}

int main(int argc, char const *argv[]) {
    int n;
    cout << "Type n: ";
    cin >> n;
    int arr[n];
    cout << "Type wach value: " << endl;
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << "Minimum number of multiplications is "
        << matrixChainOrder(arr, 1, n-1) << endl;
    return 0;
}
