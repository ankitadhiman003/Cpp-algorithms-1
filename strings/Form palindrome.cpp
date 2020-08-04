#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

int main() {
    ll t;cin>>t;
    while(t--) {
        string str;cin>>str;
        int n = str.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int ext = 1; ext < n; ++ext) {
            for(int l=0,h=ext;h<n;l++,h++) {
                dp[l][h] = (str[l] == str[h]) ? dp[l+1][h-1] : min(dp[l+1][h],dp[l][h-1]) + 1;
            }
        }
        cout<<dp[0][n-1]<<endl;
    }
}