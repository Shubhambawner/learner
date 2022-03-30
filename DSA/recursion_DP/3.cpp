#include <bits/stdc++.h>
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


int main()
{
    // cout<<palindrome("MADAM");
    // cout<<flip("1234567890");
    // cout<<fibonacci(10);
}