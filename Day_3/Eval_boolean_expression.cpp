#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
ll dp[205][205][2];
ll solve(int i,int j,bool isTrue,string &s){
    if(i>j) return 0;
    if(i==j){
        if(isTrue){
            return s[i]=='T';
        }
        else{
            return s[i]=='F';
        }
    }
    if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
        long long ways=0;
       for(int k=i+1;k<=j-1;k+=2){
           ll LT=solve(i,k-1,1,s);
           ll LF=solve(i,k-1,0,s);
           ll RT=solve(k+1,j,1,s);
           ll RF=solve(k+1,j,0,s);
           switch(s[k]){
               case '&':
                   if(isTrue){
                       ways=(ways+(LT*RT)%mod)%mod;
                   }
                   else{
                       ways=(ways+((LT*RF)%mod+(LF*RT)%mod+(LF*RF)%mod)%mod)%mod;
                   }
                   break;
               case '|':
                   if(isTrue){
                       ways=(ways+((LT*RT)%mod+(LF*RT)%mod+(LT*RF)%mod)%mod)%mod;
                   }
                   else{
                       ways=(ways+(LF*RF)%mod)%mod;
                   }
                   break;
               case '^':
                   if(isTrue){
                       ways=(ways+((RT*LF)%mod+(LT*RF)%mod)%mod)%mod;
                   }
                   else{
                       ways=(ways+((RT*LT)%mod +(RF*LF)%mod)%mod)%mod;
                   }
                   break;
           }
       }
    return dp[i][j][isTrue]=ways;
}
int evaluateExp(string & exp) {
    int n=exp.size();
    if(n==0) return 0;
    memset(dp,-1,sizeof dp);
//     vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(n,vector<int>(2,-1)));
    return solve(0,n-1,1,exp);
}
