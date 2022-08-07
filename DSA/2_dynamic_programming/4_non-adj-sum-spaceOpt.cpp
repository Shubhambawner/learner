// #include "../../DSA/util/recursion_utilities.cpp"
#include<bits/stdc++.h>
using namespace std;

/*
since we only require dp[i+1] and dp[i+2] in memoisation(dp) approach, 
we can space optimise it with 2 variables

change with transition i becoms i-1, values of them to be same if:

with old i:                dp[i]    dp[i+1]   dp[i+2]
                             |         |
                             V         V
with new i:        dp[i]  dp[i+1]   dp[i+2]

for this loop                 curr       prev      prev2
                               |         |
                               V         V
for next loop        curr    prev      prev2
*/


int maximumNonAdjacentSum(vector<int> &nums){
    
    int n=nums.size();
    vector<int> dp(n,0);

    int curr=0,prev=0,prev2=0;

    for(int i=n-1;i>=0;i--){
        int take = nums[i] ;
        if(i+2<n)take+=prev2;

        int notTake = 0;
        if(i+1<n)notTake+=prev;
        
        curr = max(take,notTake);

        prev2 = prev;
        prev = curr;

    }

    return curr;
}