#include <bits/stdc++.h>
using namespace std;
void printArr(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m,n,k=0;//! it is must to initiate k with 0, otherwise it will pick up any garbage value!
        cin>>n>>m;
        for(int i = 0; i<n; i++){
            int j;
            cin>>j;
            k+=j;
        }
        // cout<<n<<"-- "<<m<<" "<<k<<"\n";
        if(k-m>0)m=k-m;
        else m = 0;
        cout<<m<<"\n";
    }
}


