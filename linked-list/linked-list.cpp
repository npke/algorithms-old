#include <iostream>
#include <string>

using namespace std;

struct Node {
    int key;
    Node* pNext;
};


void add(Node* &linkedList, int key) {
    Node* p = new Node;
    p->key = key;
    p->pNext = NULL;
    
    Node* p1 = linkedList;
    while (p1->pNext != NULL) {
        p1 = p1->pNext;
    }
    
    p1->pNext = p;
}

void printLinkedList(Node* linkedList) {
    while (linkedList != NULL) {
        cout << linkedList->key << " ";
        linkedList = linkedList->pNext;
    }
}

void insert(Node* &linkedList, int value, int key) {
    Node* p = linkedList;
    while (p->key != key) {
        p = p->pNext;
    }
    
    Node* p1 = new Node();
    p1->key = value;
    p1->pNext = p->pNext;
    p->pNext = p1;
}

void insert2(Node* &linkedList, int value, int key) {
    Node* p = linkedList;
    while (p->pNext->key != key) {
        p = p->pNext;
    }
    
    Node* p1 = new Node();
    p1->key = value;
    p1->pNext = p->pNext;
    p->pNext = p1;
}

void deleteNode(Node* &linkedList, int value) {
    Node* p = linkedList;
    while (p->pNext->key != value) {
        p = p->pNext;
    }
    
    Node* p1 = p->pNext;
    p->pNext = p1->pNext;
    delete p1;
    
}

int main() {
    
    Node* linkedList = new Node;
    linkedList->key = 10;
    linkedList->pNext = NULL;
    
    add(linkedList,20);
    add(linkedList,13);
    add(linkedList,95);
    add(linkedList,47);
    insert(linkedList, 90, 95);
    insert2(linkedList, 90, 95);
    deleteNode(linkedList, 13);
    
    printLinkedList(linkedList);
    
    return 0;
}