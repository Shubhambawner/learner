// #include "../../DSA/util/recursion_utilities.cpp"
#include<bits/stdc++.h>
using namespace std;

//return max. possible non adj. sum for range i to n
int f(int i,vector<int> &nums,vector<int> &dp){
    if(dp[i]!=0)return dp[i];
    if(i>=nums.size())return 0;
    
    int take = nums[i] + f(i+2,nums,dp);
    int notTake = f(i+1,nums,dp);
    
    return dp[i] = max(take,notTake);
}

/*
*/

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int> dp(n,0);

    return f(0,nums,dp);
}