#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int m,n;
        cin >> m;
        cin >> n;
        int ans = 2;
        if(m*n==0){ 
        if(m==0)ans--;
        if(n==0)ans--;}
        else if(sqrt(m*m + n*n)==floor(sqrt(m*m + n*n))){
            cout<<"1\n";continue;
        }
        cout<<ans<<" \n";
    }
}