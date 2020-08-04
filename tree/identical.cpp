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

void trav(Node* n1, Node* n2, bool &ans) {
    if(!ans) return;
    if(!n1 || !n2) {
        ans = !n1 && !n2;
        return;
    }
    if(n1->data != n2->data) {
        ans = false;
        return;
    }
    if(n1 && n2) {
        trav(n1->left,n2->left,ans);
        trav(n1->right,n2->right,ans);
    }
}


bool isIdentical(Node *r1, Node *r2) {
    if(!r1 || !r2) {
        return !r1 && !r2;
    }
    bool ans = true;
    trav(r1,r2,ans);
    return ans;

}