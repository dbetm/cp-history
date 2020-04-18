#include <stdio.h>
#include <stdlib.h>
// #include <math.h>
//
// Tag(s):
typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

int main(void) {
    ulli n;
    ulli ans = 0;
    scanf("%llu", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%llu", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            ans = max(arr[i] ^ arr[j], ans);
        }
    }


    printf("%d\n", ans);
    return 0;
}
