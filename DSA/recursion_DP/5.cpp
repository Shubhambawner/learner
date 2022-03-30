#include <bits/stdc++.h>
using namespace std;

string padding = "\n";
void recurse(){
    padding+="|";
    cout<<padding<<"recurse enter";
}
void returnRecurse(){
    string temp = "\n";
    for (int i = 0; i < padding.size()-2; i++)
    {
        temp+="|";
    }
    cout<<padding<<"recurse exit ";
    padding = temp;
}

// utility funnction to print a 2d iterative container vector<vector<int>> list<vector<int>> ...
template <class T>
void print(T arr,  int i = 0)
{

    for (auto g = arr.begin(); g != arr.end(); ++g)
    {
        cout<<padding;
        cout << i++ << "---- ";
        for (auto it = (*g).begin(); it != (*g).end(); ++it)
        {
            cout << *it << " ";
        }
        cout << '|';
    }
}
template <class T>
void srint(T arr,  int i = 0)
{
    cout<<padding;
    for (auto g = arr.begin(); g != arr.end(); ++g)
    {

        
            cout << *g << " ";
        
    }
        cout << "   ";
}

;
vector<vector<int>> ans;
vector<int>temp;
void rc(set<int> permuter){
    recurse();
     srint(permuter);
    if(permuter.size()==0){
        ans.push_back(temp);
        srint(temp);
    }
    
    for(auto i:permuter){
        cout<<padding<<"-"<<i<<"-";
        temp.push_back(i);//cout<<"q1";
        set<int> tpermuter = permuter;
        tpermuter.erase(i);//cout<<"q2 ";
        rc(tpermuter);//cout<<"q*";
        temp.pop_back();//cout<<"q4 ";
        
    }
       returnRecurse();
}
vector<vector<int>> permute(vector<int>nums){
    
    set<int>  permuter;
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