
/*  //! avoid using iterators and pointers with recursion for vectors
 *  @because: 
        if datastructure changes while iteration, pointers in for loop will become useless, and it will give seg.err
        pointers/iterators cant be incremented freely, only ++ and -- are there

    //* Use integer indice values instead, for arrays vectors , 
    
    //* for lists maps sets are used, dont change elements, just change values inside them

    //* always pass the datastructure if we need recursive calls in looping, 
 *  @because: 
        as initial datastructure may need to be forwarded in loop, 
        instead of storing in temp and re asigning, pass it down ! 
 */
#include <bits/stdc++.h>
#include "./recursion_utilities.cpp"
using namespace std;

//! recursion approach: for looping and set, n! time complexicity
void Swap(char* a, char* b, string g=" "){
    cout<<spacing<<*a<<" swap with "<<*b<<g;
    int temp = *a;
    *a=*b;
    *b=temp;
}
vector<string> ans;
//* swaping based logic: 
//* select first element from n available, swap now-first element with the selected one,
//* repeat process for remaning n-1 elements array.
//* when array size is 0, the permutation is made, return.
void rc(int starter,string nums){
    recurse();srint(nums);
    cout<<spacing<<starter;
    if(starter==nums.size()-1){
        ans.push_back(nums);returnRecurse();
        return;
    }
    for (int it = starter; it < nums.size(); it++)
    {
        if(it==starter || nums[it]!=nums[starter]){
            Swap(&nums[it],&nums[starter]);
            rc(starter+1, nums);
            // Swap(&nums[it],&nums[starter], " back");
        }
        while(it+1<nums.size() && nums[it]==nums[it+1])it++;
    }
    returnRecurse('a');
}
vector<string> permute(string Nums){
    rc(0, Nums);
    return ans;
}

int main()
{
    // vector<int> nums = {2,2,2};
    string nums = "abc";
    permute(nums);
    // do
    // {
    //     ans.push_back(nums);
    // } while (next_permutation(nums.begin(), nums.end()));
    
    cout<<"end\n";
    cout<<(ans);
}

/*

for loop inside the recursive function:
-> it is used for problems that have selection of one way among many possible ways (valid)

*/