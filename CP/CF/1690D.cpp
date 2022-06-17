#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n>>k;
        vector<char> c;
        int wc= 0, t=0;
        for (int i = 0; i < n; i++)
        {
            char y;cin>>y;
            c.push_back(y);
            
            if(i-k<0 && c[i]=='W'){wc++;t++;}
            if(i-k>=0){
                if(y=='W'){wc++;}
                if(c[i-k]=='W'){wc--;}
                t=min(t,wc);
            }
        }
        cout<<t<<"\n";
    }
}
