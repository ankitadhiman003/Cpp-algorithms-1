void Solution::rotate(vector<vector<int> > &arr) {
    // Do not write main() function.
    for(int i=0;i<arr.size();i++){
int start=0;
int end=arr.size()-1;
while(start<end){
swap(arr[start][i],arr[end][i]);
start++;
end--;
}
}
for(int i=0;i<arr.size();i++){
for(int j=0;j<arr.size();j++){
if(i<j){
swap(arr[i][j],arr[j][i]);
}
}
}
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}