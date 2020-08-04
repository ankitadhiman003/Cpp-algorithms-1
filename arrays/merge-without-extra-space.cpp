#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

// takes |m-n| space
int main() {
    ll t;cin>>t;
    while(t--) {
        ll x,y;cin>>x>>y;
        vector<ll> arr1(x);
        vector<ll> arr2;
        ll xp=0;
        for(int i=0;i<x;i++) cin>>arr1[i];
        ll temp;
        for(int i=0;i<y;i++) {
            cin>>temp;
            while(xp<arr1.size() && arr1[xp] <= temp) {
                arr2.push_back(arr1[xp]);
                xp++;
            }
            arr2.push_back(temp);
        }
        for(int i = xp;i<x;i++) arr2.push_back(arr1[i]);
        for(auto h: arr2) cout<<h<<" ";cout<<endl;
    }
}

// Simplest Approach( O(1) extra space without using Insertion Sort)

// Time Complexity: O(nlogn) => As we sort both the arrays at the end.
// Space Complexity: O(1) => apart from I/O

// Procedure/Algo
// 1.
// Take two pointers , lets call them ptr1 and ptr2.
// ptr1 runs from end of array1 till the first element. ( endIndex -> 0 )
// ptr2 runs from first element of array2 till the last element. (0 -> endIndex )

// 2.
// Use a while loop which runs till ptr1 >=0 && ptr2< array2.length
// 2.1
// Now swap the elements of array1 and array2 IF (array1 [ptr1] > array2[ptr2] )
// (The reason we swap is because all the smaller elements should be in array1 and the larger elements should be in
// array2.In other words, the largest element of array1 should be lesser than the smallest element of array2)

// 3.
// Finally sort both array1 and array2

// 4. reverse array2 now pop from arr2 and push to arr1