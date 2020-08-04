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
        sort(arr.begin(),arr.end());
        ll p2=2;
        ll count = 0;
        while(p2<n) {
            ll p1=0,p3 = p2 - 1;
            while(p3>p1) {
                if(arr[p1] == arr[p2] - arr[p3]) {
                    count++;
                    p1++;p3--;
                } else if(arr[p1] > arr[p2] - arr[p3]) p3--;
                else p1++;
            }
            p2++;
        }
        if(count == 0) cout<<-1<<endl;
        else cout<<count<<endl;
    }
}