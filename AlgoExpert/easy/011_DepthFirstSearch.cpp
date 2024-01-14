#include <bits/stdc++.h>
// solved
// tags: recursion, dfs, DAG
using namespace std;
#define watch(x) cout << (#x) << " es " << (x) << endl;
typedef long long int lli;
lli MAX = 1e9+7;


class Node {
    public:
        string name;
        vector<Node*> children;

        Node(string str) { name = str; }

        void dfs(Node *node, vector<string>* array) {
            if(node->children.empty()) {
                array->push_back(node->name);
                return;
            }

            array->push_back(node->name);

            for(auto child : node->children) {
                dfs(child, array);
            }
        }

        vector<string> depthFirstSearch(vector<string>* array) {
            Node *node = this;

            dfs(node, array);

            return *array;
        }

        Node* addChild(string name) {
            Node* child = new Node(name);
            children.push_back(child);
            return this;
        }
};

int main() {
    // first level
    Node* nodeA = new Node("A");
    // second level
    auto nodeB = nodeA->addChild("B")->children[0];
    auto nodeC = nodeA->addChild("C")->children[1];
    auto nodeD = nodeA->addChild("D")->children[2];
    // third level
    nodeB->addChild("E");
    auto nodeF = nodeB->addChild("F")->children[1];;
    auto nodeG = nodeD->addChild("G")->children[0];;
    nodeD->addChild("H");
    // fourth level
    nodeF->addChild("I");
    nodeF->addChild("J");
    nodeG->addChild("K");

    vector<string> ans;
    nodeA->depthFirstSearch(&ans);

    for(string name : ans) {
        cout << name << ", ";
    }
    cout << endl;

	return 0;
}
