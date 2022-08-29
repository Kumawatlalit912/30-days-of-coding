//minimum cost of job assignment 
// Np hard problems

// time complexity-----> N*2^N;
// space complexity----->2^N;

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define nline "\n"
int cost[21][21];
int dp[21];
int solve(int index,int &n,int mask){
	if(index==n){
		return 0;
	}
	if(dp[mask]!=-1) return dp[mask];
	int res=INT_MAX;
	for(int i=0;i<n;i++){
	if(mask&(1<<i)){
		res=min(res,cost[i][index]+solve(index+1,n,(mask^(1<<i))));
	}
}
	return dp[mask]=res;
}
int main(){
	int n;
	cin>>n;
	memset(dp,-1,sizeof dp);
for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		cin>>cost[i][j];
	}
}
	cout<<solve(0,n,(1<<n)-1);
}

