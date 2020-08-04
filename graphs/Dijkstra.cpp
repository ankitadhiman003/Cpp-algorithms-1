#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

vector <int> dijkstra(vector<vector<int>> g, int src, int V) {
    vector<int> ans(V,INT_MAX);
    vector<bool> vis(V,false);
    int cnt = 0;
    ans[src] = 0;
    while(cnt < V) {
        int minv=INT_MAX,mini;
        for(int i=0;i<V;i++) {
            if(ans[i] < minv && !vis[i]) {
                minv = ans[i];
                mini = i;
            }
        }
        vis[mini] = true;
        cnt++;
        for(int i=0;i<V;i++) {
            if(g[mini][i]>0) {
                ans[i] = min(ans[i],ans[mini]+g[mini][i]);
            }
        }
    }
    return ans;
}

// int main() {
//     int x,y;
//     cin>>x>>y;
//     vector<vector<int>> arr(x,vector<int>(y,0));
//     for(int i=0;i<x;i++) {
//         for(int j=0;j<y;j++) cin>>arr[i][j];
//     }
//     vector<int> ans = dijkstra(arr,0,5);
//     for(auto h: ans) cout<<h<<" ";cout<<endl;
//     return 0;
// }