#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

// V.I.P: Manacher's algorithm
int main() {
    ll t;cin>>t;
    while(t--) {
        string str;cin>>str;
        int n = str.size();
        vector<int> d1(n),d2(n);

        for(int i=0,l=0,r=-1;i<n;i++) {
            int k = (i>r) ? 1 : min(d1[l + r - i], r - i + 1);
            while( i-k+1>0 && i+k-1<n-1 && str[i-k] == str[i+k] ) k++;
            d1[i] = k;
            if( i+k-1 > r) {
                r = i+k-1;
                l = i-k+1;
            }
        }
        for(int i=0,l=0,r=-1;i<n;i++) {
            // Note: here we consult d2's l + r - i + 1 (j + 1) because in d2's mirror is always placed to the 
            // left of current, but we want the length as per the mirror image of the current pal at i
            // so we want the mirror to be placed to the right of current j which is equivalent to the
            // d2 value of j+1 which has it's mirror placed to its left(as normal) so we consider j+1.
            int k = (i>r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while( i-k>0 && i+k-1<n-1 && str[i-k-1] == str[i+k] ) k++;
            d2[i] = k;
            if( i+k-1 > r) {
                r = i+k-1;
                l = i-k;
            }
        }
        int maxl = 0;
        string ans="";
        for(int i=0;i<n;i++) {
            if(2*d1[i]-1 > maxl) {
                maxl = 2*d1[i]-1;
                ans = str.substr(i-d1[i]+1,2*d1[i]-1);
            }
        }
        for(int i=0;i<n;i++) {
            if(2*d2[i] > maxl) {
                maxl = 2*d2[i];
                ans = str.substr(i-d2[i],2*d2[i]);
            }
        }
        cout<<ans<<endl;
    }
}