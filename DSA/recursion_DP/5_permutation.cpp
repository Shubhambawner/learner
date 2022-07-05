#include <bits/stdc++.h>
#include "./recursion_utilities.cpp"
using namespace std;

//! recursion approach: for looping and set, n! time complexicity
//* bruite force for permutations,  select one of the list elements, permute all others behind it recursively
vector<vector<int>> ans;
vector<int>temp;
void rc(unordered_set<int> permuter){
    recurse();
     srint(permuter);
    if(permuter.size()==0){
        ans.push_back(temp);
        srint(temp);
    }
    
    for(auto i:permuter){
        cout<<padding<<"-"<<i<<"-";
        temp.push_back(i);
        unordered_set<int> tpermuter = permuter;
        tpermuter.erase(i);;
        rc(tpermuter);
        //! datastructure cant be edited while iterating, so we have to create new one and pass inn.
        temp.pop_back();;
        
    }
       returnRecurse();
}
vector<vector<int>> permute(vector<int>nums){
    
    unordered_set<int>  permuter;
    for(auto i:nums){
        permuter.insert(i);
    }
    rc(permuter);
    return ans;
}

int main()
{
    vector<int> nums = {1,2,3};
    permute(nums);
    cout<<"end\n";
    print(ans);
}