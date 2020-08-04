#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

int main() {
    ll n;cin>>n;
    priority_queue<int> lesser;
    priority_queue<int, vector<int>, greater<int>> bigger;
    while(n--) {
        int temp;cin>>temp;
        //Insertion can be optimised
        lesser.push(temp);
        int a = 0,b=0;
        if(lesser.size() - bigger.size() == 2) {
            bigger.push(lesser.top());
            lesser.pop();
            a = lesser.top();
            b = bigger.top();
            cout<<(a+b)/2<<endl;
        } else {
            bigger.push(lesser.top());
            lesser.pop();
            a = bigger.top();
            bigger.pop();
            cout<<a<<endl;
            lesser.push(a);
        }
        
    }
}