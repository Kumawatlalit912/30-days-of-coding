#include<bits/stdc++.h>
bool is_palin(string s){
    string cp=s;
    reverse(s.begin(),s.end());
    if(cp==s) return true;
    return false;
}
int solve(int index,string str,int n,vector<int>&dp){
    if(index==n) return 0;
    if(dp[index]!=-1) return dp[index];
    string op="";
    int mini=INT_MAX,ans=INT_MAX;
    for(int j=index;j<n;j++){
        op+=str[j];
        if(is_palin(op)){
            ans=1+solve(j+1,str,n,dp);
        }
        mini=min(mini,ans);
    }
    return dp[index]=mini;
}
int palindromePartitioning(string str) {
int n=str.size();
    vector<int>dp(n+1,-1);
    return solve(0,str,n,dp)-1;

}
