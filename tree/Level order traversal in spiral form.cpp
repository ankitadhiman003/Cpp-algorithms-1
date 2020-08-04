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


void printSpiral(Node *root) {
    if(!root) return;
    deque<Node*> q;
    q.push_back(root);
    int cnt = 0;
    while(!q.empty()) {
        int x = q.size();
        while(x--) {
            if(cnt%2==0) {
                Node* temp = q.back();
                q.pop_back();
                cout<<temp->data<<" ";
                if(temp->right) q.push_front(temp->right);
                if(temp->left) q.push_front(temp->left);

            } else {
                Node* temp = q.front();
                q.pop_front();
                cout<<temp->data<<" ";
                if(temp->left) q.push_back(temp->left);
                if(temp->right) q.push_back(temp->right);
            }
        }
        cnt++;
    }
}