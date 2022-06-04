#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll MOD = 1000000007;

ll solve(ll n, ll k)
{
    ll ans = 0, N = n;
    n = 1;
    int r;
    while (k != 0)
    {
        r = k % 2;
        ans += ((r) * (n % MOD)) % MOD;
        ans = ans % MOD;
        k /= 2;
        n *= N % MOD;
        n = n % MOD;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        ll n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
}