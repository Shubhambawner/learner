#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin>>n;
    while(n--){
        string t; cin>>t;
        string f; cin>>f;
        int fc = -1;
        for(int i = 0; i<t.size() ; i++){
            char d = t[i];
            int tfc = fc+1;
            if(d==f[tfc]) fc = tfc;
            else{
                int y = 0;
                while(tfc>y && d!=f[y]){ y++;}
                if(d==f[y]) fc = y;
            }
        }

        if(f.size()-1==fc) cout<<"YES\n";
        else cout<<"NO\n";

    }
}