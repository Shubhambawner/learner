//* fix size sliding window

// to find 1st -ve elem in each sub-array of size k
// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
// aproach:
/*

*/
//{ Driver Code Starts
#include <bits/stdc++.h>
#include "../util/recursion_utilities.cpp"
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{

    vector<long long> ans;

    //* initialise ds to be maintained as state of the window
    //* here ds contains all -ve elements in the window in order they appear in window
    list<int> ds;

    //* window running over the length:n, window size(fixed here): k
    int n = N, k = K;
    //* initialise window variables
    //* window soans from index i to j-1 both inclusive, or [i,j)
    int i = 0, j = 0;

    while (j<=n)
    {
        //* step 1: initial window forming
        // for fixed size only condition for window to be formed is size should be k
        if (j <= k-1 ) //j denotes no. of included elements while initial window forming
        {
            //*expanding window maintaining the state, i.e. the ds
            if (A[j] < 0)
                ds.push_back(A[j]); // update state of ds
            j++;                    // update window size (increasing)

            continue;
        }
        //* step 2:  operation on window formed in previous step
        // make sure this step receivs the window with proper state always,
        // as we are calculating answer in here
        cout<<ds<<endl;
        if (ds.size() > 0)
            ans.push_back(ds.front());
        else
            ans.push_back(0);

        //* step 3:  shifting window towards end
        // first we modify the state, then we move the ppointers
        // while modifying state, check for j<n as j is 1+last index in the window, which can become n for the last loop.
        //* 3.1 shrinking window: incrasing i
        if (A[i] < 0)
            ds.pop_front();
        i++;
        //* 3.1 growing window: incrasing j
        if (j == n)
            break; // window cant grow any more, so process is terminated
        if (A[j] < 0)
            ds.push_back(A[j]);
        j++;
    }

    return ans;
}

// Driver program to test above functions
int main()
{
    long long int t=1, i;
    // cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}