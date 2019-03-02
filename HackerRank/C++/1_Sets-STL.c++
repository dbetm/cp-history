#include <bits/stdc++.h>
using namespace std;
// https://www.hackerrank.com/challenges/cpp-sets/problem
/*
set <int> s; //Creates a set of integers.
int length=s.size(); //Gives the size of the set.
s.insert(x); //Inserts an integer x into the set s.
s.erase(val); //Erases an integer val from the set s.
set<int>::iterator itr=s.find(val); //Gives the iterator to the element val if it is found otherwise returns s.end() .
Ex: set<int>::iterator itr=s.find(100); //If 100 is not present then it==s.end().
*/
int main(int argc, char const *argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int queries, x, y;
    set <int> s;
    cin >> queries;

    for (int i = 0; i < queries; i++) {
        cin >> x >> y;
        switch (x) {
            case 1:
                s.insert(y);
                break;
            case 2:
                if(s.find(y) != s.end()) s.erase(y);
                break;
            default:
                if(s.find(y) != s.end()) cout << "Yes\n";
                else cout << "No\n";
        }
    }
    return 0;
}
