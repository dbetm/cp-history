#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/rompiendo-el-sistema-rsa#problems
using namespace std;

pair<long long, long long> primesFactors(long long);
long long modInverse(long long, long long);
long long gcdExtended(long long, long long, long long *, long long *);
vector<int> toBinary(long long);
long long exec_pow(long long, vector<int>, long long);
string decript(long long, long long, vector<long long>);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int lenCripto;
    long long e; //Llave pública.
    long long n; //Módulo de crifra.
    long long cripto;
    vector<long long> criptograma;

    ///Leer los datos.
    cin >> e >> n >> lenCripto;

    for(long int i = 0; i < lenCripto; i++) {
        cin >> cripto;
        criptograma.push_back(cripto);
    }
    //Factorizar el modulo de cifra.
    pair<long long, long long> factors = primesFactors(n);
    long long p = factors.first;
    long long q = factors.second;

    //Calcular la llave privada.
    long long d = modInverse(e, (p - 1) * (q - 1));

    ///descifrar.
    cout << decript(d, n, criptograma) << endl;

    return 0;
}

pair<long long, long long> primesFactors(long long num) {
    pair<long, long> factors;
    long long p = 1;
    long long q;
    long long r;

    do {
        p++;
        q = num / p;
        r = num % p;
    } while(r);

    factors.first = p;
    factors.second = q;

    return factors;
}

long long modInverse(long long num, long long body) {
    ///las variables 'y' son las de la tabla del algoritmo de euclides extentido.
    long long y_0 = 0;///El primer valor de 'y' sub 'i' de la tabla ('y' sub 0).
    long long y_1 = 1;///El segundo valor de 'y' sub 'i' de la tabla ('y' sub 1).
    long long r_body = body;

    while(num) {
        ///Calcula el cociente y el residuo para continar la tabla.
        long long temp = num;
        long long quotient = body / num;
        num = body % num;
        body = temp;

        ///Calcula la siguiente 'y'.
        temp = y_1;
        y_1 = y_0 - quotient * y_1;
        y_0 = temp;
    }

    return (y_0 < 0) ? (y_0 + r_body) : (y_0);
}

vector<int> toBinary(long long num) {
    vector<int> binary;
    do {
        binary.push_back(num % 2);
        num /= 2;
    } while(num);

    return binary;
}


long long exec_pow(long long base, vector<int> exp, long long mod) {
    long long current = base;
    long long total = 1;
    for(register int i = 0, l = exp.size(); i < l; i++) {
        if(exp[i]) {
            total = (total * current) % mod;
        }
        current = (current * current) % mod;
    }

    return total;
}

string decript(long long d, long long n, vector<long long> C) {
    vector<int> exp = toBinary(d);
    string N;

    for(long long i = 0, l = C.size(); i < l; i++)
        N.push_back(exec_pow(C[i], exp, n));

    return N;
}
