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
        int n, p =  0, k=0; 
        cin >> n ;
        char c[n];
        for(int i=0;i<n;i++){
            cin>>c[i];
        }
        p+=n%2;
        char t = c[n/2];
        while(n/2+k+(n%2)<n && c[n/2+k+(n%2)]==t){
            p+=2;k++;
        }
        cout<<p<<endl;
    }
}
