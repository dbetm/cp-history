#include <stdio.h>
// https://omegaup.com/arena/problem/Coordenadas-Cartesianas#problems
int main() {
    int n;
    scanf("%d", &n);
    int x, y;
    while(n--) {
        scanf("%d %d", &x, &y);
        if(x > 0 && y > 0) printf("I\n");
        else if(x > 0 && y < 0) printf("IV\n");
        else if(x < 0 && y > 0) printf("II\n");
        else printf("III\n");
    }

    return 0;
}
