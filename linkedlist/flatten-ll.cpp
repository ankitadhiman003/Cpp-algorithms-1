#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

// V.I.P: merging linked list
Node* merging(Node* a, Node* b) {
    if(!a) return b;
    if(!b) return a;
    if(a->data < b->data) {
        a->bottom = merging(a->bottom,b);
        return a;
    } else {
        b->bottom = merging(a,b->bottom);
        return b;
    }
}

Node *flatten(Node *root) {
    Node *a=root;
    Node *b=root->next;
    while(b) {
        Node *c = b->next;
        a = merging(a,b);
        b = c;
    }
    return a;
}