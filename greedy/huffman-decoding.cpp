#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define PI 3.14159265


struct MinHeapNode 
{ 
    char data;             // One of the input characters 
    int freq;             // Frequency of the character 
    MinHeapNode *left, *right; // Left and right child 
  
    MinHeapNode(char data, int freq) 
    { 
        left = right = NULL; 
        this->data = data; 
        this->freq = freq; 
    } 
}; 

string decode_file(struct MinHeapNode* root, string s) {
    MinHeapNode* now = root;
    string ans = "";
    for(int i=0;i<s.size();i++) {
        if(s[i] == '0') now = now->left;
        else now = now->right;
        if(!now->left && !now->right) {
            ans.push_back(now->data);
            now = root;
        } 
    }
    return ans;
}