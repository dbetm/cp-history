#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

/* ¿Qué es un K Sorted Array?
Es un arreglo cuyos elementos están a lo más k-1 desde el índice al índice
que corresponde cuando se ordenan de forma descendente. La K respecto a N es
relativamente pequeña, 2 <= K <= 20, 2 <= N <= 1e^5.
Ejemplo:
k = 3
indíces: [0,  1,  2,  3,  4]
          |   |   |   |   |
input:   [10, 12, 6,  7,  9]

output:  [12, 10, 9,  7,  6]
diffs:   [1,  1,  2,  0,  2]

max(diffs): 2 y 2 < k = 3

Una posible solución para ordernar sería usar el sort in-inbuilt, con una
complejidad en tiempo:
O(N * log(N))

Sin embargo, podemos aprovechar que es un K sorted array y usar una cola de prioridad
y así tener una complejidad en tiempo:
O(N)

*/

using namespace std;

void sortKSortedArray(int *input, int n, int k);

int main() {
    int n, k;
    cout << "Type n: ";
    cin >> n;
    cout << "Type k: ";
    cin >> k;
    cout << "Type " << n << " element(s) of array." << endl;
    int array[n];
    for (int i = 0; i < n; ++i) cin >> array[i];

    sortKSortedArray(array, n, k);

    for (int i = 0; i < n; ++i) cout << array[i] << " ";
    cout << endl;

    return 0;
}

void sortKSortedArray(int *input, int n, int k) {
    priority_queue<int> pq;

    for (int i = 0; i < k; ++i) {
        pq.push(input[i]);
    }

    int beginningWin = 0, endWin;

    for (endWin = k; endWin < n; ++endWin) {
        input[beginningWin] = pq.top();
        pq.pop();
        ++beginningWin;
        pq.push(input[endWin]);
    }

    while(!pq.empty()) {
        input[beginningWin] = pq.top();
        pq.pop();
        ++beginningWin;
    }
}
