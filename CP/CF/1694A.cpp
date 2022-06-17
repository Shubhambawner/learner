#include <bits/stdc++.h>
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
    while (t--)
    {
        int a,b; //! it is must to initiate k with 0, otherwise it will pick up any garbage value!
        cin >> a>>b;
        if(a>b){
            a-=b;
            while(b--) cout<<"01";
            while(a--) cout<<"0";
        }else{
            b-=a;
            while(a--) cout<<"10";
            while(b--) cout<<"1";
        }
        
    }
}
