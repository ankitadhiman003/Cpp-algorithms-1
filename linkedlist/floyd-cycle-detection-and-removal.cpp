#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

// V.I.P floyd cycle detect and break
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void removeDaLoop(Node* meet,Node* head) {
    Node* slow = meet,*fast = head;
    while(slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}

void detectAndRemoveLoop(Node* head) {
    if(!head || !head->next) return;
    Node *fast = head,*slow = head;
    while(fast && fast->next) {
        fast = fast->next;
        slow = slow->next;
        if(fast->next) {
            fast = fast->next;
            if(fast == slow) {
                //cout<<"yes";
                removeDaLoop(slow, head);
                return;
            }
        }
    }
}