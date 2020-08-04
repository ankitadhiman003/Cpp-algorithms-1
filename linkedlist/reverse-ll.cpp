#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

struct Node
{
    int data;
    struct Node *next;
};


Node* revRec(struct Node *head, struct Node *prev) {
    if(!head) return prev;
    Node* h = revRec(head->next,head);
    head->next = prev;
    return h;
}

// Should reverse list and return new head.
Node* reverseList(struct Node *head)
{
    return revRec(head,NULL);
}