#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

int main() {
    ll t;cin>>t;
    while(t--) {
        vector<int> arr(100,0);
        string str;cin>>str;
        for(auto h: str) {
            int x = h - 'a';
            arr[x]++;
        }
        int maxs = 0;
        for(auto h: arr) maxs = max(maxs, h);
        cout<<((2*maxs - 1)<=str.size())<<endl;
    }
}