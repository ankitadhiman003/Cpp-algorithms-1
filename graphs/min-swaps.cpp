#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265

int univ = 0;
bool comparat(int first, int second) {
    if(first<=second) {
        univ++;
        return true;
    }
    return false;
}

int minSwaps(int arr[], int N){
    univ = 0;
    vector<int> arr2(N);
    for(int i=0;i<N;i++) arr2[i] = arr[i];
    sort(arr2.begin(),arr2.end(),comparat);
    return univ;
}