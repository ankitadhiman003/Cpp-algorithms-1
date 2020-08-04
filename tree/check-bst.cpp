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

void trav(Node* n,deque<int> &q,bool &ans) {
    if(!n || !ans) return;
    trav(n->left,q,ans);
    if(q.size()==0) {
        q.push_back(n->data);
    } else if(q.size()==1) {
        int temp = q.front();
        q.pop_front();
        if(temp >= n->data) {
            ans = false;
            return;
        }
        q.push_back(n->data);
    }
    trav(n->right,q,ans);
}

void isBST(Node* root) {
    bool ans = true;
    deque<int> q;
    trav(root,q,ans);
    if(ans) cout<<"yes";
    else cout<<"no";
}