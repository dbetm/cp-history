#include <bits/stdc++.h>
/* Es una estructura de datos en forma de árbol binario:
Casos prácticos de uso:
    + Consultar un elemento máximo o mínimo en un intervalo de un conjunto.
    + Modificar un elemento.
    + Modificar un intervalo de elementos.
*/
using namespace std;

class Node {
    private:
        int left;
        int right;
        int value;
    public:
        Node(int l, int r);
        void merge(Node leftChild, Node rightChild);
        ~Node();
};

Node::Node(int l, int r) {
    this->left = l;
    this->right = r;
}

void Node::merge(Node leftChild, Node rightChild) {
    if(leftChild) value = rightChild.value;
    else if(!rightChild) value = leftChild.value;
    // en este caso minimiza
    else value = min(leftChild.value, rightChild.value);
}

Node::~Node() {

}

class SegmentTree {
    private:
        int n;
        Node tree[];
    public:
        SegmentTree(int A[]);
        ~SegmentTree();
    private:
        void build(int node, int l, int r, int A[]);
};

SegmentTree::SegmentTree(int A[]) {
    this->n = A.length;
    // log_2(n)
    int power = (int) Math.floor(Math.log(A.length) / Math.log(2)) + 1;
    // len = 2^log_2(n)
    int len = (int) 2 * Math.pow(2, power);
    tree = new Node[len];
}

int main(int argc, char const *argv[]) {

    return 0;
}
