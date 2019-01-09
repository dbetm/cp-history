#include <bits/stdc++.h>

using namespace std;
typedef unsigned long int uli;

int contarEnterosCuadrados(float, float);

int main(int argc, char* argv[]) {
    int T;
    float A, B;
    cin >> T;

    for (int i = 0; i < T; i++){
        cin >> A >> B;
        cout << contarEnterosCuadrados(A, B) << endl;
    }
    return 0;
}

int contarEnterosCuadrados(float A, float B) {
    int ans = 0;
    uli aux;
    uli a = round(sqrt(A)), b = round(sqrt(B));

    for (uli i = a; i <= b; i++) {
        aux = i*i;
        if(aux >= A and aux <= B) ans++;
    }
    return ans;
}
