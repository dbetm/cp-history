#include <iostream>

using namespace std;

int main() {
	long int n, m, area, mayor, menor;
	long int cont = 0;

	scanf("%ld %ld", &n, &m);

	area = n * m;

    if(n % m == 0 && n >= m) {
        cont = n / m;
    }
    else if(m % n == 0 && m > n) {
        cont = m / n;
    }
    else {
        while(area > 0) {
            if(n % m == 0 && n >= m) {
                cont += (n / m);
                break;
            }
            else if(m % n == 0 && m > n) {
                cont += (m / n);
                break;
            }
            mayor = max(n, m);
            menor = min(n, m);

    		area -= menor * menor;
    		n = mayor - menor;
    		m = menor;
    		cont++;
    	}
    }

	printf("%ld\n", cont);
	return 0;
}
