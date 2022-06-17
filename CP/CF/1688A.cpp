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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if(n==1){cout<<"3\n";continue;}
        int ans = pow(2,__builtin_ffs(n) - 1);
        if (n / ans == 1)
            ans++;
        cout << ans<<endl;
    }
}
