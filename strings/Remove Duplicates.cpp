#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

int main() {
    ll t;cin>>t;
    char c;
    getchar();
    while(t--) {
        vector<int> freq(256,0);
        while(((c = getchar()) != '\n') && (c != EOF)) {
            if(freq[c]++ == 0) putc(c,stdout);
        }
        printf("\n");
    }
    return 0;
}