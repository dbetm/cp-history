#include <bits/stdc++.h>

using namespace std;
/*
An array A contains all the integers from 0 to n except for one number which is
missing. We cannot access an integer integer in A with a single operation.
The elements of A are represented in binary, and the only operation we can use
to access them is "fetch the jth bit of A[i]" which takes constant time.
- How can we find the missing integer in O(n) time?
- Checking the pattern that it will follows the sequential numbers, i.e.
flipping the least significant bit.
*/

int getFirstBit(int x) {
    return x & 1;
}


/*Iterate over the array A, missing one number,
because the numbers are sorted, the sequence of the least significant bit
is 0, 1, 0, 1...so, when this patterns breaks, that indicates the missing
number.
*/
int findMissingInteger(vector<int> &a) {
    int n = a.size();
    int ans = n;
    bool pairNumber = true;

    for (auto i = 0; i < n; ++i) {
        // It follows an even number, but an odd number was found
        if(pairNumber and getFirstBit(a[i]) == 1) {
            ans = i;
            break;
        }
        // It follows an odd number, but and even number was found
        if(!pairNumber and getFirstBit(a[i]) == 0) {
            ans = i;
            break;
        }

        pairNumber = !pairNumber;
    }

    return ans;
}


int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << "Missing: " << findMissingInteger(a) << endl;

    return 0;
}
