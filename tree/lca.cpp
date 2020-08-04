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

pair<bool,bool> trav(Node* nd, int &n1, int &n2,Node* &ans,bool &done) {
    if(!nd) return make_pair(false,false);
    if(done) return make_pair(true,true);
    bool found1=false, found2=false;
    pair<bool,bool> p1 = trav(nd->left,n1,n2,ans,done);
    if(nd->data == n1) found1 = true;
    if(nd->data == n2) found2 = true;
    pair<bool,bool> p2 = trav(nd->right,n1,n2,ans,done);
    found1 = found1 || p1.first || p2.first;
    found2 = found2 || p1.second || p2.second;
    if(found1 && found2 && !done) {
        ans = nd;
        done = true;
    }
    return make_pair(found1,found2);
}

Node* LCA(Node *root, int n1, int n2) {
    Node* ans;
    if(!root) return ans;
    bool done = false;
    trav(root,n1,n2,ans,done);
    return ans;
}