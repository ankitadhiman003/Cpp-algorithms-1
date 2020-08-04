#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

bool comp(int first,int second) {
    return first<second;
}

int main() {
    vector<int> arr = {1,5,4,3,7,8,9};
    sort(arr.begin(),arr.end(),comp);
    for(auto h: arr) cout<<h<<" ";cout<<endl;

}