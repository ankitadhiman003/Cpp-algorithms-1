#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

int main() {
    ll t;cin>>t;
    while(t--) {
        ll n;cin>>n;
        vector<char> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        char ans;
        map<char,int> mp;
        queue<char> q;
        for(auto c: arr) {
            if(mp.find(c) == mp.end()) {
                mp[c] = 1;
                q.push(c);
            } else {
                mp[c] = 0;
            }
            while(q.size()>0 && mp[q.front()]==0) q.pop();
            if(q.size() == 0) cout<<-1<<" ";
            else cout<<q.front()<<" ";
        }
        cout<<endl;
    }
}