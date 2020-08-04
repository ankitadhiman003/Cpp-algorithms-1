#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void trav(Node* nd, Node* &prev) {
    if(!nd) return;
    trav(nd->left,prev);
    if(prev) prev->right = nd;
    nd->left = prev;
    prev = nd;
    trav(nd->right,prev);
}


Node * bToDLL(Node *root) {
    Node* prev = NULL;
    if(!root) return prev;
    trav(root,prev);
    while(root->left) root = root->left;
    return root;
}