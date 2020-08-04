#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

void DFSUtil(vector<string> subset,vector<string> &ans,bool &done,vector<string> &arr,vector<bool> vis) {
    if(done) return;
    // cout<<"subset top "<<subset.back()<<endl;
    if(subset.size() == arr.size()) {
        if((subset[0][0]==subset[subset.size()-1][subset[subset.size()-1].size()-1])) {
            ans = subset;
            done = true;
            return;
        }
    }
    for(int i=0;i<arr.size();i++) {
        // cout<<"checking "<<i<<endl;
        if(arr[i][0] == subset[subset.size()-1][subset[subset.size()-1].size()-1] && !vis[i] && !done) {
            subset.push_back(arr[i]);
            vis[i] = true;
            DFSUtil(subset,ans,done,arr,vis);
            subset.pop_back();
            vis[i] = false;
        }
    }
}

int main() {
    ll t;cin>>t;
    while(t--) {
        ll n;cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<bool> vis(n,false);
        if(n==1) {
            cout<<(arr[0][0]==arr[0][arr[0].size()-1])<<endl;
            continue;
        }
        vector<string> subset;
        vector<string> ans;
        bool done = false;
        subset.push_back(arr[0]);
        vis[0] = true;
        DFSUtil(subset,ans,done,arr,vis);
        cout<<done<<endl;
    }
}