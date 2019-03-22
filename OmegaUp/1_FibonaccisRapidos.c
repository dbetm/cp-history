// Fibonacci Series using Space Optimized Method
#include <stdio.h>
#define MAX 100000009
// está mal en la plataforma
unsigned long long fib(unsigned long long n) {
	unsigned long long a = 0, b = 1, c, i;
	if( n == 0) return a;
	for (i = 2; i <= n; i++){
		c = a%MAX + b%MAX;
		a = b;
		b = c;
	}
	return b%MAX;
}

int main () {
	unsigned long long n;
	scanf("%lld", &n);
	printf("%lld\n", fib(n));
	getchar();
	return 0;
}
