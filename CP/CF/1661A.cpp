#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int n; cin>>n;
        int arr[2*n];
        for (int i = 0; i < 2*n; i++)
        {
            cin>>arr[i];
        }
        
        sort(arr, arr+2*n);
        // for(int i = 0; i<2*n; i++)cout<<arr[i]<<" ";
        // cout<<" \n";

        int ans = 0;
        for(int i =0; i<2*n-1; i++){
            if(i==n-1) continue;
            ans+= abs(arr[i]-arr[i+1]);
        }

        cout<<ans<<"\n";
    }
}