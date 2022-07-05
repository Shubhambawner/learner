#include <bits/stdc++.h>
#define ll long long
using namespace std;
//* default value of parameters passed in C++
//* https://www.programiz.com/cpp-programming/default-argument#:~:text=In%20C%2B%2B%20programming%2C%20we%20can%20provide%20default%20values,calling%20the%20function%2C%20the%20default%20arguments%20are%20ignored.

bool palindrome(string s, int start = 0)
{ //* default value of parameters passed in C++, Must be at the end of the parameters list !
    //! if(s.length()<=1) return true; even when i put this wrong base case, it ran, it did not get crashed, no seg.falt, output 0 !
    if (start >= s.length() / 2)
        return true;
    if (s[start] == s[s.length() - 1 - start])
        return palindrome(s, ++start);
    return false;
}

string flip(string s, int start = 0)
{
    if (start >= s.length() / 2)
        return s;
    cout << s << "\n";
    char temp = s[start];
    s[start] = s[s.length() - 1 - start];
    s[s.length() - 1 - start] = temp;
    return flip(s, start + 1);
}

//! multiple recursion calls: roughly exponencial time complexicity !!
int fibonacci(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

vector<long long> d = {0,1};
long long fibonacci_dp(int n ){
    if(n<d.size()) return d[n];
    else if(n==d.size()){
        d.push_back(d[n-1]+d[n-2]);
        return d[n];
    }else{
        return fibonacci_dp(n-1)+fibonacci_dp(n-2);
    }
}

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
    // cout<<fibonacci(20)<<endl;
    cout<<fibonacci_dp(45)<<"\n";
    cout<<fibonacci_dp_space_optimised(45);
}