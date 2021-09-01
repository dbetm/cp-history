#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

#define watch(x) cout << (#x) << " es " << endl;

class Hanoi {
    private:
        stack<int> A;
        stack<int> B;
        stack<int> C;
        int numDisks;
        long long int cont;
        void commit(char origin, char destination, int disk);
        int top(char nameStack);
        void pop(char nameStack);
        void insert(char nameStack, int val);
        // bool isCompleted(char origin, char destination, int n);
    public:
        Hanoi(int numDisks);
        void simulate(char origin, char destination, char helper, int n);
        ~Hanoi();
};

Hanoi::Hanoi(int numDisks) {
    this->cont = 0;
    this->numDisks = numDisks;
    for (int i = this->numDisks; i > 0; --i) {
        this->A.push(i);
    }
}

void Hanoi::simulate(char origin, char destination, char helper, int n) {
    if(n == 0) return;

    simulate(origin, helper, destination, n-1);

    int disk = this->top(origin);
    this->pop(origin);

    this->commit(origin, destination, disk);
    this->insert(destination, disk);

    simulate(helper, destination, origin, n-1);
}

int Hanoi::top(char nameStack) {
    if(nameStack == 'A') return this->A.top();
    else if(nameStack == 'B') return this->B.top();

    return this->C.top();
}

void Hanoi::pop(char nameStack){
    if(nameStack == 'A') this->A.pop();
    else if(nameStack == 'B') this->B.pop();
    else this->C.pop();
}

void Hanoi::insert(char nameStack, int val) {
    if(nameStack == 'A') this->A.push(val);
    else if(nameStack == 'B') this->B.push(val);
    else this->C.push(val);
}

void Hanoi::commit(char origin, char destination, int disk) {
    this->cont++;
    cout << "Move #" << this->cont << ": " << disk << " from " << origin << " to " << destination << endl;
}

Hanoi::~Hanoi() {
    cout << "-----------------------\nA: ";
    while(!this->A.empty()) {
        cout << this->A.top() << " ";
        this->A.pop();
    }
    cout << "\nB: ";
    while(!this->B.empty()) {
        cout << this->B.top() << " ";
        this->B.pop();
    }
    cout << "\nC: ";
    while(!this->C.empty()) {
        cout << this->C.top() << " ";
        this->C.pop();
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Type n: ";
    cin >> n;
    Hanoi hanoi(n);
    hanoi.simulate('A', 'C', 'B', n);

    return 0;
}
