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
        int n,sum=0;cin>>n;
        set<int> a;
        for(int i = 0; i<n;i++){
            int j;cin>>j;
            a.insert(j);
            sum+=j;
        }
        if(sum%n!=0){
            cout<<"NO\n";continue;
        }sum=sum/n;
        if(a.find(sum)==a.end())cout<<"NO\n";
        else cout<<"YES\n";
    }
}
