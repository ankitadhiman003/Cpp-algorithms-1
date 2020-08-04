#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

int main() {
    ll t;cin>>t;
    while(t--) {
        ll n,s;cin>>n>>s;
        vector<ll> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        ll sum = arr[0];
        ll p1=0,p2=0;
        while(p2<n && p1<n) {
            if(sum == s) break;
            p2++;
            sum += arr[p2];
            if(sum > s) {
                while(sum > s && p1<=p2) {
                    sum -= arr[p1];
                    p1++;
                }
            }
        }
        if(sum == s) cout<<p1+1<<" "<<p2+1<<endl;
        else cout<<-1<<endl;
    }
}