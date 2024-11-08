#include <bits/stdc++.h>
// https://leetcode.com/problems/design-hashmap/
// Tag(s): data structures, hashing
using namespace std;
#define watch(x) cout << (#x) << " is " << x << endl;

/* 10^4 worst case (everything is put)
load_factor = num_elements / num_buckets
load_factor = 10⁴ / num_buckets
num_buckets = 10⁴ / 0.75
num_buckets = 13,333
*/
const int MAX = 13333;

struct Node {
    int key;
    int val;
    Node *next;
    Node(int key, int val): key(key), val(val), next(nullptr) {}
    Node(int key, int val, Node *next): key(key), val(val), next(next) {}
    ~Node() {
        this->next = nullptr;
    }
};

class MyHashMap {
private:
    Node **buckets;
    const int P = 37;

    int hashing(int key) {
        int index = ((key % MAX) * this->P) % MAX;
        return index;
    }
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        this->buckets = new Node*[MAX];
        for (int i = 0; i < MAX; i++) {
            this->buckets[i] = nullptr;
        }
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = this->hashing(key);
        Node *head = this->buckets[index];

        while(head != nullptr) {
            if(head->key == key) {
                head->val = value;
                return;
            }
            head = head->next;
        }
        Node *item = new Node(key, value);
        item->next = head;
        // put at head
        this->buckets[index] = item;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = this->hashing(key);
        int ans = -1;

        Node *head = this->buckets[index];
        while(head != nullptr) {
            if(head->key == key) {
                ans = head->val;
                break;
            }
            head = head->next;
        }

        return ans;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = this->hashing(key);

        Node *head = this->buckets[index];
        Node *prev = head;
        while(head != nullptr) {
            if(head->key == key) {
                if(head == this->buckets[index]) { // head
                    this->buckets[index] = head->next;
                    delete(head);
                }
                else { // at the tail or in the middle
                    prev->next = head->next;
                    delete(head);
                }
                break;
            }
            prev = new Node(head->key, head->val, head->next);
            head = head->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
/*
["MyHashMap","remove","get","put","put","put","get","put","put","put","put"]
[[],[14],[4],[7,3],[11,1],[12,1],[7],[1,19],[0,3],[1,8],[2,6]]
*/

int main() {
    cout << MAX << endl;
    MyHashMap hashMap;
    // TEST CASE 2
    hashMap.remove(14);
    cout << hashMap.get(4) << endl;
    hashMap.put(7, 3);
    hashMap.put(11, 1);
    hashMap.put(12, 1);
    cout << hashMap.get(7) << endl;
    hashMap.put(1, 19);
    hashMap.put(0, 3);
    hashMap.put(1, 8);
    hashMap.put(2, 6);

    /* TEST CASE 1
    hashMap.put(1, 1);
    hashMap.put(2, 2);
    cout << hashMap.get(1) << endl;
    cout << hashMap.get(3) << endl;
    hashMap.put(2, 1);
    cout << hashMap.get(2) << endl;
    hashMap.remove(2);
    cout << hashMap.get(2) << endl;
    */

    return 0;
}
