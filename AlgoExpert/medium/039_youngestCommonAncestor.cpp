#include <bits/stdc++.h>
// solved
// tags: implementation, trees
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl;

class AncestralTree {
    public:
        char name;
        AncestralTree* ancestor;

        AncestralTree(char name) {
            this->name = name;
            this->ancestor = nullptr;
        }

        void addAsAncestor(vector<AncestralTree*> descendants) {
            for(auto descendant : descendants) {
                descendant->ancestor = this;
            }
        }
};


AncestralTree* getYoungestCommonAncestor(
    AncestralTree* topAncestor,
    AncestralTree* descendantOne,
    AncestralTree* descendantTwo
) {
    /*My solution
    Time: O(v)
    Space: O(v)

    Where v is the number of nodes in the tree
    */
    set<AncestralTree*> setPath;
    AncestralTree* ans = topAncestor;

    auto a = descendantOne;
    while(a != nullptr) {
        setPath.insert(a);
        //watch(a->name)
        a = a->ancestor;
    }

    auto b = descendantTwo;
    while(b != nullptr) {
        auto pos = setPath.find(b);

        if(pos != setPath.end()) {
            ans = b;
            break;
        }

        //watch(b->name)
        b = b->ancestor;
    }

    return ans;
}

AncestralTree* getYoungestCommonAncestor2(
    AncestralTree* topAncestor,
    AncestralTree* descendantOne,
    AncestralTree* descendantTwo
) {
    /*Proposal
    Time: O(depth)
    Space: O(1)
    */
    auto a = descendantOne;
    int aDepth = 0;
    while(a != nullptr) {
        watch(a->name)
        a = a->ancestor;
        aDepth += 1;
    }

    auto b = descendantTwo;
    int bDepth = 0;
    while(b != nullptr) {
        watch(b->name)
        b = b->ancestor;
        bDepth += 1;
    }

    // match up level of depth of deepest descendant
    AncestralTree* x;
    AncestralTree* y;

    auto magico = [&](AncestralTree* target, int delta) {
        int cont = 0;
        while(cont < delta) {
            target = target->ancestor;
            cont += 1;
        }

        return target;
    };

    if(aDepth > bDepth) {
        x = magico(descendantOne, aDepth - bDepth);
        y = descendantTwo;
    }
    else {
        x = magico(descendantTwo, bDepth - aDepth);
        y = descendantOne;
    }

    watch(x->name)
    watch(y->name)

    while(x != y) {
        x = x->ancestor;
        y = y->ancestor;
    }

    return x;
}


int main(int argc, char const *argv[]) {
    AncestralTree top('A');

    auto b = new AncestralTree('B');
    auto c = new AncestralTree('C');
    top.addAsAncestor(vector<AncestralTree*>({b, c}));
    auto d = new AncestralTree('D');
    auto e = new AncestralTree('E');
    b->addAsAncestor(vector<AncestralTree*>({d, e}));
    auto h = new AncestralTree('H');
    auto i = new AncestralTree('I');
    d->addAsAncestor(vector<AncestralTree*>({h, i}));
    auto f = new AncestralTree('F');
    auto g = new AncestralTree('G');
    c->addAsAncestor(vector<AncestralTree*>({f, g}));

    auto ans = getYoungestCommonAncestor2(&top, e, i);
    
    if(ans) cout << ans->name << endl;
    else cout << ans << endl;

    return 0;
}
