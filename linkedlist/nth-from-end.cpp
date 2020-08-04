#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

int getNthFromLast(Node *head, int n) {
    int x = n-1;
    Node* p=head,*q=head;
    while(x--) {
        if(q) q = q->next;
        else return -1;
    }
    while(q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    return p->data;
}