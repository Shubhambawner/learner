#include <bits/stdc++.h>
#include "./recursion_utilities.cpp"
using namespace std;

//! recursion approach: for looping and set, n! time complexicity
void Swap(vector<int>::iterator a, vector<int>::iterator b){
    cout<<padding<<*a<<" swap with "<<*b;
    int temp = *a;
    *a=*b;
    *b=temp;
}
vector<vector<int>> ans;
vector<int>nums;
void rc(vector<int>::iterator starter){
    recurse();srint(nums);
    if(starter==nums.end()){
        ans.push_back(nums);returnRecurse();
        return;
    }
    vector<int> temp = nums;
    for (vector<int>::iterator it = starter; it != nums.end(); )
    {
        Swap(it,starter);
        it++;
        rc(it);
    }
    returnRecurse('a');
}
vector<vector<int>> permute(vector<int>Nums){
    nums = Nums;
    rc(nums.begin());
    return ans;
}

int main()
{
    vector<int> nums = {1,2,3};
    permute(nums);
    cout<<"end\n";
    print(ans);
}