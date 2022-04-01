
/*  //! avoid using iterators and pointers with recursion for vectors
 *  @because: 
        if datastructure changes while iteration, pointers in for loop will become useless, and it will give seg.err
        pointers/iterators cant be incremented freely, only ++ and -- are there

    //! Use integer indice values instead, for arrays vectors , 
    
    //! for lists maps sets are used, dont change elements, just change values inside them

    //! always pass the datastructure if we need recursive calls in looping, 
 *  @because: 
        as initial datastructure may need to be forwarded in loop, 
        instead of storing in temp and re asigning, pass it down ! 
 */
#include <bits/stdc++.h>
#include "./recursion_utilities.cpp"
using namespace std;

//! recursion approach: for looping and set, n! time complexicity
void Swap(int* a, int* b){
    cout<<padding<<*a<<" swap with "<<*b;
    int temp = *a;
    *a=*b;
    *b=temp;
}
vector<vector<int>> ans;
void rc(int starter,vector<int>nums){
    recurse();srint(nums);
    if(starter==nums.size()-1){
        ans.push_back(nums);returnRecurse();
        return;
    }
    for (int it = starter; it < nums.size(); it++)
    {
        Swap(&nums[it],&nums[starter]);
        rc(starter+1, nums);
        
    }
    returnRecurse('a');
}
vector<vector<int>> permute(vector<int>Nums){
    rc(0, Nums);
    return ans;
}

int main()
{
    vector<int> nums = {1,2,3};
    //permute(nums);
    do
    {
        ans.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    
    cout<<"end\n";
    print(ans);
}