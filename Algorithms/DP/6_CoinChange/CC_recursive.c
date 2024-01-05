#include <stdio.h>

int count(int S[], int n, int value) {
    // If value in 0 then there is 1 sol
    // don't include any coin
    if(value == 0) return 1;

    // If value is less than 0, then no sol exists
    if(value < 0) return 0;

    // If there are no coins and value is greater
    // than 0, then no solution exists
    if(n <= 0 && value >= 1) return 0;

    // count is sum of solutions:
    // (i) including S[n-1]
    // (ii) excluding S[n-1]
    return count(S, n-1, value) + count(S, n, value-S[n-1]);
}

int main(int argc, char const *argv[]) {
    int n, value;
    printf("Type number of coins: ");
    scanf("%d", &n);
    printf("Type each Sn: \n");
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Type value: ");
    scanf("%d", &value);

    printf("%d \n", count(arr, n, value));
    return 0;
}
