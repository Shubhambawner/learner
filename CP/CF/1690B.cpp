#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, D=0;
        cin >> n;
        int d[n][2];
        for(int i  =0; i<n;i++){
            cin>>d[i][0];
        }
        for(int i  =0; i<n;i++){
            cin>>d[i][1];
            D = max(d[i][0] - d[i][1],D);
        }
        bool f = true;
        for(int i  =0; i<n;i++){
            if((d[i][0]-D<=0 && d[i][1]==0) || d[i][0]-D==d[i][1])continue;
            f=false;
            cout<<"NO\n";break;
        }
        if(f)cout<<"YES\n";
    }
}