#include <iostream>
#include <cstdlib>
#include <climits>
#define D 6
// https://www.hackerrank.com/challenges/2d-array/problem
using namespace std;

class Pat {
    private:
        int max;
        int A[D][D];
    public:
        Pat();
        void leer();
        int recorrer();
        ~Pat();
}Pattern;

Pat::Pat() {
    this->max = -100000;
}

void Pat::leer() {
    for (int i = 0; i < D; i++) {
        for (int j = 0; j < D; j++) {
            cin >> A[i][j];
        }
    }
}

int Pat::recorrer() {
    int aux = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            aux = 0;
            aux += A[i][j];
            aux += A[i][j+1];
            aux += A[i][j+2];
            aux += A[i+1][j+1];
            aux += A[i+2][j];
            aux += A[i+2][j+1];
            aux += A[i+2][j+2];
            if(aux > max) {
                max = aux;
            }
        }
    }
    return max;
}

Pat::~Pat() {
    for (int i = 0; i < D; i++) {
        for (int j = 0; j < D; j++) {
            A[i][j] = 0;
        }
    }
}

int main(int argc, char const *argv[]) {
    Pattern.leer();
    cout << Pattern.recorrer() << endl;
    return 0;
}
