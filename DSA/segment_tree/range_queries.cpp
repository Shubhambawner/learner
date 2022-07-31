//! we use segment tree when need to frequently find avrage/sum/... of sub-arrays 
//! where number of elements are fixed, but elements can change
/*
what is it?
The segment tree for array a[0 to n−1] is a binary tree 
in which each node contains aggregate information (min, max, sum, etc.) for a subrange [i to j] of the array, 
as its left and right child hold information for range [i to (i+j)/2] and [(i+j)/2 + 1 to j].

implementation: for seg. tree of n nodes:
Segment tree could be implemented using either an array or a tree. 
For an array implementation, 
if the element at index i is not a leaf, 
its left and right child are stored at index 2*i and 2*i + 1 respectively.
here, 2*i is left child, 2*i + 1 is right child, i.e. even inc=dexed is left, odd is ri8.

*/
// https://leetcode.com/problems/range-sum-query-mutable/solution/

#include <bits/stdc++.h>
#include "../util/recursion_utilities.cpp"
using namespace std;


/* 
*to create class that allows for 
    storing given array, 
    retriving sum of its sub-array, 
    updating it's elements 
    */

class NumArray{
    public:
    vector<int> ds;
    NumArray(vector<int>& nums){
        int n = nums.size();
        ds = vector<int>(2*n,0);
        for(int i=n;i<2*n;i++){
            ds[i]=nums[i-n];
        }
        for(int j=n-1;j>0;j--){
            ds[j]=ds[2*j]+ds[2*j+1];
        }
    }
    void update(int index,int val){
        int n = ds.size()/2;
        index+=n;
        ds[index]=val;
        while(index>0){
            if(index%2){
                ds[index/2]=ds[index-1]+ds[index];
            }else{
                ds[index/2]=ds[index+1]+ds[index];
            }
            index=index/2;
        }
    }
    int sumRange(int l,int r){
        int n = ds.size()/2;
        // get leaf with value 'l'
        l += n;
        // get leaf with value 'r'
        r += n;
        int sum = 0;
        while (l <= r) {
            if ((l % 2) == 1) {
               sum += ds[l];
               l++;
            }
            if ((r % 2) == 0) {
               sum += ds[r];
               r--;
            }
            l /= 2;
            r /= 2;
        }
        return sum;
    }
}
;


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

