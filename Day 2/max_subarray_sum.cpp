// this one is kadane's algo
//oook lets see we have similar king of problem but we have to find product in that case (so what we do in that problem nothing just first iterate from last and take sum ,and 
// iterate from start and take sum and store in different variable ( then take max from sum taken from last and starting of array ) this is in case of negative elements...

#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long maxi=0;
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        maxi=max(maxi,sum);
        if(sum<0){
            maxi=max(maxi,sum);
            sum=0;
        }
    }
    return maxi;
}
