#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
// https://www.hackerrank.com/challenges/classes-objects/problem
using namespace std;

// Write your Student class here
class Student {
    private:
        vector <int> scores;
    public:
        Student();
        void input();
        int calculateTotalScore();
        ~Student();
};

Student::Student() {
}

void Student::input() {
    int aux;
    for (int i = 0; i < 5; i++) {
        cin >> aux;
        scores.push_back(aux);
    }
}

int Student::calculateTotalScore() {
    int sumaTotal = 0;
    for(int i = 0; i < 5; i++) {
        sumaTotal += scores[i];
    }
    return sumaTotal;
}

Student::~Student() {
    if(!this->scores.empty()) this->scores.clear();
}

int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students

    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0;
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;

    return 0;
}
