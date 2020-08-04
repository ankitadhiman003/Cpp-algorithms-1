#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265
int dijkshtra(vector<int> adj[],int V) {
    vector<int> ans(V,INT_MAX);
    set<pair<int,int>> s;
    s.insert(make_pair(0,0));
    ans[0] = 0;
    while(!s.empty()) {
        pair<int,int> temp = *(s.begin());
        s.erase(s.begin());
        int u = temp.second;
        for(int v=u+1;v<=u+6;v++) {
            if(v>=30) break;
            int x = v;
            if(adj[v].size()>0) {
                int y = adj[x][0];
                if(y > x) {
                    x = y;
                }
                else continue;
            }
            if(ans[x] > ans[u] + 1) {
                if(ans[x]!=INT_MAX) {
                    s.erase(s.find(make_pair(ans[x],x)));
                }
                ans[x] = ans[u] + 1;
                s.insert(make_pair(ans[x],x));
            }
        }
    }
    return ans[29];
}

int main() {
    ll t;cin>>t;
    while(t--) {
        ll n;cin>>n;
        vector<int> adj[30];
        int t1,t2;
        for(int i=0;i<n;i++) {
            cin>>t1>>t2;t1--;t2--;
            adj[t1].push_back(t2);
        }
        cout<<dijkshtra(adj,30)<<endl;
    }
}




