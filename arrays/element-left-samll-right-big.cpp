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
        vector<bool> ans(n,false);
        ll temp = arr[0];
        for(int i=1;i<n;i++) {
            if(arr[i] >= temp) {
                ans[i] = true;
                temp = arr[i];
            }
        }
        temp = arr[n-1];
        ans[n-1] = false;
        for(int i=n-2;i>=0;i--) {
            if(arr[i] <= temp) {
                ans[i] = ans[i] && true;
                temp = arr[i];
            } else ans[i] = false;
        }
        bool flag = true;
        for(int i=0;i<n;i++) {
            if(ans[i]) {
                cout<<arr[i]<<endl;
                flag = false;
                break;
            }
        }
        if(flag) cout<<-1<<endl;
    }
}