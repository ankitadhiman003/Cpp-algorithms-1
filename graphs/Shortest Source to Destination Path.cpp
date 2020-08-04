#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

int main() {
    ll t;cin>>t;
    while(t--) {
        int ans=-1;
        ll rows,col;cin>>rows>>col;
        vector<vector<int>> arr(rows,vector<int>(col));
        vector<vector<bool>> vis(rows,vector<bool>(col,false));
        for(int i=0;i<rows;i++) {
            for(int j=0;j<col;j++) {
                cin>>arr[i][j];
            }
        }
        ll a,b;cin>>a>>b;
        if(arr[0][0]==0 || arr[a][b]==0) {
            cout<<-1<<endl;
            continue;
        } // Couldve simply used a counter
        queue<pair<pair<int,int>,int>> q;
        vis[0][0] = true;
        q.push(make_pair(make_pair(0,0),0));
        while(!q.empty()) {
            int x = q.size();
            while(x--) {
                pair<pair<int,int>,int> temp = q.front();
                q.pop();
                if(temp.first.first == a && temp.first.second == b) ans = temp.second;
                int x,y;
                x=temp.first.first-1;y=temp.first.second;
                if(x>=0 && x<rows && y>=0 && y<col) {
                    if(!vis[x][y] && arr[x][y]==1) {
                        vis[x][y] = true;
                        q.push(make_pair(make_pair(x,y),temp.second+1));
                    }
                }

                x=temp.first.first;y=temp.first.second+1;
                if(x>=0 && x<rows && y>=0 && y<col) {
                    if(!vis[x][y] && arr[x][y]==1) {
                        vis[x][y] = true;
                        q.push(make_pair(make_pair(x,y),temp.second+1));
                    }
                }

                x=temp.first.first+1;y=temp.first.second;
                if(x>=0 && x<rows && y>=0 && y<col) {
                    if(!vis[x][y] && arr[x][y]==1) {
                        vis[x][y] = true;
                        q.push(make_pair(make_pair(x,y),temp.second+1));
                    }
                }

                x=temp.first.first;y=temp.first.second-1;
                if(x>=0 && x<rows && y>=0 && y<col) {
                    if(!vis[x][y] && arr[x][y]==1) {
                        vis[x][y] = true;
                        q.push(make_pair(make_pair(x,y),temp.second+1));
                    }
                }
                    
            }
        }
        cout<<ans<<endl;
    }
}