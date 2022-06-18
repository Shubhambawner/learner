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
    // ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){//cout<<"1\n";
        int n,N=0,m,M=0;
        cin>>m;
        for (int i = 0; i < m; i++)
        {
            int j;cin>>j;M=max(j,M);//cout<<M<<"$\n";
        }
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            int j;cin>>j;N=max(j,N);//cout<<N<<"*\n";
        }
        if(M==N){
            cout<<"Alice\nBob\n";
        }else if(M<N){
            cout<<"Bob\nBob\n";
        }else{
            cout<<"Alice\nAlice\n";
        }
    }
}
