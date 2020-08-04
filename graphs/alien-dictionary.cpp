#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

void DFSUtil(vector<int> adj[],int i,int K, vector<bool> &vis, vector<int> &ans) {
    vis[i] = true;
    for(auto h: adj[i]) {
        if(!vis[h]) {
            DFSUtil(adj,h,K,vis,ans);
        }
    }
    ans.push_back(i);
}

vector<int> topoSort(vector<int> adj[],int K) {
    vector<int> ans;
    vector<bool> vis(K,false);
    // Might be a disconnected graph
    for(int i=0;i<K;i++) {
        if(!vis[i]) {
            DFSUtil(adj,i,K,vis,ans);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int helper(char c) {
    return c - 'a';
}

char revHelper(int x) {
    return (char)('a' + x);
}

string findOrder(string dict[], int N, int K) {
    vector<int> adj[K];
    for(int i=0;i<N-1;i++) {
        int j=0,z=0;
        while(j<dict[i].size() && z<dict[i+1].size()) {
            if(dict[i][j] != dict[i+1][z]) {
                adj[helper(dict[i][j])].push_back(helper(dict[i+1][z]));
                break;
            }
            j++;z++;
        }
    }
    vector<int> ans = topoSort(adj,K);
    string str = "";
    for(auto h: ans) str.push_back(revHelper(h));
    return str;
}

int main() {
    string dict[5] = {"baa", "abcd", "abca", "cab", "cad"};
    cout<<findOrder(dict,5,4);
    return 0;
}