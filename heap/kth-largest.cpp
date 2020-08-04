#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

int main() {
    ll t;cin>>t;
    while(t--) {
        ll k,n;cin>>k>>n;
        priority_queue<int,vector<int>,greater<int>> second;
        int temp;
        while(n--) {
            cin>>temp;
            second.push(temp);
            if(second.size()>k) {
                second.pop();
            }
            if(second.size() < k) cout<<-1<<" ";
            else cout<<second.top()<<" ";
        }
        cout<<endl;
    }
}