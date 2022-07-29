//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {
        // code here
        sort(arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        unordered_map<int, int> s;
        for (int i = 0; i < n; i++)
            s[arr[i]]++;

        int p1 = 0, p2 = n - 1, a = 0;

        while (p1 <= p2)
        {cout<<"==="<<a<<endl;
            cout << arr[p1] << " - " << arr[p2] << endl;
            if (k == arr[p1] + arr[p2])
            {
                cout << s[arr[p1]] <<" "<< s[arr[p2]]<< "e\n";
                if (k == arr[p1] * 2)
                {
                    a += s[arr[p1]] * (s[arr[p2]] - 1);
                    break;
                }
                else
                    a += s[arr[p1]] * s[arr[p2]];
                while (arr[p2] == arr[p2 - 1])
                    p2--;
                p2--;
                while (arr[p1] == arr[p1 + 1])
                    p1++;
                p1++;
            }
            else if (k < arr[p1] + arr[p2])
            {
                while (arr[p2] == arr[p2 - 1])
                    p2--;
                p2--;
            }
            else if (k > arr[p1] + arr[p2])
            {
                while (arr[p1] == arr[p1 + 1])
                    p1++;
                p1++;
            }
        }
        return a;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }

    return 0;
}
// } Driver Code Ends