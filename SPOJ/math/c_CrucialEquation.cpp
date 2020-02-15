#include <iostream>
#include <cstdio>
#include <cstdlib>
// https://www.spoj.com/problems/CEQU/
// Tag(s): Teoría de números, ecuación lineal diofántica

int findAnySol(int a, int b, int c, int &, int &, int &);
int gcdExtended(int a, int b, int &, int &);

int main() {
    int t, a, b, c;
    int x, y, g;
    scanf("%d", &t);

    for (int i = 1; i <= t; i++) {
        scanf("%d %d %d",&a, &b, &c);
        if(findAnySol(a, b, c, x, y, g)) printf("Case %d: Yes\n", i);
        else printf("Case %d: No\n", i);
    }

    return 0;
}

int findAnySol(int a, int b, int c, int &x0, int &y0, int &gcd) {
    gcd = gcdExtended(a, b, x0, y0);
    if(c % gcd) return false;
    return true;
}

int gcdExtended(int a, int b, int &x, int &y) {
    if(a == 0) {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int d = gcdExtended(b % a, a, x1, y1);
    x = y1 - (b/a) * x1;
    y = x1;
    return d;
}
