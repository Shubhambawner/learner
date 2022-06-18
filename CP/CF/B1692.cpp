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
    int t;
    cin >> t;
    while(t--){
        int n;cin>>n;
        set<int> s;
        for(int i = 0; i<n; i++){int m;cin>>m;s.insert(m);}
        if((n-s.size())%2==0)cout<<s.size()<<endl;
        else cout<<s.size()-1<<endl;
    }
}
