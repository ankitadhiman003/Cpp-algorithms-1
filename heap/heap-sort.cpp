#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

// V.I.P: Heap Sort

void heapify(vector<int> &arr, int n, int i) {
    int largest = i,l=2*i+1,r=2*i+2;
    if(l<n && arr[l] > arr[largest]) {
        largest = l;
    }
    if(r<n && arr[r] > arr[largest]) {
        largest = r;
    }
    if(largest != i) {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void heapSort(vector<int> &arr) {
    int n = arr.size();
    // from last parent
    for(int i=n/2-1;i>=0;i--) heapify(arr,n,i);
    for(int i=n-1;i>0;i--) {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

// Driver
int main() {
    ll t;cin>>t;
    while(t--) {
        ll n;cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        heapSort(arr);
        for(auto h: arr) cout<<h<<" ";cout<<endl;
    }
}