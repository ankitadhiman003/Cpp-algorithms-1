#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

int main() {
    ll t;cin>>t;
    while(t--) {
        ll n;cin>>n;
        vector<pair<ll,ll>> arr(n);
        ll temp;
        for(int i=0;i<n;i++) {
            cin>>temp;
            arr[i] = make_pair(temp,0);
        }
        for(int i=0;i<n;i++) cin>>arr[i].second;
        sort(arr.begin(),arr.end());
        ll ans = 0;
        priority_queue<ll, vector<ll>, greater<ll>> q;
        for(int i=0;i<n;i++) {
            if(q.size() == 0) {
                q.push(arr[i].second);
            } else {
                temp = q.top();
                if(temp < arr[i].first) {
                    q.pop();
                    q.push(arr[i].second);
                } else {
                    q.push(arr[i].second);
                }
            }
            ans = max(ans, (ll)q.size());
        }
        cout<<ans<<endl;
    }
}