#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
// https://www.hackerrank.com/challenges/c-class-templates/problem
using namespace std;

#define cin ios_base::sync_with_stdio(false);cin.tie(NULL); cin
#define concatenate add

template <class T>
class AddElements {
    T element;
    public:
        AddElements(T &arg) {
            element = arg;
        }
        T add(T &arg) {
            return element + arg;
        }
};

template <>
class AddElements <string> {
    string element;
    public:
        AddElements(string &str) {
            element = str;
        }
        string concatenate(string &arg) {
            element.append(arg);
            return element;
        }
};

int main() {
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++) {
        string type;
        cin >> type;
        if(type == "float") {
            double element1, element2;
            cin >> element1 >> element2;
            AddElements<double> myFloat(element1);
            cout << myFloat.add(element2) << endl;
        }
        else if(type == "int") {
            int element1, element2;
            cin >> element1 >> element2;
            AddElements<int> myint(element1);
            cout << myint.add(element2) << endl;
        }
        else if(type == "string") {
            string element1, element2;
            cin >> element1 >> element2;
            AddElements<string> mystring(element1);
            cout << mystring.concatenate(element2) << endl;
        }
    }
}
