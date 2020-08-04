#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

bool isCyclic(vector<int> g[], int V) {
    queue<pair<int,int>> q;
    vector<bool> vis(V,false);
    int k=0;
    while(k<V) {
        if(!vis[k]) {
            q.push(make_pair(k,INT_MIN));
            vis[k] = true;
            while(!q.empty()) {
                int x = q.size();
                while(x--) {
                    pair<int,int> temp = q.front();
                    q.pop();
                    for(int i=0;i<g[temp.first].size();i++) {
                        if(g[temp.first][i] != temp.second) {
                            if(vis[g[temp.first][i]]) return true;
                            vis[g[temp.first][i]] = true;
                            q.push(make_pair(g[temp.first][i],temp.first));
                        }
                    }
                }
            }
        }
        k++;
    }       
    return false;
}