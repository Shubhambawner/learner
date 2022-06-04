#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll MOD = 1000000007;

ll solve(ll n, ll k)
{
    ll N = n,i=0; int j=0;
    map<int, int> a ;
    for(i;i<n;i++){
        cin>>j;
        a[j]=i;
    }
    ll d=0, sum=0;
    for(auto i=a.begin(); i!=a.end();i++,k--){
        if(k){ d+=i->first+n-i->second-1;}
        sum+=i->first;
    }
    d+= k*(k+1)/2;
    return sum-d;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        ll n, k;
        cin >> n >> k;
        ll ans = solve(n, k);
        cout << ans << endl;
    }
}