#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int d[n][2];
        for(int i  =0; i<n;i++){
            cin>>d[i][0];
        }
        for(int i  =0; i<n;i++){
            cin>>d[i][1];
        }
        cout<<d[0][1]-d[0][0]<<" ";
        for(int i  =1; i<n;i++){
            cout<<min(d[i][1]-d[i][0],d[i][1]-d[i-1][1])<<" ";
        }cout<<"\n";
    }
}