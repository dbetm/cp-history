#include <bits/stdc++.h>

using namespace std;

int binarySearch(int*, int*);

int A[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int target;

int main(int argc, char* argv[]) {
    int min = 0, max = (sizeof(A)/sizeof(*A)) - 1;
    int* ptrMin;
    int* ptrMax;
    ptrMin = &min;
    ptrMax = &max;
    cout << "Type the target: ";
    cin >> target;
    cout << binarySearch(ptrMin, ptrMax) << endl;
    return 0;
}

int binarySearch(int* min, int* max) {
    int guess = floor((*min + *max) / 2);
    if(*min > *max) return -1;
    else if(A[guess] == target) return guess;
    else if(A[guess] < target) *min = guess + 1;
    else *max = guess - 1;
    return binarySearch(min, max);
}
