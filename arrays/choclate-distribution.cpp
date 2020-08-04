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
        ll m;cin>>m;
        sort(arr.begin(),arr.end());
        ll ans = INT_MAX;
        for(int i=0;i<=n-m;i++) {
            ans = min(ans,arr[i+m-1] - arr[i]);
        }
        cout<<ans<<endl;
    }
}