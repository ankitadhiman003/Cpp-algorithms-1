int Solution::maxSubArray(const vector<int> &A) {
    
    int sum=0, maxi=A[0];
    
    for(int i=0;i<A.size();i++)
    {
        sum=sum+A[i];
        
        maxi = max(sum,maxi);
        if(sum<0) sum=0;
    }
    return maxi;
}
