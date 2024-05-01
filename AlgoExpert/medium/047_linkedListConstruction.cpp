#include <bits/stdc++.h>
// solved
// tags: linked-list, data-structures
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl;
#define watch2(x, y) cout << (#x) << " is " << (x) << ", " << (#y) << " is " << (y) << endl;

class Node {
    public:
        int value;
        Node* prev;
        Node* next;

        Node(int value) {
            this->value = value;
            this->prev = nullptr;
            this->next = nullptr;
        }
};

class DoublyLinkedList {
    // My proposal
    public:
        Node* head;
        Node* tail;

        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
        }

        void setHead(Node* node) {
            // Time: O(n)
            // Space: O(1)
            cout << "setHead" << endl;
            if(node == this->head) return;
            else if(this->head == nullptr) {
                this->head = node;
                this->tail = node;
                return;
            }

            if(this->containsNode(node)) {
                this->disconnect(node);
            }

            Node* oldHead = this->head;
            this->head = node;

            node->next = oldHead;
            node->prev = nullptr;
            if(this->head) oldHead->prev = node;
        }

        void setTail(Node* node) {
            // Time: O(n)
            // Space: O(1)
            cout << "setTail" << endl;
            if(node == this->tail) return;

            if(this->containsNode(node)) {
                this->disconnect(node);
            }

            if(this->tail == nullptr) {
                this->tail = node;

                if(this->head) {
                    this->head->next = this->tail;
                    this->tail->prev = this->head;
                }
                else this->head = node;
            }
            else {
                Node* oldTail = this->tail;
                this->tail = node;

                node->next = nullptr;
                node->prev = oldTail;
                oldTail->next = node;
            }
        }

        void insertBefore(Node* node, Node* nodeToInsert) {
            // Time: O(n)
            // Space: O(1)
            cout << "insertBefore" << endl;
            if(this->containsNode(nodeToInsert)) {
                this->disconnect(nodeToInsert);
            }

            auto tmp = this->head;
            while(tmp != node) {
                tmp = tmp->next;
            }

            cout << "  found " << tmp->value << endl;

            watch2(tmp->prev, tmp->next)

            nodeToInsert->prev = tmp->prev;
            nodeToInsert->next = tmp;
            
            if(tmp->prev != nullptr) tmp->prev->next = nodeToInsert;

            tmp->prev = nodeToInsert;

            if(node == this->head) this->head = nodeToInsert;
        }

        void insertAfter(Node* node, Node* nodeToInsert) {
            // Time: O(n)
            // Space: O(1)
            cout << "insertAfter" << endl;
            if(this->containsNode(nodeToInsert)) {
                this->disconnect(nodeToInsert);
            }

            auto tmp = this->head;
            while(tmp != node) {
                tmp = tmp->next;
            }

            nodeToInsert->next = tmp->next;
            tmp->next = nodeToInsert;
            nodeToInsert->prev = tmp;

            if(nodeToInsert->next) nodeToInsert->next->prev = nodeToInsert;

            if(node == this->tail) {
                this->tail = nodeToInsert;
            }
        }

        void insertAtPosition(int position, Node* nodeToInsert) {
            // Time: O(n)
            // Space: O(1)
            cout << "insertAtPosition" << endl;

            if(this->head == nullptr) return this->setHead(nodeToInsert);

            int cont = 1;
            auto tmp = this->head;

            while(cont < position and tmp != nullptr) {
                tmp = tmp->next;
                cont += 1;
            }

            if(tmp == nodeToInsert) return;

            if(this->containsNode(nodeToInsert)) {
                this->disconnect(nodeToInsert);
            }

            if(tmp == nullptr) return;
            watch2(tmp->value, nodeToInsert->value)
            
            this->insertBefore(tmp, nodeToInsert);
        }

        void removeNodesWithValue(int value) {
            // Time: O(n)
            // Space: O(1)
            cout << "removeNodesWithValue" << endl;
            auto tmp = this->head;

            while(tmp != nullptr) {
                if(tmp->value == value) {
                    auto toDelete = disconnect(tmp);
                }

                tmp = tmp->next;
            }
        }

        void remove(Node* node) {
            // Time: O(1)
            // Space: O(1)
            cout << "remove" << endl;
            auto toDelete = disconnect(node);

            watch2(toDelete, toDelete->value);
        }

        bool containsNodeWithValue(int value) {
            // Time: O(n)
            // Space: O(1)
            cout << "containsNodeWithValue" << endl;
            auto tmp = this->head;

            while(tmp != nullptr) {
                if(tmp->value == value) return true;

                tmp = tmp->next;
            }

            return false;
        }

        void print() {
            cout << "print" << endl;
            watch2(this->head, this->head->value);
            watch2(this->tail, this->tail->value);
            Node* tmp = this->head;
            int cont = 0;

            while(tmp != nullptr) {
                cout << tmp->value << "<->";
                tmp = tmp->next;

                cont += 1;
                if(cont > 15) break;
            }
            cout << endl;
        }

    private:
        bool containsNode(Node* node) {
            cout << "containsNode" << endl;
            auto tmp = this->head;

            while(tmp != nullptr) {
                if(tmp == node) {
                    return true;
                }
                tmp = tmp->next;
            }

            return false;
        }

        Node* disconnect(Node* node) {
            cout << "disconect" << endl;

            if(node == this->tail) {
                if(node != this->head) node->prev->next = nullptr;
                else this->head = nullptr;

                this->tail = node->prev;
            }
            else if(node == this->head) {
                this->head = this->head->next;
                this->head->prev = nullptr;
            }
            else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }

            return node;
        }
};


int main() {
    DoublyLinkedList list;

    /* Test case # 1
    Node one(1);
    Node two(2);
    Node three(3);
    Node four(4);
    Node five(5);
    Node six(6);
    Node threeV2(3);
    Node threeV3(3);

    list.setHead(&one);
    list.setTail(&one);

    list.insertAfter(&one, &two);
    list.insertAfter(&two, &three);
    list.insertAfter(&three, &four);
    list.insertAfter(&four, &five);

    list.print();

    list.setHead(&four);
    list.setTail(&six);

    list.print();

    list.insertBefore(&six, &three);
    list.print();
    list.insertAfter(&six, &threeV2);
    list.print();

    list.insertAtPosition(1, &threeV3);
    list.print();

    list.removeNodesWithValue(3);
    list.print();

    list.remove(&two);
    list.print();

    cout << list.containsNodeWithValue(50) << endl;

    */

    /* TEST CASE #12 */
    Node one(1);
    Node two(2);
    Node three(3);
    Node four(4);

    list.setTail(&one);
    list.insertBefore(&one, &two);
    list.print();

    list.insertBefore(&two, &three);
    list.print();

    list.insertBefore(&three, &four);
    list.print();

    list.setHead(&one);
    list.print();

    return 0;
}

