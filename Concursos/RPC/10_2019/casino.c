#include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// No pasó
typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(void) {
    int t;
    int n, p;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &p);
        if(n & 1) {
            if(p == 0) {
                if(n == 3) printf("1\n");
                else printf("0\n");
            }
            else {
                if(n == 3 || n == 1) printf("0\n");
                else printf("1\n");
            }
        }
        else {
            if(p == 0) {
                if(n == 4) printf("0\n");
                else printf("1\n");
            }
            else {
                if(n == 2) printf("0\n");
                else printf("1\n");
            }
        }
    }
    return 0;
}
