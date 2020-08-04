#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

// using dijkshtra(slight mod s.t those with int max aren't pushed, bcz of overflow values will start getting negative)
// Gives TLE
vector<int> dijkshtras(int src, vector<vector<int>> &arr) {
    int n = arr.size();
    vector<int> ans(n,INT_MAX);
    set<pair<int,int>> s;
    s.insert(make_pair(0,src));
    ans[src] = 0;
    while(!s.empty()) {
        pair<int,int> temp = *(s.begin());
        s.erase(s.begin());
        int u = temp.second;
        for(int i=0;i<n;i++) {
            if(arr[u][i]!=0 && arr[u][i]!=INT_MAX) {
                if(ans[i] > ans[u] + arr[u][i]) {
                    if(ans[i]!=INT_MAX) {
                        s.erase(s.find(make_pair(ans[i],i)));
                    }
                    ans[i] = ans[u] + arr[u][i];
                    s.insert(make_pair(ans[i],i));
                }
            }
        }
    }
    return ans;
}

void floydWarshall (vector<vector<int>> graph,int V)  
{  

    int dist[V][V], i, j, k;  
    for (i = 0; i < V; i++)  
        for (j = 0; j < V; j++)  
            dist[i][j] = graph[i][j];  
    for (k = 0; k < V; k++)  
    {  
        // Pick all vertices as source one by one  
        for (i = 0; i < V; i++)  
        {  
            for (j = 0; j < V; j++)  
            {  
                // If vertex k is on the shortest path from  
                // i to j, then update the value of dist[i][j]  
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }  
  
    // Print the shortest distance matrix  
    for (int i = 0; i < V; i++)  
    {  
        for (int j = 0; j < V; j++)  
        {  
            if (dist[i][j] == 10000000)  
                cout<<"INF"<<" ";  
            else
                cout<<dist[i][j]<<" ";  
        }  
        cout<<endl;  
    }   
}  
  
/* A utility function to print solution */


int main() {
    ll t;cin>>t;
    while(t--) {
        ll v;cin>>v;
        vector<vector<int>> graph(v,vector<int>(v));
        for(int i=0;i<v;i++) {
            for(int j=0;j<v;j++) {
                cin>>graph[i][j];
            }
        }
        floydWarshall(graph,v);
    }
}

