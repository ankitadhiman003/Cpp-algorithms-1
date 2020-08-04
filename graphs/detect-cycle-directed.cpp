#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

void DFSUtil(vector<int> g[], vector<bool> &vis, vector<bool> &vis2, int i, bool &ans) {
    if(ans) return;
    for(int j=0;j<g[i].size();j++) {
        if(vis2[g[i][j]]) {
            ans = true;
            return;
        }
        vis2[g[i][j]] = true;
        vis[g[i][j]] = true;
        DFSUtil(g,vis,vis2,g[i][j],ans);
    }
}

bool isCyclic(vector<int> g[], int V) {
    vector<bool> vis(V,false);
    bool ans = false;
    int k = 0;
    while(k<V) {
        if(!vis[k]) {
            vis[k] = true;
            vector<bool> vis2(V,false);
            vis2[k] = true;
            DFSUtil(g,vis,vis2,k,ans);
        }
        k++;
    }
    return ans;
}