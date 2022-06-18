#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        //cout << arr[i] << " ";
    }
    //cout << endl;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){//cout<<"1\n";
        int n,s;cin>>n>>s;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        int a = -1, b=-1, sum = 0, l=0,flag=false;
        while(sum<s && b<n-1){b++;sum+=arr[b];l++;}
        while(b<n-1){
            while(sum==s && b<n-1){l=max(l,b-a);b++;sum+=arr[b];}
            while(sum>s){a++;sum-=arr[a];}
        }
        l=max(l,b-a);
        if(sum==s)
        cout<<n-l<<"\n";
        else cout<<"-1\n";
    }
    
}
