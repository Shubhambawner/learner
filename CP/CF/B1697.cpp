#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n,q;
    cin >> n>> q;
    ll arr[n];
    for(int i = 0; i<n;i++) cin>>arr[i]; 
    sort(&arr[0],&arr[n]);
    for(int i = 1; i<n; i++) arr[i]+=arr[i-1];
    while(q--){int x,y;cin>>x>>y;
    ll t; if(n-1-x<0)t=0; else t = arr[n-1-x];
    cout<<arr[n-1-x+y]-t<<endl;}
}
