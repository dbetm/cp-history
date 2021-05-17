#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void reverseString(char str[], int n) {
    int l = 0;
    int r = n-1;
    char aux;

    while(l < r) {
        aux = str[l];
        str[l] = str[r];
        str[r] = aux;
        l++;
        r--;
    }
}

int main() {
    char str[1000];
    int n;
    scanf("%s", str);
    n = strlen(str);

    reverseString(str, n);

    printf("%s\n", str);
}
