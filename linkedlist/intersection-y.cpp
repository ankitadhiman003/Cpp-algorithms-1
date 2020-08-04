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

int intersectPoint(Node* head1, Node* head2) {
    Node* h1 = head1,*h2=head2;
    int ans = -1;
    while(h1) {
        h1->data = -h1->data-1;
        h1 = h1->next;
    }
    while(h2) {
        if(ans == -1) {
            if(h2->data < 0) {
                ans = -h2->data-1;
                break;
            }
        }
        h2 = h2->next;
    }
    while(h1) {
        h1->data = -h1->data-1;
        h1 = h1->next;
    }
    return ans;
}