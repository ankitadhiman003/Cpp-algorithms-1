#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265


ll univ = 0;

// V.I.P: merge sort

void merger(int arr[], int l, int m, int r) {
    int i,j,k;
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];

    for(i=0; i<n1; i++) L[i] = arr[l+i];
    for(j=0; j<n2; j++) R[j] = arr[m-j+1];

    i=0;j=0;k=l;

    while(i<n1 && j<n2) {
        if(L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            univ+= m - (l + i) + 1;  // length of elements b/w L[i] and L[m] that will all form invs with R[j]
            arr[k++] = R[j++];
        }
    }

    while(i<n1) {
        arr[k++] = L[i++];
    }
    while(j<n2) {
        arr[k++] = R[j++];
    }

}

void mergeSort(int arr[],int l, int r) {
    if(l < r) {
        int m = l + (r - l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merger(arr,l,m,r);
    }
}

int main() {
    ll t;cin>>t;
    while(t--) {
        ll n;cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        univ=0;
        mergeSort(arr,0,n-1);
        cout<<univ<<endl;
    }
}