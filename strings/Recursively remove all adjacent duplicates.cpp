#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

bool check(string str) {
    int n = str.size();
    for(int i=0;i<n-1;i++) {
        if(str[i] == str[i+1]) return true;
    }
    return false;
}

string helper(string str) {
    string stk;
    char destro;
    int n = str.size();
    stk.push_back(str[0]);
    int i=1;
    while(i<n) {
        if(stk.back() == str[i]) {
            destro = stk.back();
            stk.pop_back();
            while(i<n && destro == str[i]) i++;
        }
        stk.push_back(str[i++]);
    }
    if(check(stk)) {
        return helper(stk);
    }
    return stk;
}

int main() {
    ll t;cin>>t;
    while(t--) {
        string str;cin>>str;
        cout<<helper(str)<<endl;
    }
}