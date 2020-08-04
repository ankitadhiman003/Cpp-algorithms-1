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

bool isPalindrome(Node *head) {
    string a="",b="";
    Node* h = head;
    while(h) {
        a += to_string(h->data);
        h = h->next;
    }
    Node* h2 = revRec(head);
    while(h2) {
        b += to_string(h2->data);
        h2 = h2->next;
    }
    return (a == b);
}