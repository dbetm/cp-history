#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    int arr[n];
    int flag = 1;
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (int i = 0, j = n-1; i < n/2; i++, j--) {
        if(arr[i] != arr[j]) {
            flag = 0;
            break;
        }
    }

    if(flag == 1) printf("SI\n");
    else printf("NO\n");

    return 0;
}
