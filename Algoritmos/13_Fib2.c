#include <stdio.h>
#include <stdlib.h>

int fib(int n) {
    int ans;

    if(n < 2) ans = n;
    else {
        int a = 0;
        int b = 1;
        for (int i = 2; i < n; i++) {
            ans = a + b;
            a = b;
            b = ans;
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", fib(n));

    return 0;
}
