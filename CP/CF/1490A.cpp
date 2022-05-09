#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        int ans = 0;
        for (int i = 0; i < n-1; i++)
        {
            float M = max(arr[i], arr[i+1]);
            float N = min(arr[i], arr[i+1]);
            while((M/N)>2) {ans++;M=(M/2);}
        }
        
        cout<<ans<<endl;
    }
}