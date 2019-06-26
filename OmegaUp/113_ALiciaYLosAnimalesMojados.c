#include <stdio.h>
// https://omegaup.com/arena/problem/Alicia-y-los-animales-mojados#problems
int arr[5000001];

int main() {
    int n, animal, cont = 0;
    scanf("%d", &n);

    while(n--) {
        scanf("%d", &animal);
        if(arr[animal] == 0) {
            arr[animal] = 1;
            cont++;
        }
    }

    printf("%d\n", cont);

    return 0;
}
