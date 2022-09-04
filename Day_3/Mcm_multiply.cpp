#include<bits/stdc++.h>
#define ll long long
//Tc----.O(N^2)*N-->O(N^3)
//Sc-----O(N^2)+recursion stack space 
int solve(int i,int j,vector<int>&arr,int N,vector<vector<int>>&dp){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mini=INT_MAX;
    for(int k=i;k<=j-1;k++){
        mini=min(mini,arr[i-1]*arr[k]*arr[j]+solve(i,k,arr,N,dp)+solve(k+1,j,arr,N,dp));
    }
    return dp[i][j]=mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>>dp(N,vector<int>(N,-1));
    return solve(1,N-1,arr,N,dp);
}
