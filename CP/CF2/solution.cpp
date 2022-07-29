#include <bits/stdc++.h>
#define ll long long
#define f(n) for (long long i = 0; i < n; i++) // forward loop
#define fa(a, n) for (long long i = a; i < n; i++)
#define r(n) for (long long i = n - 1; i >= 0; i--) // reverse loop
#define ra(n, a) for (long long i = n - 1; i >= a; i--)
using namespace std;
int MIN = -1000000000;
int MAX = 1000000000;
void setup()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("p1.in", "r", stdin);
    freopen("p1.out", "w", stdout);
#endif
}

template <class t>
void Arr(t *arr, ll n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        // cout<<arr[i]<<" ";
    }
    // cout<<" \n";
}

void solve()
{
    int n, maxIndex = 0;
    cin >> n;
    ll z;
    cin >> z;
    ll arr[n];
    Arr(arr,n);
    ll A = arr[0], sum = 0;
    for(int i = 0; i<n;i++)
    {
        ll s = (arr[i] & z);cout<<s<<" ";
        if (s > arr[maxIndex])
            maxIndex = i;
    }
    if (maxIndex == 0)
        A = A & z;
    fa(1, n)
    {
        if (i == maxIndex)
            A = A | (A & z);
        A = A | arr[i];
    }
    cout << A <<" "<<maxIndex<< "\n";
}

main()
{
    setup();
    // // cout<<(int)'a';
    
}