#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

int main() {
    ll t;cin>>t;
    while(t--) {
        string a,b;cin>>a>>b;
        if(a.size()!=b.size()) {
            cout<<0<<endl;continue;
        }
        bool flag = false;
        string p1 = a.substr(0,2);
        string p2 = a.substr(2,a.size()-2);
        string x = p2+p1;
        if(x == b) flag = true;
        if(!flag) {
            p1 = a.substr(0,a.size()-2);
            p2 = a.substr(a.size()-2,2);
            x = p2+p1;
            if(x == b) flag = true;
        }
        cout<<flag<<endl;
    }
}