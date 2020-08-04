#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265


// Wrong answer. This is what was optimised by dikjashtra
int main() {
    ll t;cin>>t;
    while(t--) {
        ll n;cin>>n;
        vector<vector<int>> arr(n,vector<int>(n));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) cin>>arr[i][j];
        }
        queue<pair<int,int>> q;
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        dp[0][0] = arr[0][0];
        q.push(make_pair(0,0));
        while(!q.empty()) {
            int x = q.size();
            while(x--) {
                pair<int,int> temp = q.front();
                q.pop();
                int x,y;
                int mini = INT_MAX;
                // cout<<"on "<<temp.first<<" "<<temp.second<<endl;

                x = temp.first-1;y=temp.second;
                if(x>=0 && x<n && y>=0 && y<n) {
                    if(dp[x][y]!=INT_MAX) mini = min(mini,dp[x][y]);
                }

                x = temp.first;y=temp.second+1;
                if(x>=0 && x<n && y>=0 && y<n) {
                    if(dp[x][y]!=INT_MAX) mini = min(mini,dp[x][y]);
                }

                x=temp.first+1;y=temp.second;
                if(x>=0 && x<n && y>=0 && y<n) {
                    if(dp[x][y]!=INT_MAX) mini = min(mini,dp[x][y]);
                }

                x=temp.first;y=temp.second-1;
                if(x>=0 && x<n && y>=0 && y<n) {
                    if(dp[x][y]!=INT_MAX) mini = min(mini,dp[x][y]);
                }
                // cout<<"mini= "<<mini<<" dp= "<<dp[temp.first][temp.second]<<" before"<<endl;
                if(mini != INT_MAX) dp[temp.first][temp.second] = min(dp[temp.first][temp.second],mini+arr[temp.first][temp.second]);
                // cout<<"after "<<dp[temp.first][temp.second]<<endl;
                x = temp.first-1;y=temp.second;
                if(x>=0 && x<n && y>=0 && y<n) {
                    if(dp[x][y] > dp[temp.first][temp.second]+arr[x][y]) {
                        q.push(make_pair(x,y));
                    }
                }


                x = temp.first;y=temp.second+1;
                if(x>=0 && x<n && y>=0 && y<n) {
                    if(dp[x][y] > dp[temp.first][temp.second]+arr[x][y]) {
                        q.push(make_pair(x,y));
                    }
                }

                x=temp.first+1;y=temp.second;
                if(x>=0 && x<n && y>=0 && y<n) {
                    if(dp[x][y] > dp[temp.first][temp.second]+arr[x][y]) {
                        q.push(make_pair(x,y));
                    }
                }

                x=temp.first;y=temp.second-1;
                if(x>=0 && x<n && y>=0 && y<n) {
                    if(dp[x][y] > dp[temp.first][temp.second]+arr[x][y]) {
                        q.push(make_pair(x,y));
                    }
                }
            }
        }
        cout<<dp[n-1][n-1]<<endl;
    }
}
// V.I.P : Good Ques, using dikjastra(modified) for matrix graph
// Soln

int main() {
    ll t;cin>>t;
    while(t--) {
        ll n;cin>>n;
        vector<vector<int>> arr(n,vector<int>(n));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) cin>>arr[i][j];
        }
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        // weight helps to sort
        set<pair<int,pair<int,int>>> s;
        dp[0][0] = arr[0][0];
        s.insert(make_pair(arr[0][0],make_pair(0,0)));
        int count = 0;
        while(!s.empty()) {
            int minv = INT_MAX;
            //pair<int,int> temp;
            pair<int,pair<int,int>> temp2 = *(s.begin());
            s.erase(s.begin());
            pair<int,int> temp = temp2.second;

            // cout<<"visiting "<<temp.first<<" "<<temp.second<<endl;
            // cout<<dp[temp.first][temp.second]<<endl;
            count++;
            int x,y;
            // here the dikjashtra's gurantee of setting minimum fails since there are multiple nodes 
            // which might be ready to set the value of a node
            x = temp.first-1;y=temp.second;
            if(x>=0 && x<n && y>=0 && y<n) {
                if(dp[x][y] > dp[temp.first][temp.second]+arr[x][y]) {
                    if(dp[x][y] != INT_MAX) {
                        s.erase(s.find(make_pair(dp[x][y],make_pair(x,y))));
                    }
                    dp[x][y] = dp[temp.first][temp.second] + arr[x][y];
                    s.insert(make_pair(dp[x][y],make_pair(x,y)));
                }
            }
            x = temp.first;y=temp.second+1;
            if(x>=0 && x<n && y>=0 && y<n) {
                if(dp[x][y] > dp[temp.first][temp.second]+arr[x][y]) {
                    if(dp[x][y] != INT_MAX) {
                        s.erase(s.find(make_pair(dp[x][y],make_pair(x,y))));
                    }
                    dp[x][y] = dp[temp.first][temp.second] + arr[x][y];
                    s.insert(make_pair(dp[x][y],make_pair(x,y)));
                }
            }
            
            x=temp.first+1;y=temp.second;
            if(x>=0 && x<n && y>=0 && y<n) {
                if(dp[x][y] > dp[temp.first][temp.second]+arr[x][y]) {
                    if(dp[x][y] != INT_MAX) {
                        s.erase(s.find(make_pair(dp[x][y],make_pair(x,y))));
                    }
                    dp[x][y] = dp[temp.first][temp.second] + arr[x][y];
                    s.insert(make_pair(dp[x][y],make_pair(x,y)));
                }
            }
            
            x=temp.first;y=temp.second-1;
            if(x>=0 && x<n && y>=0 && y<n) {
                if(dp[x][y] > dp[temp.first][temp.second]+arr[x][y]) {
                    if(dp[x][y] != INT_MAX) {
                        s.erase(s.find(make_pair(dp[x][y],make_pair(x,y))));
                    }
                    dp[x][y] = dp[temp.first][temp.second] + arr[x][y];
                    s.insert(make_pair(dp[x][y],make_pair(x,y)));
                }
            }
            
        }
        cout<<dp[n-1][n-1]<<endl;
    }
}