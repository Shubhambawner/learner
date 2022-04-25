#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int n, k;
        cin>>n>>k;
        if(k*n==1)cout<<"YES\n1\n";
        else if(n%2==1 && k!=1) cout<<"NO\n";
        else {
            cout<<"YES\n";
            for (int i = 1; 2*i <= n*k; i++)
            {
                cout<<2*i<<" ";
                if(i%k==0) cout<<"\n";
            }
            
            for (int i = 1; 2*i - 1 <= n*k; i++)
            {
                 cout<<2*i - 1<<" ";
                if(i%k==0) cout<<"\n";
            }
            
        }
    }
}