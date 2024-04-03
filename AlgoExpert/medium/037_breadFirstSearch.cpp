#include <bits/stdc++.h>

using namespace std;

// Do not edit the class below except
// for the breadthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
    public:
        string name;
        vector<Node*> children;

        Node(string str) { name = str; }

        vector<string> breadthFirstSearch(vector<string>* array) {
            queue<Node*> q;
            q.push(this);
            q.push(NULL);

            while(!q.empty()) {
                auto current = q.front();
                q.pop();

                if(current == NULL) {
                    if(!q.empty()) {
                        q.push(NULL);
                    }
                }
                else {
                    array->push_back(current->name);
                    for(auto child : current->children) {
                        q.push(child);
                    }
                }
            }

            return *array;
        }

        Node* addChild(string name) {
            Node* child = new Node(name);
            children.push_back(child);
            return child;
        }
};


int main() {
    Node tree("A");

    auto b = tree.addChild("B");
    tree.addChild("C");
    auto d = tree.addChild("D");

    b->addChild("E");
    auto f = b->addChild("F");
    f->addChild("I");
    f->addChild("J");

    auto g = d->addChild("G");
    d->addChild("H");
    g->addChild("K");

    vector<string> ans;
    tree.breadthFirstSearch(&ans);

    int n = ans.size();

    for (int i = 0; i < n; i++) {
        cout << ans[i] << ", ";
    }
    cout << endl;

    return 0;
}
