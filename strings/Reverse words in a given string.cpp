#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

int main() {
    ll t;cin>>t;
    while(t--) {
        string str;
        cin>>str;
        vector<string> ans;
        string holder = "";
        for(auto x: str) {
            if(x == '.') {
                ans.push_back(holder);
                holder = "";
            } else holder += x;
        }
        ans.push_back(holder);
        while(!ans.empty()) {
            cout<<ans.back();
            ans.pop_back();
            if(!ans.empty()) cout<<'.';
        }
        cout<<endl;
    }
}