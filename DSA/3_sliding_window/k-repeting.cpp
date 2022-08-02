#include <bits/stdc++.h>
#include "../util/recursion_utilities.cpp"
using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> m;
        string t ;
        for(int i=0;i<s.size();i++){
            t=s.substr(i,10);
            m[t]++;
        }
        cout<<m<<endl;
        vector<string>ans;
        for(auto i:m)if(i.second>1)ans.push_back(i.first);
        return ans;
    }

    int main(){
        cout<<findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    }