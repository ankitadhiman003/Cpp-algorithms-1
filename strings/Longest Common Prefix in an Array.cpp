#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

int main() {
    ll t;cin>>t;
    while(t--) {
        ll n;cin>>n;
        vector<string> arr(n);
        int minsz = INT_MAX;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            minsz = min(minsz,(int)arr[i].size());
        }
        char holder;
        string lcs = "";
        bool flag = false;
        for(int i=0;i<minsz;i++) {
            if(flag) break;
            holder = arr[0][i];
            for(int j=1;j<n;j++) {
                if(holder != arr[j][i]) {
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                lcs += holder;
            }
        }
        if(lcs == "") cout<<-1<<endl;
        else cout<<lcs<<endl;
    }
}