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
        int n, l, p=0; 
        cin >> n >>l;
        for(int i=1;i<n;i++){
            int h;cin>>h;
            if(h<l){
                i++;p++;
                if(i<n)cin>>l;
            }else{
                l = h;
            }
        }
        cout<<p<<endl;
    }
}//constructively building the array : sum of previous elements....
