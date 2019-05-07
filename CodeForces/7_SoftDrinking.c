#include <stdlib.h>
#include <stdio.h>
// https://codeforces.com/contest/151/problem/A
typedef long long int lli;

lli min(lli a, lli b) {
    return (a > b) ? b : a;
}

int main() {
    lli n, k, l, c, d, p, nl, np;

    scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&n,&k,&l,&c,&d,&p,&nl,&np);
    lli res = min(min(k*l / nl, c*d), p/np) / n;
    printf("%lld\n", res);

    return 0;
}
