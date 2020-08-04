#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265


int findIslands(vector<int> A[], int N, int M) {
    vector<vector<bool>> vis(N,vector<bool>(M,false));
    queue<pair<int,int>> q;
    int islands=0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(A[i][j]==1 && !vis[i][j]) {
                islands++;  
                vis[i][j] = true;
                q.push(make_pair(i,j));
                while(!q.empty()) {
                    pair<int,int> temp = q.front();
                    q.pop();
                    int x,y;

                    x=temp.first-1;y=temp.second;
                    if(x>=0 && x<N && y>=0 && y<M) {
                        if(!vis[x][y] && A[x][y]==1) {
                            vis[x][y] = true;
                            q.push(make_pair(x,y));
                        }
                    }
                    x=temp.first-1;y=temp.second+1;
                    if(x>=0 && x<N && y>=0 && y<M) {
                        if(!vis[x][y] && A[x][y]==1) {
                            vis[x][y] = true;
                            q.push(make_pair(x,y));
                        }
                    }

                    x=temp.first;y=temp.second+1;
                    if(x>=0 && x<N && y>=0 && y<M) {
                        if(!vis[x][y] && A[x][y]==1) {
                            vis[x][y] = true;
                            q.push(make_pair(x,y));
                        }
                    }

                    x=temp.first+1;y=temp.second+1;
                    if(x>=0 && x<N && y>=0 && y<M) {
                        if(!vis[x][y] && A[x][y]==1) {
                            vis[x][y] = true;
                            q.push(make_pair(x,y));
                        }
                    }

                    x=temp.first+1;y=temp.second;
                    if(x>=0 && x<N && y>=0 && y<M) {
                        if(!vis[x][y] && A[x][y]==1) {
                            vis[x][y] = true;
                            q.push(make_pair(x,y));
                        }
                    }

                    x=temp.first+1;y=temp.second-1;
                    if(x>=0 && x<N && y>=0 && y<M) {
                        if(!vis[x][y] && A[x][y]==1) {
                            vis[x][y] = true;
                            q.push(make_pair(x,y));
                        }
                    }

                    x=temp.first;y=temp.second-1;
                    if(x>=0 && x<N && y>=0 && y<M) {
                        if(!vis[x][y] && A[x][y]==1) {
                            vis[x][y] = true;
                            q.push(make_pair(x,y));
                        }
                    }

                    x=temp.first-1;y=temp.second-1;
                    if(x>=0 && x<N && y>=0 && y<M) {
                        if(!vis[x][y] && A[x][y]==1) {
                            vis[x][y] = true;
                            q.push(make_pair(x,y));
                        }
                    }
                }
            }
        }
    }
}