#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

struct Node{
	int data;
	struct Node * next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

Node* revRec(Node* first) {
    Node* prev = NULL;
    Node* curr = first;
    Node* q;
    while(curr) {
        q = curr->next;
        curr->next = prev;
        prev = curr;
        curr = q;
    }
    return prev;
}
// V.I.P beware of segmentation fault
Node* addTwoLists(Node* first, Node* second)
{
    int carry = 0;
    first = revRec(first);
    second = revRec(second);
    Node* prev;
    int ans;
    while(first!=NULL || second!=NULL) {
        ans = carry;
        if(first!=NULL && second!=NULL) {
            ans += first->data + second->data;
            first = first->next;
            second = second->next;
        } else if(first!=NULL) {
            ans += first->data;
            first = first->next;
        } else if(second!=NULL) {
            ans += second->data;
            second = second->next;
        }
        carry = ans/10;
        ans = ans%10;
        Node* a = new Node(ans);
        a->next = prev;
        prev = a;
    }
    if(carry>0) {
        Node* a = new Node(carry);
        a->next = prev;
        prev = a;
    }
    return prev;
    
}
