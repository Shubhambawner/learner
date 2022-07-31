#include <bits/stdc++.h>
#include "../util/recursion_utilities.cpp"
using namespace std;

//! we use 2 heaps, min heap and max-heap, when need to find median of group of numbers, 
//! when numbers are added/removed from the group frequently.

//* to find median of each k sized sub array

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double>ans;
        multiset<int>s;
        int i=0,j=0,n=nums.size();
        while(j<=n){
            while(j<k){
                s.insert(nums[j]);
                j++;
            }
            double f=0;
            auto med=s.begin();
            for(int i=0;i<k/2;i++){
                med++;
            }
            f=*med;
            if(k%2==0){
                med--;
                f=(f+*med)/2;
            }ans.push_back(f);
            
            s.erase(s.find(nums[i]));
            i++;
            if(j==n)break;
            s.insert(nums[j]);
            j++;
        }
        return ans;
    }