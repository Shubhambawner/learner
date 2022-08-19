// { Driver Code Starts
#include "../util/recursion_utilities.cpp"
// #define w 
// #define e 
// #define b 
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int main()
{
    int T;cin>>T;
    while(T--){
        long long int a;cin>>a;
        long long int b;cin>>b;
        long long int c;cin>>c;
        long long int d;cin>>d;
        long long int t = a*d, s = b*c;
        w("debug: ",a,b,c,d,s,t, "|| ");
        if(s==t)cout<<"0\n";
        else{
            w('a');
            if(t<s){
                long long r = t;t=s;s=r;
            }
            if(s==0 || t%s==0)cout<<"1\n";
            else cout<<"2\n";
        }
    }
} // } Driver Code Ends