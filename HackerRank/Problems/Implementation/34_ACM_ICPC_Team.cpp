#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/acm-icpc-team/problem
using namespace std;

void acmTeams(vector <string>);
int getMaxKnowledge(string, string);

int main() {
    int n, temas;
    cin >> n >> temas;
    vector <string> equipos(n);
    for (int i = 0; i < n; i++) cin >> equipos[i];
    acmTeams(equipos);
    return 0;
}

void acmTeams(vector <string> equipos) {
    int maxTopics = 0;
    int numEquipos = 0;
    for (unsigned int i = 0; i < equipos.size() - 1; i++) {
        for (unsigned int j = i+1; j < equipos.size(); j++) {
            int numTopics = getMaxKnowledge(equipos[i], equipos[j]);
            if(numTopics >= maxTopics) {
                if(numTopics == maxTopics) numEquipos++;
                else {
                    numEquipos = 1;
                    maxTopics = numTopics;
                }
            }
        }
    }
    cout << maxTopics << endl;
    cout << numEquipos << endl;
}

int getMaxKnowledge(string teamA, string teamB) {
    int knowledge = 0;
    for (unsigned int i = 0; i < teamA.size(); i++)
        if(teamA[i] == '1' || teamB[i] == '1') knowledge++;
    return knowledge;
}
