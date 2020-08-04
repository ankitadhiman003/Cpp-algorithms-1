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

// V.I.P : Good Questions


// Soln for max sum b/w two leaf nodes

int trav(Node* nd,int &maxs) {
    if(!nd) return 0;
    int x = trav(nd->left,maxs);
    int y = trav(nd->right,maxs);
    if(nd->left && nd->right) {
        maxs = max(maxs,nd->data + x + y);
    }
    int rtr;
    if(nd->left && nd->right) {
        rtr = max(nd->data + x,nd->data + y);
    } else if (nd->left) {
        rtr = nd->data + x;
    } else {
        rtr = nd->data + y;
    }
    return rtr;
}

int maxPathSum(Node* root) {
    int ans = INT_MIN;
    if(!root) return INT_MIN;
    if(!root->left && !root->right) return root->data;
    trav(root,ans);
    return ans;
}


// Soln for max sum b/w any two nodes
int trav(Node* nd,int &maxs) {
    if(!nd) return INT_MIN;
    int x = trav(nd->left,maxs);
    int y = trav(nd->right,maxs);
    maxs = max(maxs,nd->data + (x>0)*x + (y>0)*y);
    return max(nd->data, max(nd->data + (x>0)*x,nd->data + (y>0)*y));
}

int maxPathSum(Node* root) {
    int ans = INT_MIN;
    if(!root) return INT_MIN;
    trav(root,ans);
    return ans;
}
