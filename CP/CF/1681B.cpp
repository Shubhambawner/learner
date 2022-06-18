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
    while (t--)
    {
        int n, m, bsum=0; 
        cin >> n ;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cin>>m;
        for(int i=0;i<m;i++){
            int j;
            cin>>j;
            bsum+=j;
            bsum=(bsum)%n;
        }

        cout<<arr[(bsum)%n]<<endl;
    }
}//constructively building the array : sum of previous elements....
