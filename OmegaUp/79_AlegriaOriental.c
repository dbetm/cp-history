#include <stdio.h>

int main() {
    int n, num;
    scanf("%d", &n);

    while(n--) {
        scanf("%d", &num);
        while(num--) {
            printf("w");
        }
        printf("\n");
    }
    return 0;
}
