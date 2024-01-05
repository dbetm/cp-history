#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    int arr[n];
    int res[n+1];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("1 ");
    res[0] = 1;

    for (int i = 1; i < n; i++) {
        printf("%d ", res[i-1] + arr[i]);
        res[i] = arr[i];
    }

    printf("1\n");

    return 0;
}
