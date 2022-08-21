#include <bits/stdc++.h>
#include "../util/recursion_utilities.cpp"
using namespace std;

//! recursion approach: for looping and set, n! time complexicity
//* bruite force for permutations,  select one of the list elements, permute all others behind it recursively
vector<vector<int>> ans;
vector<int>temp;
void rc(unordered_set<int> permuter){
    _e(permuter);
    if(permuter.size()==0){
        ans.push_back(temp);
        _w(temp);
    }
    
    for(auto i:permuter){
        temp.push_back(i);
        _w("pushing ",i,", now temp: ",temp);
        //! unordered_set permuter cant be edited while iterating, so we have to create new one and pass inn.
        unordered_set<int> tpermuter = permuter;
        tpermuter.erase(i);;
        rc(tpermuter);
        temp.pop_back();;
        _w("popping back ",i,", now temp: ",temp);
        
    }
    _b();
}
//permute only array of unique elements, no duplicates 😢
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
    cout<<ans;
}