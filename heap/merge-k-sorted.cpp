#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

bool checking(Node *arr[], int N) {
    for(int i=0;i<N;i++) {
        if(arr[i]) return true;
    }
    return false;
}

Node * mergeKLists(Node *arr[], int N) {
    Node *prev=NULL,*root=NULL;
    int mini,minv;
    while(checking(arr,N)) {
        minv = INT_MAX;
        for(int i=0;i<N;i++) {
            if(arr[i]) {
                if(arr[i]->data <minv) {
                    minv = arr[i]->data;
                    mini = i;
                }
            }
        }
        Node *nd = new Node(minv);
        arr[mini] = arr[mini]->next;
        if(prev) prev->next = nd;
        else root = nd;
        prev = nd;
    }
    return root;
}