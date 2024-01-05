#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

// Imprimir los k elementos más pequeños de un arreglo de enteros no ordenado

using namespace std;

void printKSmallestElements(int *input, int n, int k);

int main() {
    int n, k;
    cout << "Type n: ";
    cin >> n;
    cout << "Type k: ";
    cin >> k;
    cout << "Type " << n << " element(s) of array." << endl;
    int array[n];
    for (int i = 0; i < n; ++i) cin >> array[i];

    printKSmallestElements(array, n, k);

    return 0;
}

void printKSmallestElements(int *input, int n, int k) {
    priority_queue<int> pq;

    for (int i = 0; i < n; ++i) {
        pq.push(input[i]);
        if((int)pq.size() > k) pq.pop();
    }

    // Print answer
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}
