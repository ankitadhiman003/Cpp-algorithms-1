#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

int main() {
    ll t;cin>>t;
    while(t--) {
        int n;cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<int> span(n);
        vector<int> stk;
        stk.push_back(arr[0]);
        span[0] = arr[0];
        for(int i=1;i<n;i++) {
            span[i] = max(stk.back(),arr[i]);
            if(arr[i] > stk.back()) stk.push_back(arr[i]);
        }
        stk.clear();
        span[n-1] = min(span[n-1],arr[n-1]);
        stk.push_back(arr[n-1]);
        for(int i=n-2;i>=0;i--) {
            span[i] = min(span[i],max(stk.back(),arr[i]));
            if(arr[i] > stk.back()) stk.push_back(arr[i]);
        }
        ll rain = 0;
        for(int i=0;i<n;i++) {
            rain += span[i] - arr[i];
        }
        cout<<rain<<endl;
    }
}