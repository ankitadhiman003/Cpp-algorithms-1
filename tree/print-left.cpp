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

void leftView(Node *root) {
    queue<Node*> q;
    if(!root) return;
    q.push(root);
    while(!q.empty()) {
        int x = q.size();
        bool flag = false;
        while(x--) {
            Node* temp = q.front();
            q.pop();
            if(!flag) {
                flag = true;
                cout<<temp->data<<" ";
            }
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}