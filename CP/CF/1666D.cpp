#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin>>n;
    while(n--){
        string t; cin>>t;
        string f; cin>>f;
        int lastIndex = f.size()-1;
        map<char,int>pos;
        // for(int i=0;i<f.size();i++){
        //     pos[f[i]]=i+1;
        // }
        char c = f[lastIndex];
        bool flag = false;
        for(int i = t.size()-1; i>0; i--){
            
            if(t[i]==c){
                c=f[--lastIndex];
            }
        }
        if((lastIndex%f.size())==0){
            cout<<"YES\n";
        }else cout<<"NO\n";
    }
}