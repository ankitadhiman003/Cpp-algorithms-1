#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

int main() {
    ll t;cin>>t;
    while(t--) {
        vector<ll> arr(3,0);
        ll n;cin>>n;
        ll temp;
        for(int i=0;i<n;i++) {
            cin>>temp;
            arr[temp]++;
        }
        for(int i=0; i<arr[0]; i++) cout<<0<<" ";
        for(int i=0; i<arr[1]; i++) cout<<1<<" ";
        for(int i=0; i<arr[2]; i++) cout<<2<<" ";
        cout<<endl;
    }
}