#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

// Its not that basic, at first it might give a feel of recursion but if we inpect properly we dont need that
int main() {
    ll t;cin>>t;
    while(t--) {
        ll n;cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        int casing = 0;
        for(int i=0;i<n-1;i++) {
            switch (casing%2)
            {
            case 0:
                if(arr[i] > arr[i+1]) {
                    swap(arr[i],arr[i+1]);
                }
                break;
            case 1:
                if(arr[i] < arr[i+1]) {
                    swap(arr[i],arr[i+1]);
                }
                break;
            default:
                break;
            }
            casing++;
        }
        for(auto h:arr) cout<<h<<" ";cout<<endl;
    }
}