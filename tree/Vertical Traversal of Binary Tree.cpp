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

// V.I.P: The power of DEQUE :(
// Might be useful somewhere but not here, since this ques is related to the horizontal distance

vector<int> verticalOrder(Node *root) {
    vector<int> ans;
    if(!root) return ans;
    deque<pair<Node*,int>> q;
    q.push_back(make_pair(root,2));
    while(!q.empty()) {
        pair<Node*, int> temp = q.back();
        q.pop_back();
        if(temp.second==2) {
            q.push_back(make_pair(temp.first,1));
            if(temp.first->left) q.push_back(make_pair(temp.first->left,2));
        } else if(temp.second==1) {
            ans.push_back(temp.first->data);
            if(temp.first->right) q.push_front(make_pair(temp.first->right,2));
        }
    }
    return ans;
}

// ANS
vector<int> verticalOrder(Node *root) {
    vector<int> ans;
    if(!root) return ans;
    map<int,vector<int>> mp;
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));
    while(!q.empty()) {
        int x = q.size();
        while(x--) {
            pair<Node*,int> temp = q.front();
            q.pop();
            // mp[temp.second] = temp.first->data;
            mp[temp.second].push_back(temp.first->data);
            if(temp.first->left) q.push(make_pair(temp.first->left,temp.second-1));
            if(temp.first->right) q.push(make_pair(temp.first->right,temp.second+1));
        }
    }
    for(auto h: mp) {
        for(auto x: h.second) {
            ans.push_back(x);
        }
    }
    return ans;
    
}

