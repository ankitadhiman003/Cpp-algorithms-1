#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

int main() {
    ll t;cin>>t;
    while(t--) {
        ll n;cin>>n;
        vector<ll> arr(n);
        ll rst = INT_MAX;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            if(arr[i] < rst) rst = arr[i]; 
        }
        if(rst > 0) rst = 0;
        ll max_so_far = rst,max_ending_here = 0;
        for(int i=0;i<n;i++) {
            max_ending_here += arr[i];
            max_so_far = max(max_so_far,max_ending_here);
            if(max_ending_here < 0) max_ending_here = 0;
        }
        cout<<max_so_far<<endl;
    }
}