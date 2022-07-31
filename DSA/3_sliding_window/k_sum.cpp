#include <bits/stdc++.h>
#include "../util/recursion_utilities.cpp"
using namespace std;

//* variable size sliding window
/*
to find no. of sub-arrays summing to k, array given has POSITIVE integers 
*/

    int subarraySum(vector<int> &nums, int k)
{
    int ans = 0, n = nums.size();
    map<int, int> a;
    a[nums[0]]++;
    for (int i = 1; i < n; i++)
    {
        nums[i] += nums[i - 1];
        a[nums[i]]++;
    }
    cout<<nums<<endl;
    
    int i=0,m=a.size();
    ans += a[k];
    for (i; i<n; i++)
    {
    
        cout<<a<<" "<<nums[i]<<" "<<nums[i]+k<<" = "<<a[nums[i]] * a[nums[i] + k]<<endl;
        if (k)
        {
            ans += a[nums[i]] * a[nums[i] + k];
        }
        else
            ans += (a[nums[i]] * (a[nums[i]] - 1)) / 2;
        a[nums[i]]--;
    }
    return ans;
}

int main(){
    vector<int>nums={1,1,1};int k=2;
    cout<<subarraySum(nums,k);
}