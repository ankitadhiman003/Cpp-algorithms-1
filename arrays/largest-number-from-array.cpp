#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

// V.I.P -
bool comp(int f, int s) {
    string first = to_string(f) + to_string(s);
    string second = to_string(s) + to_string(f);
    return second>first;
}

int main() {
    ll t;cin>>t;
    while(t--) {
        ll n;cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr.begin(),arr.end(),comp);
        string str="";
        while(!arr.empty()) {
            str+=to_string(arr.back());
            arr.pop_back();
        }
        cout<<str<<endl;

    }

}
