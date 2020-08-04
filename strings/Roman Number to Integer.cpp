#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

int val(char c) {
    switch (c)
    {
    case 'I':
        return 1;
        break;
    case 'V':
        return 5;
        break;
    case 'X':
        return 10;
        break;
    case 'L':
        return 50;
        break;
    case 'C':
        return 100;
        break;
    case 'D':
        return 500;
        break;
    case 'M':
        return 1000;
        break;
    
    default:
        break;
    }return 0;
}

int main() {
    ll t;cin>>t;
    while(t--) {
        string str;
        cin>>str;
        int sum = val(str[0]);
        char prev = str[0];
        for(int i=1;i<str.size();i++) {
            sum = sum + val(str[i]);
            if(val(prev) < val(str[i])) sum -= 2*val(prev);
            prev = str[i];
        }
        cout<<sum<<endl;
    }
}