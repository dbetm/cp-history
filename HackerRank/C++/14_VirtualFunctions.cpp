#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Cuando en una clase declaramos una función como virtual, y la superponemos en
alguna clase derivada, al invocarla usando un puntero de la clase base, se
ejecutará la versión de la clase derivada.
*/

class Person {
    protected:
        string name;
        int age;
    public:
        virtual void getdata() {
            cin >> name >> age;
        }
        virtual void putdata() {
            cout << name << " " << age << endl;
        }
};

class Student : public Person {
    private:
        int cur_id;
        int marks[6];
    public:
        static int counter;
        Student() {
            this->cur_id = ++Student::counter;
        }
        void getdata() {
            cin >> name >> age;
            for (int i = 0; i < 6; i++) {
                cin >> this->marks[i];
            }
        }
        void putdata() {
            int sum = 0;
            for (int i = 0; i < 6; i++) {
                sum += this->marks[i];
            }
            cout << name << " " << age << " " << sum << " " << cur_id << endl;
        }
};

class Professor : public Person {
    private:
        int cur_id;
        int publications;
    public:
        static int counter;
        Professor() {
            this->cur_id = ++Professor::counter;
        }
        void getdata() {
            cin >> name >> age >> publications;
        }
        void putdata() {
            cout << name << " " << age << " " << publications << " " << cur_id << endl;
        }
};

int Student::counter = 0;
int Professor::counter = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
