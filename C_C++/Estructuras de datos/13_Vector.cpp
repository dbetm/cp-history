#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<int> *vp = new vector<int>(); // Dynamically, manual deleting

    vector<int> v; // static, auto (scope way) deleting
    v.push_back(10);
    v.push_back(22);
    v.push_back(25);
    v.push_back(42);

    // Safer access with at() function
    cout << v.at(3) << endl;
    // No safer with []
    cout << v[4] << endl;

    // Safer access with at() function -- error
    // cout << v.at(4) << endl;

    // Capacity, how many elements we can insert into vector,
    // every size two-multiple duplicates the Capacity, example

    for (int i = 0; i < 100; i++) {
        cout << "Capacity: " << vp->capacity() << endl;
        cout << "Size: " << vp->size() << endl;
        vp->push_back(i+1);
    }


    return 0;
}
