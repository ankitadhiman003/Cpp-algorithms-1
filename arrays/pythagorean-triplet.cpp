#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

int main() {
    ll t;cin>>t;
    while(t--) {
        ll n;cin>>n;
        vector<bool> mp(1002);
        unordered_set<int> ust;
        int temp;
        for(int i=0;i<n;i++) {
            cin>>temp;
            ust.insert(temp);
            mp[temp] = 1;
        }
        bool flag = true;
        for(auto a: ust) {
            if(!flag) break;
            for(auto b: ust) {
                if(a != b) {
                    int x = a;
                    int y = b;
                    int z = sqrt(x*x + y*y);
                    int w = sqrt(abs(x*x - y*y));
                    if(z<1001) {
                        if(mp[z]) {
                            if(z*z == x*x + y*y) {
                                flag = false;
                                break;
                            }
                        }
                    }
                    if(w<1001) {
                        if(mp[w]) {
                            if(w*w == abs(x*x - y*y)) {
                                flag = false;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if(!flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}