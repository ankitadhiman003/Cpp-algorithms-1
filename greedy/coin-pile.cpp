#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

// The game of numbers
int main() {
    ll t;cin>>t;
    while(t--) {
        ll n,k;cin>>n>>k;
        vector<int> arr(n);
        int mini = INT_MAX;
        int t2=0,temp=0;
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++) {
            temp = t2;
            t2+=arr[i];
            for(int j=n-1;j>i;j--) {
                if(arr[j]-arr[i] > k) {
                    temp += arr[j]-arr[i]-k;
                }
            }
            mini = min(mini, temp);
        }
        cout<<mini<<endl;
    }
}