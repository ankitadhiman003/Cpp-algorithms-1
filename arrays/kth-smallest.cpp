#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265


// V.I.P : Quicksort using binary search the solution
// additionally the pivot is randomised

// Written by: Kshitij Bhardwaj
void swaping(ll *a, ll *b) {
    ll temp = *a;
    *a = *b;
    *b = temp;
}

int partitioning(vector<ll> &arr, int l, int r) {
    int pvt = arr[r];int i = l;
    for(int j=l;j<r;j++) {
        if(arr[j] <= pvt) {
            swaping(&arr[i],&arr[j]);
            i++;
        }
    }
    swaping(&arr[i],&arr[r]);
    return i;
}

int randomisedParty(vector<ll> &arr, int l, int r) {
    int n = r-l+1;
    int pivot = rand()%n;
    swaping(&arr[l+pivot],&arr[r]);
    return partitioning(arr,l,r);
}

int kthsmallest(vector<ll> &arr, int l, int r, int k) {
    while(l<=r) {
        int pos = randomisedParty(arr,l,r);
        if(pos == k-1) {
            return arr[pos];
        } else if (pos > k-1) {
            r = pos-1;
        } else {
            l = pos + 1;
        }
    }
    return -1;
}

int main() {
    ll t;cin>>t;
    while(t--) {
        ll n,k;cin>>n;
        vector<ll> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        cin>>k;
        cout<<kthsmallest(arr,0,n-1,k)<<endl;
    }
}