#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

void helper(unordered_set<string> &res, vector<pair<char,int>> lookup, string subset, int &x) {
    if(subset.size() == x) {
        res.insert(subset);
    } else {
        for(int i=0;i<lookup.size();i++) {
            if(lookup[i].second == 1) {
                subset.push_back(lookup[i].first);
                lookup[i].second = 0;
                helper(res,lookup,subset,x);
                subset.pop_back();
                lookup[i].second = 1;
            }
        }
    }

}

int main() {
    ll t;cin>>t;
    while(t--) {
        string str;cin>>str;
        unordered_set<string> res;
        int x = str.size();
        vector<pair<char,int>> lookup(x);
        for(auto h: str) {
            lookup.push_back(make_pair(h,1));
        }
        helper(res,lookup,"",x);
        vector<string> res2;
        for(auto y: res) {
            res2.push_back(y);
        }
        sort(res2.begin(),res2.end());
        for(auto h: res2) cout<<h<<" ";cout<<endl;

    }

}