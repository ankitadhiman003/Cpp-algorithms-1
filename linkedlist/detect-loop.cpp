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

bool detectLoop(Node* head)
{
    Node* h = head;
    while(h) {
        if(h->data < 0) return true;
        h->data = -h->data-1;
        h = h->next;
    }
    return false;
}