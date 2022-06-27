#include <bits/stdc++.h>
#define ll long long int
#define f(n) for(long long int i = 0; i<n; i++) //forward loop
#define fa(a, n) for(long long int i = a; i<n; i++)
#define r(n) for(long long int i = n-1; i>=0; i--) //reverse loop
#define ra(n, a) for(long long int i = n-1; i>=a; i--)
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

template<class t>
void Arr(t*arr, long long n){
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        // cout<<arr[i]<<" ";
    }
    // cout<<" \n";
}

void solve(){
    int n;cin>>n;
    long long A=MIN, sum = 0;
    f(n){
        long long j;cin>>j;
        if(j>A){A=j;}
        sum+=j;
    }
    if(sum+1>=2*A)cout<<"YES\n";
    else cout<<"NO\n";
}

main()
{
    setup();
    // // cout<<(int)'a';
    long long int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}