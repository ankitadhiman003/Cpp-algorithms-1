#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

// V.I.P: Sliding window and use of deque.

int main() {
    ll t;cin>>t;
    while(t--) {
        ll n,k;cin>>n>>k;
        vector<int> arr(n),ans;
        deque<int> stk;
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++) {
            
            while(!stk.empty() && stk.front()<i-k+1) stk.pop_front();
            while(!stk.empty() && arr[i]>=arr[stk.back()]) stk.pop_back();
            stk.push_back(i);
            ans.push_back(arr[stk.front()]);
        }
        for(int i=k-1;i<ans.size();i++) cout<<ans[i]<<" ";cout<<endl;
    }
}