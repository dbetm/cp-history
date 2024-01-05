#include <bits/stdc++.h>
// Time Complexity: O(mn)
// Space Complexity: O(n)
// SRC: GFG
using namespace std;

int count(int S[], int n, int value) {
    // table[i] will be storing the number of solutions for
    // value i. We need n+1 rows as the table is constructed
    // in bottom up manner using the base case (n = 0)
    int table[value + 1];
    // Initialize all table values as 0
    memset(table, 0, sizeof(table));
    // Base case (If given value is 0)
    table[0] = 1;
    // Pick all coins one by one and update the table[] values
    // after the index greater than or equal to the value of the
    // picked coin
    for(int i = 0; i < n; i++)
        for(int j = S[i]; j <= value; j++)
            table[j] += table[j-S[i]];

    return table[value];
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
