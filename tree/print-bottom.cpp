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


vector <int> bottomView(Node *root)
{
    vector<int> ans;
    if(!root) return ans; 
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));
    // queue<Node*> q;
    // q.push(root);
    while(!q.empty()) {
        int x = q.size();
        while(x--) {
            // Node* temp = q.front();
            // q.pop();
            // cout<<temp->data<<" ";
            // if(temp->left) q.push(temp->left);
            // if(temp->right) q.push(temp->right);
            pair<Node*,int> temp = q.front();
            q.pop();
            mp[temp.second] = temp.first->data;
            if(temp.first->left) q.push(make_pair(temp.first->left,temp.second-1));
            if(temp.first->right) q.push(make_pair(temp.first->right,temp.second+1));
        }
    }
    for(auto h: mp) {
        ans.push_back(h.second);
    }
    return ans;
}