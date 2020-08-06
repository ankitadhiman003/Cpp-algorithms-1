#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

int main() {
    ll t;cin>>t;
    while(t--) {
        ll n,s;cin>>n>>s;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++) {
            if(s>=9) {
                arr[i] = 9;
                s = s - 9;
            } else {
                if(i==0 && s==0) {
                    s = 1;break;
                }
                arr[i] = s;
                s = 0;
                break;
            }
        }
        if(s>0) cout<<-1<<endl;
        else {
            for(auto h: arr) cout<<h;cout<<endl;
        }
    }
}