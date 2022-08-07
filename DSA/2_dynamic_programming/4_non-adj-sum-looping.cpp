// #include "../../DSA/util/recursion_utilities.cpp"
#include<bits/stdc++.h>
using namespace std;

/*

we have to immagine bottom to top, from base case of dp to top, 
i.e. how we would relate o/p of case i with i-1, 
then bring it all the way up from n to 0 in same way, filling the dp array

in recursion/dp we went from top to bottom, then back to top
i.e. f(0) called f(1).. called f(n), 
then f(n) returned to f(n-1), f(n-1) returned to f(n-1)... to f(0) finaly
backtracking all the way up again to get the f(0), the answer

here we will start with the case of f(n), and loop up to f(0), 
avoiding recursion stack space and backtracking
*/

int maximumNonAdjacentSum(vector<int> &nums){
    
    int n=nums.size();
    vector<int> dp(n,0);

    for(int i=n-1;i>=0;i--){

        int take = nums[i] ;
        if(i+2<n)take+=dp[i+2];

        int notTake = 0;
        if(i+1<n)notTake+=dp[i+1];
        
        dp[i] = max(take,notTake);
    }

    return dp[0];
}