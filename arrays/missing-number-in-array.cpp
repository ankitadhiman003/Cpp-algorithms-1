#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

int main() {
    ll t;cin>>t;
    while(t--) {
        ll n;cin>>n;
        vector<bool> arr(n+1,false);
        ll temp;
        for(int i=0;i<n-1;i++) {
            cin>>temp;
            arr[temp] = true;
        }
        for(int i=1;i<=n;i++) {
            if(!arr[i]) {
                cout<<i<<endl;
                break;
            }
        }
    }
}