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

// V.I.P : Serialisation and Deserialisation of Trees

void serialize(Node *root,vector<int> &A) {
    if(!root) {
        A.push_back(-1);
        return;
    }
    A.push_back(root->data);
    serialize(root->left,A);
    serialize(root->right,A);
}

int prev_index = 0;
Node * deSerialize(vector<int> &A) {
    if(A[prev_index] == -1 || prev_index == A.size()) {
        prev_index++;
        prev_index = prev_index%A.size();
        return NULL;
    }
    Node* nd = new Node(A[prev_index]);
    prev_index++;
    prev_index = prev_index%A.size();
    nd->left = deSerialize(A);
    nd->right = deSerialize(A);
}