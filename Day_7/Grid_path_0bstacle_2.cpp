#include<bits/stdc++.h>
int mod=1e9+7;
int dp[205][205];
int solve(int i,int j,vector<vector<int>>&mat){
    if(i<0 || j<0 || mat[i][j]==-1) return 0;
    if(i==0 && j==0) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=solve(i-1,j,mat);
    int left=solve(i,j-1,mat);
    return dp[i][j]=(up+left)%mod;
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    memset(dp,-1,sizeof dp);
    return solve(n-1,m-1,mat);
}
