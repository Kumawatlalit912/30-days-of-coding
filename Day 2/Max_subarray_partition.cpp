class Solution {
    
public:
    
    int solve(int index,vector<int>&arr,int k,int n,vector<int>&dp){
        if(index==n) return 0;
        if(dp[index]!=-1) return dp[index];
        int len=0,maxi=INT_MIN,max_sum=0;
        for(int j=index;j<min(n,index+k);j++){
            len++;
            maxi=max(maxi,arr[j]);
            int ans=(len*maxi)+solve(j+1,arr,k,n,dp);
            max_sum=max(max_sum,ans);
        }
        return dp[index]=max_sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,-1);
        return solve(0,arr,k,n,dp);
    }
};
