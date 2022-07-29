#include <bits/stdc++.h>
#define ll long long
using namespace std;

// top-down approach, first it will go to base case, then compute answer while backtracking upwards
long long fibonacci_dp(int n , vector<long long>& d){
    if(d[n]!=-1) return d[n];
    if(n<=2)return d[n] = 1; //1 based indexing, so that nth fib is d[n]
    return d[n] = fibonacci_dp(n-1,d)+fibonacci_dp(n-2,d);
}

// bottom up approach
// we take the base case, then build the solution from it using the loop
ll last_second=0,last=1,N=2;
ll fibonacci_dp_space_optimised(int n){
    if(N==n){
        N++;
        last = last+last_second;
        last_second = last - last_second;
        return last;
    }else if(n==N-1)return last;
    else if(n==N-2)return last_second;
    else return fibonacci_dp_space_optimised(n-1)+fibonacci_dp_space_optimised(n-2);
}

int main()
{
    // cout<<palindrome("MADAM");
    // cout<<flip("1234567890");
    vector<long long> d = vector<long long>(21, -1);
    cout<<fibonacci_dp(20, d)<<"\n";
    cout<<fibonacci_dp_space_optimised(20);
}