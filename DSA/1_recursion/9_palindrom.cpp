#include <bits/stdc++.h>
using namespace std;
#include "./recursion_utilities.cpp"

string s = "";

// palindrome partitioning, partition given string into pallindromes, aaba: a,aba or a,a,b,a...
// find no. of partitions possible

vector<string> temp;
bool isPal(int start, int end, string s)
{
    if (start >= end)
        return true;
    if (s[start] == s[end])
        return isPal(start + 1, end - 1, s);
    return false;
}
vector<vector<string>> ans;
int start = 0;
void rc(string s)
{
    if(!s.size()){
        ans.push_back(temp);
    }else{
        for (int i = 0; i < s.size(); i++)
        {
            if(isPal(0,i,s)){
                temp.push_back(s.substr(0,i+1));
                rc(s.substr(i+1, s.size()-i-1));
                temp.pop_back();
            }
        }
        
    }
}
vector<vector<string>> partition(string st)
{
    rc(st);
    return ans;
}
int main(){
    partition("aaba");
    cout<< ans;
}