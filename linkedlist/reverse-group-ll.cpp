#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

struct node
{
    int data;
    struct node *next;
};

node* revRec(node* head, node* prev) {
    if(!head) return prev;
    node* actHead = revRec(head->next, head);
    head->next = prev;
    return actHead;
}

// V.I.P loop approach to reversal

struct node *reverse (struct node *head, int k)
{ 
    node* prev = NULL;
    node* curr = head;
    node* q;
    int counter = k;
    while(counter-- && curr) {
        q = curr->next;
        curr->next = prev;
        prev = curr;
        curr = q;
    }
    if(head) head->next = reverse(curr,k);
    return prev;
}

