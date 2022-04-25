//! bruteforce TLE for n > 8

#include <iostream>
#include <bits/stdc++.h>
#include "../../DSA/recursion_DP/recursion_utilities.cpp"
using namespace std;

int n = 0;
int minXor = 1000;
vector<int> t;
vector<vector<int>> ans;
vector<vector<int>> ans2;

int Xor(vector<int> t){
    // srint(t);
    if(t.size()==1) return t[0];
    int ans = t[0]^t[1];
    for(int i = 1; i<t.size()-1; i++){
        ans = max(ans, t[i]^t[i+1]);
    }
    return ans;
}

void comparePermute(int starter=0){
    if(starter==n){
        ans2.push_back(t);
        minXor = min(Xor(t), minXor);
        return;
    }

    for(int pointer = starter; pointer<n;pointer++){
        swap(t[starter], t[pointer]);
        comparePermute(starter+1);
        swap(t[starter], t[pointer]);
    }
}

int main()
{
        cin>>n;
        for(int i=0;i<n;i++)t.push_back(i);
        comparePermute();

        for(int ii = 0; ii<ans2.size(); ii++){
            vector<int> i = ans2[ii];
            if(Xor(i)== minXor ){
                srint(i);
                cout
                <<"xor: "<<minXor
                <<" "<<ii <<"\n";
            ans.push_back(i);
            }
        }

    //print(ans);
    // print(ans);
}