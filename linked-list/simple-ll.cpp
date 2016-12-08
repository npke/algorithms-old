#include <iostream>
#include <string>

using namespace std;

struct Node {
    int key;
    Node *pNext;
};

struct SimpleLinkedList {
    int count = 0;
    Node *pHead;
};

void addToLinkedList(SimpleLinkedList &list, int key)
{
    Node *p = new Node;
    p->key = key;
    
    p->pNext = list.pHead;
    list.pHead = p;
    list.count++;
}

void printLinkedList(SimpleLinkedList list)
{
    for (Node *p = list.pHead; p != NULL; p = p->pNext)
        cout << p->key << " ";
        cout << endl;
}

void addToEndLinkedList(SimpleLinkedList &list, int key)
{
    Node *pNew = new Node;
    pNew->key = key;
    pNew->pNext = NULL;
    
    if (list.pHead == NULL) 
       list.pHead = pNew;
    else 
    {
        Node *p = list.pHead;
        while (p->pNext != NULL)
            p = p->pNext;
        p->pNext = pNew;
    }
}

void deleteNodeLinkedList(SimpleLinkedList &list, int key)
{
    Node *p = list.pHead;
    while (p->pNext->key != key)
        p = p->pNext;
    Node *p1 = p->pNext;
    p->pNext = p1->pNext;
    delete p1;
        
}


int main()
{
    SimpleLinkedList list;
    addToEndLinkedList(list, 10);
    addToEndLinkedList(list, 45);
    addToEndLinkedList(list, 100);
    addToEndLinkedList(list, 125);
    addToEndLinkedList(list, 450);
    addToEndLinkedList(list, 1000);
    printLinkedList(list);
    deleteNodeLinkedList(list, 125);
    printLinkedList(list);
}