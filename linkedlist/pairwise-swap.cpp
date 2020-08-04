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

Node* pairWiseSwap(struct Node* head) {
    Node *a = head;
    int counter = 0;
    while(a && a->next) {
        if(counter%2==0) {
            int temp = a->data;
            a->data = a->next->data;
            a->next->data = temp;
        }
        counter++;
        a = a->next;
    }
    return head;
}