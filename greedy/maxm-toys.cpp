#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

int main() {
    ll t;cin>>t;
    while(t--) {
        ll n,k;cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr.begin(),arr.end());
        int cnt=0,temp=0;
        for(int i=0;i<n;i++) {
            temp+=arr[i];
            if(temp<=k) cnt++;
            else break;
        }
        cout<<cnt<<endl;
    }
}