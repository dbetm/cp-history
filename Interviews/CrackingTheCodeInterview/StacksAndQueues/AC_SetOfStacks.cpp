#include <bits/stdc++.h>

using namespace std;

#define watch(x) cout << (#x) << " is " << x << endl;

class SetOfStacks {
    private:
        vector<stack<int>> stacks;
        int threshold;
    public:
        SetOfStacks(int threshold);
        void push(int data);
        int top();
        void pop();
        void popAt(int index);
        void printNumberStacks();
        void printTops();
        bool isEmpty();
        ~SetOfStacks();
};

SetOfStacks::SetOfStacks(int threshold=10) {
    this->threshold = threshold;
    this->stacks.push_back(stack<int>());
}

void SetOfStacks::push(int data) {
    if((int)this->stacks.back().size() == this->threshold) {
        this->stacks.push_back(stack<int>());
    }

    this->stacks.back().push(data);
}

int SetOfStacks::top() {
    if(!this->stacks.back().empty()) {
        return this->stacks.back().top();
    }

    return INT_MIN;
}

void SetOfStacks::pop() {
    if(this->stacks.back().empty() and this->stacks.size() == 1) {
        return;
    }

    this->stacks.back().pop();

    if(this->stacks.back().empty() and this->stacks.size() > 1) {
        this->stacks.pop_back();
    }
}

void SetOfStacks::popAt(int index) {
    if(this->stacks[index].empty()) return;

    this->stacks[index].pop();

    if(this->stacks[index].empty() and index == (int)(this->stacks.size() - 1)) {
        this->stacks.pop_back();
    }
    else {
        SetOfStacks setStacks(this->threshold);

        for (int i = index + 1; i < (int)this->stacks.size(); i++) {
            stack<int> aux = this->stacks[i];

            while(!aux.empty()) {
                setStacks.push(aux.top());
                aux.pop();
            }
        }

        int x = this->stacks.size() - (index + 1);
        // Delete stacks from original set of stacks
        while(x--) {
            this->stacks.pop_back();
        }

        vector<int> dataItems;
        while(!setStacks.isEmpty()) {
            dataItems.push_back(setStacks.top());
            setStacks.pop();
        }

        int len = dataItems.size();
        for (int i = len - 1; i >= 0; i -= this->threshold) {
            for (int j = max(0, i - this->threshold + 1); j <= i; j++) {
                this->push(dataItems[j]);
            }
        }
    }
}

void SetOfStacks::printNumberStacks() {
    int numberStacks = this->stacks.size();
    if(this->stacks.back().size() == 0) {
        cout << "Number of stacks: " << numberStacks - 1 << endl;
    }
    else {
        cout << "Number of stacks: " << numberStacks << endl;
    }
}

void SetOfStacks::printTops() {
    int n = this->stacks.size();

    for (int i = 0; i < n; i++) {
        if(this->stacks[i].size() > 0) {
            cout << "Stack #" << i+1 << ": " << this->stacks[i].top() << endl;
        }
    }
}

bool SetOfStacks::isEmpty() {
    return this->stacks.empty() or (this->stacks.size() == 1 and this->stacks[0].empty());
}

SetOfStacks::~SetOfStacks() {
    if(!this->stacks.empty()) {
        this->stacks.clear();
    }
}

int main() {
    int threshold;
    cout << "Type threshold: ";
    cin >> threshold;
    cout << "Type n: ";
    SetOfStacks setStacks(threshold);
    int n, data;
    cin >> n;

    cout << "Type the elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> data;
        setStacks.push(data);

        if((i+1) % threshold == 0) setStacks.printNumberStacks();
    }
    setStacks.printTops();

    setStacks.popAt(0);

    setStacks.printNumberStacks();

    setStacks.printTops();

    while(!setStacks.isEmpty()) {
        cout << setStacks.top() << endl;
        setStacks.pop();
    }

    return 0;
}
