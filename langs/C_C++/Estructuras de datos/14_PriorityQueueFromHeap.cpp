#include <iostream>
#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>
// Time complexity: O(n log (n))
// Space complexity: O(n)
using namespace std;


class PriorityQueue {
    private:
        vector<int> pq;
    public:
        PriorityQueue();
        ~PriorityQueue();
        int getMin();
        bool isEmpty();
        int getSize();
        void insert(int val);
        void pop();
};

PriorityQueue::PriorityQueue() {};

PriorityQueue::~PriorityQueue() {
    this->pq.clear();
};

int PriorityQueue::getMin() {
    if(this->isEmpty()) return 0;

    return this->pq[0];
}

bool PriorityQueue::isEmpty() {
    return this->pq.empty();
}

int PriorityQueue::getSize() {
    return this->pq.size();
}

void PriorityQueue::insert(int val) {
    this->pq.push_back(val);
    // We need to do bubble up in order to keep min heap property
    int childIndex = this->pq.size() - 1;
    int parentIndex = (childIndex - 1) / 2;

    while(childIndex > 0 and this->pq[childIndex] < this->pq[parentIndex]) {
        swap(this->pq[childIndex], this->pq[parentIndex]);
        childIndex = parentIndex;
        parentIndex = (childIndex - 1) / 2;
    }
}

// Heap Min: Delete "root"
void PriorityQueue::pop() {
    if(this->isEmpty()) return;

    swap(this->pq[0], this->pq[this->getSize() - 1]);
    this->pq.pop_back(); // delete min

    if(this->isEmpty()) return;

    int n = this->getSize();

    // Bubble down
    int index = 0;
    while((2 * index + 1) < n) {
        int leftChild = this->pq[2*index+1];
        int rightChild = INT_MAX;
        if((2 * index + 2) < n) rightChild = this->pq[2*index+2];

        if(rightChild <= leftChild and this->pq[index] > this->pq[2*index+2]) {
            swap(this->pq[index], this->pq[2*index+2]);
            index = 2 * index + 2;
        }
        else if(leftChild < rightChild and this->pq[index] > this->pq[2*index+1]) {
            swap(this->pq[index], this->pq[2*index+1]);
            index = 2 * index + 1;
        }
        else {
            break;
        }
    }
}

int main() {
    PriorityQueue pq;
    int n = 7;
    int elements[] = {100, 10, 15, 4, 17, 21, 67};
    for(int i = 0; i < n; ++i) pq.insert(elements[i]);

    cout << "Size of priority queue: " << pq.getSize() << endl;

    while(!pq.isEmpty()) {
        cout << pq.getMin() << " ";
        pq.pop();
    }
    cout << endl;

    cout << "Size of priority queue: " << pq.getSize() << endl;

    /* Se puede hacer Inplace Heap Sort IHS, al usar el arreglo elements
    en pq en lugar de crear un vector interno, simplemente se van ordenando, primero
    considerando un elementos, luego, dos, luego tres, ...

    En el proceso de borrar, solo se van ignorando los elementos en lugar de hacer
    pop_back(), y al final se tendra elements con los elementos ordenados en orden
    descenente.
    */

    return 0;
}
