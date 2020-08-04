#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

int main() {
    ll t;cin>>t;
    while(t--) {
        string str;cin>>str;
        stack<char> stk;
        for(auto c: str) {
            switch (c)
            {
            case '(':
                stk.push('(');
                break;
            case '{':
                stk.push('{');
                break;
            case '[':
                stk.push('[');
                break;
            case ')':
                if(!stk.empty() && stk.top() == '(') {
                    stk.pop();
                } else {
                    stk.push(')');
                }
                break;
            case '}':
                if(!stk.empty() && stk.top() == '{') {
                    stk.pop();
                } else {
                    stk.push('}');
                }
                break;
            case ']':
                if(!stk.empty() && stk.top() == '[') {
                    stk.pop();
                } else {
                    stk.push('}');
                }
                break;
            default:
                break;
            }
        }
        if(stk.empty()) cout<<"balanced"<<endl;
        else cout<<"not balanced"<<endl;
    }
}