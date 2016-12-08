#include <iostream>

using namespace std;

struct Node 
{
    int key;
    
    Node *pLeft;
    Node *pRight;
};

void NLR(Node *binaryTree)
{
    if (binaryTree == NULL)
        return;
        
    cout << binaryTree->key << " ";
    
    NLR(binaryTree->pLeft);
    NLR(binaryTree->pRight);
}

bool searchKey(Node *binaryTree, int key)
{
    if (binaryTree == NULL)
        return false;
    else if (binaryTree->key == key)
        return true;
    else if (binaryTree->key > key)
        return searchKey(binaryTree->pLeft, key);
    else if (binaryTree->key < key)
        return searchKey(binaryTree->pRight, key);
}

bool searchKey2(Node *binaryTree, int key)
{
    while(1)
    {
        if (binaryTree == NULL)
            return false;
        else if (binaryTree->key == key)
        return true;
        else if (binaryTree->key > key)
            binaryTree = binaryTree->pLeft;
        else if (binaryTree->key < key)
            binaryTree = binaryTree->pRight;
    }
}

void addToTree(Node *&binaryTree, int key)
{
    if (binaryTree == NULL)
    {
        Node *p = new Node;
        p->key = key;
        p->pLeft = p->pRight = NULL;
        
        binaryTree = p;
    } else if (key < binaryTree->key)
        addToTree(binaryTree->pLeft, key);
    else if (key > binaryTree->key)
        addToTree(binaryTree->pRight, key);
    else cout << "Conflict key!!!" << endl;
    
    //NLR(binaryTree);
}

int main()
{
    Node *binaryTree;
    addToTree(binaryTree, 50);
    addToTree(binaryTree, 14);
    addToTree(binaryTree, 120);
    addToTree(binaryTree, 25);
    addToTree(binaryTree, 45);
    addToTree(binaryTree, 69);
    addToTree(binaryTree, 96);
    
    NLR(binaryTree);
    
    cout << searchKey2(binaryTree, 99) << endl;
}