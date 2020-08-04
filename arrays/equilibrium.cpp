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
        vector<ll> dp(n+1,0);
        for(int i=0;i<n;i++) {
            dp[i+1] = dp[i] + arr[i];
        }
        int ans = -2;
        for(int i=0;i<n;i++) {
            if(dp[i] == dp[n] - dp[i+1]) {
                ans = i;
                break;
            }
        }
        cout<<ans+1<<endl;
    }
}