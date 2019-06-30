#include <bits/stdc++.h>
// https://omegaup.com/arena/problem/Docentes-de-Excelencia-ASINUS#problems
using namespace std;

int main() {
    int numPub, nivelAcademico, experiencia, materias, averageYears;
    int niveDeIgnorancia;
    cin >> numPub >> nivelAcademico >> experiencia >> materias >> averageYears;

    if(materias == 0) cout << "ERROR" << endl;
    else {
        if(averageYears == 0) averageYears++;
        double ans = (sqrt(numPub) + (nivelAcademico*nivelAcademico + experiencia)) / (materias * averageYears);
        niveDeIgnorancia = ans;
        cout << niveDeIgnorancia << endl;
    }

    return 0;
}
