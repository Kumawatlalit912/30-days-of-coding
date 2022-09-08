#include <bits/stdc++.h>
int dp[20][20];
int solve(int i,int j){
    if(i<0 || j<0) return 0;
    if(i==0 && j==0) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
//     as i am starting from last index
    int up=solve(i-1,j);
    int left=solve(i,j-1);
    return dp[i][j]=down+right;
    
}
int uniquePaths(int m, int n) {
	// Write your code here.
    memset(dp,-1,sizeof dp);
    return solve(m-1,n-1);
}
