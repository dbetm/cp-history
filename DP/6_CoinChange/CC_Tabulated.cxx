#include <bits/stdc++.h>
// Time Complexity: O(mn)
// SRC: GFG
using namespace std;

int count(int S[], int n, int value) {
    // We need value+1 rows as the table is constructed in bottom-up manner
    // using the base case 0
    int table[value+1][n];

    // Fill the entries for 0 value case (n == 0)
    for (int i = 0; i < n; i++) table[0][i] = 1;

    // Fill rest of the table entries in bottom up manner
    for (int i = 1; i < value+1; i++) {
        for (int j = 0; j < n; j++) {
            // Count of solutions including S[j]
            int x = (i - S[j] >= 0) ? table[i - S[j]][j] : 0;
            // Count of solutions excluding S[j]
            int y = (j >= 1) ? table[i][j-1] : 0;
            // Total count
            table[i][j] = x + y;
        }
    }

    return table[value][n-1];
}

int main(int argc, char const *argv[]) {
    int n, value;
    printf("Type number of coins: ");
    cin >> n;
    printf("Type each Sn: \n");
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    printf("Type value: ");
    cin >> value;

    printf("%d \n", count(arr, n, value));
    return 0;
}
