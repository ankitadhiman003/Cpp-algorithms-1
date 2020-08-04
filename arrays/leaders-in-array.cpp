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
        for(int i=0;i<n;i++) cin>>arr[i];
        for(auto h: arr) cout<<h<<" ";cout<<endl;
        vector<pair<ll,int>> stk;
        stk.push_back(make_pair(arr[n-1],n-1));
        cout<<stk.size()<<endl;
        for(int i=n-2;i>=0;i--) {
            if(arr[i] >= stk.back().first) {
                stk.push_back(make_pair(arr[i],i));
            }
        }cout<<stk.size()<<endl;
        for(int i=stk.size()-1;i>=0;i--) cout<<stk[i].first<<" ";
        cout<<endl;
    }
}