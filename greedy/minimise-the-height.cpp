#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

int main() {
    ll t;cin>>t;
    while(t--) {
        ll k,n;cin>>k>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            arr[i]+=k;
        }
        if(n==0) {
            cout<<0<<endl;
            continue;
        }
        sort(arr.begin(),arr.end());
        //for(auto h: arr) cout<<h<<" ";cout<<endl;
        int mini = arr[0],prev=0;
        for(int i=n-1;i>=1;i--) {
            if(arr[i] >= 2*k && arr[i]>prev) {
                if(arr[i] - mini > abs(arr[i] - mini - 2*k)) {
                    arr[i] = arr[i] - 2*k;
                    mini = min(mini, arr[i]);
                    prev = max(prev,arr[i]);
                }
            }
        }
        //for(auto h: arr) cout<<h<<" ";cout<<endl;
        int maxi = INT_MIN;
        for(auto h: arr) maxi = max(maxi, h);
        cout<<maxi-mini<<endl;
    }
}