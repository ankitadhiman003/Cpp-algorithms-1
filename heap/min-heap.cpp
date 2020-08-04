#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

struct MinHeap
{
    int *harr;
    int capacity, heap_size;
    MinHeap(int cap) {heap_size = 0; capacity = cap; harr = new int[cap];}
    int extractMin();
    void deleteKey(int i);
    void MinHeapify(int i);
    void insertKey(int k);
    int parent(int i);
    void decreaseKey(int i, int new_val);
    int left(int i);
    int right(int i);
};

void MinHeap::decreaseKey(int i, int new_val) {
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i]) smallest = l;
    if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}

int MinHeap::extractMin() {
    if(heap_size==0) return -1;
    int root = harr[0];
    swap(harr[0],harr[heap_size-1]);
    heap_size--;
    MinHeapify(0);
}


