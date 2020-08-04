#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

void DFSUtil(vector<int> adj[], vector<bool> &vis, vector<int> &ans,int i) {
    vis[i] = true;
    for(auto h: adj[i]) {
        if(!vis[h]) {
            DFSUtil(adj,vis,ans,h);
        }
    }
    ans.push_back(i);
}

// Multiple possibilities, for ex reverse the traversal order for any vertex during DFS
vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<bool> vis(V,false);
    for(int i=0;i<V;i++) {
        if(!vis[i]) DFSUtil(adj,vis,ans,i);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


// Driver
int main() {
    vector<int> adj[5];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[4].push_back(3);
    vector<int> ans = topoSort(5,adj);
    for(auto h: ans) cout<<h<<" ";
}