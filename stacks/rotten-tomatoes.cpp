#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265


int main() {
    ll t;cin>>t;
    while(t--) {
        ll rows,col;cin>>rows>>col;
        vector<vector<int>> arr(rows,vector<int>(col));
        vector<vector<bool>> dp(rows,vector<bool>(col,false));
        queue<pair<int, int>> q;
        for(int i=0;i<rows;i++) {
            for(int j=0;j<col;j++) {
                cin>>arr[i][j];
                if(arr[i][j] == 2) q.push(make_pair(i,j));
            }
        }
        int cnt = 0;
        while(!q.empty()) {
            int x = q.size();
            while(x--) {
                pair<int,int> temp = q.front();
                q.pop();
                dp[temp.first][temp.second] = true;
                int x,y;
                x = temp.first - 1;y=temp.second;
                if(x>=0 && (!dp[x][y]) && (arr[x][y]==1)) {
                    arr[x][y] = 2;
                    q.push(make_pair(x,y));
                }
                x = temp.first;y=temp.second+1;
                if(y<col && (!dp[x][y]) && (arr[x][y]==1)) {
                    arr[x][y] = 2;
                    q.push(make_pair(x,y));
                }

                x = temp.first+1;y = temp.second;
                if(x<rows && (!dp[x][y]) && (arr[x][y]==1)) {
                    arr[x][y] = 2;
                    q.push(make_pair(x,y));
                }

                x = temp.first;y = temp.second - 1;
                if(y>=0 && (!dp[x][y]) && (arr[x][y]==1)) {
                    arr[x][y] = 2;
                    q.push(make_pair(x,y));
                }
            }
            cnt++;
        }
        bool flag = true;
        for(int i=0;i<rows;i++) {
            for(int j=0;j<col;j++) {
                if(!flag) break;
                if(arr[i][j] == 1) {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) cout<<cnt-1<<endl;
        else cout<<-1<<endl;
    }
}