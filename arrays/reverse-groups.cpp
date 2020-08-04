#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

int main() {
    ll t;cin>>t;
    while(t--) {
        ll n,k;cin>>n>>k;
        vector<ll> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<ll> stk;
        for(int i=0;i<n;i++) {
            if(stk.size()<k) {
                stk.push_back(arr[i]);
            } else {
                while(!stk.empty()) {
                    cout<<stk.back()<<" ";
                    stk.pop_back();
                }
                stk.push_back(arr[i]);
            }
        }
        while(!stk.empty()) {
            cout<<stk.back()<<" ";
            stk.pop_back();
        }
        cout<<endl;
    }
}