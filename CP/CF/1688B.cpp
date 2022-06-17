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
        int n; //! it is must to initiate k with 0, otherwise it will pick up any garbage value!
        cin >> n;
        int minp = 2000000000, evnum = 0;bool odd = false;
        for (int i = 0; i < n; i++)
        {
            int j;
            cin >> j;
            if (j % 2 == 0)
            {
                evnum++;
                int p = 0;
                while (j % 2 == 0)
                {
                    j /= 2;
                    p++;
                }
                if (p < minp)
                    minp = p;
            }else odd = true;
        }
        // cout<<n<<"-- "<<m<<" "<<k<<"\n";
        if (evnum == 0)
            cout << "0\n";
        else
        {
            if (!odd)
                cout << evnum + minp - 1 << "\n";
            else
                cout << evnum << "\n";
        }
    }
}
