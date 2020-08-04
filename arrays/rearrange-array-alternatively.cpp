#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

int main() {
    ll t;cin>>t;
    while(t--) {
        ll n;cin>>n;
        vector<ll> arr,arr2,arr3;
        ll a = (n%2) ? (n/2)+1 : n/2;
        ll temp;
        for(int i=0;i<a;i++) {
            cin>>temp;
            arr.push_back(temp);
        }
        for(int i=0;i<n-a;i++) {
            cin>>temp;
            arr2.push_back(temp);
        }
        ll temp2;
        reverse(arr.begin(),arr.end());
        while(arr.size()>0 && arr2.size()>0) {
            temp = arr2.back();
            temp2 = arr.back();
            arr2.pop_back();
            arr.pop_back();
            arr3.push_back(temp);
            arr3.push_back(temp2);
        }
        if(arr.size() == 1) arr3.push_back(arr[0]);
        for(auto h: arr3) cout<<h<<" ";cout<<endl;
    }
}