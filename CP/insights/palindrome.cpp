#include<bits/stdc++.h>
using namespace std;
/**
 * //* Palindrome is string with root ang 2 wings
 * //* like: 12345aaaaa54321 here the root is substring aaaaa
 * //* any single char or substring of same char. can be palindrome root.
 */

//* here, for searcing longest pal. we search for roots, and then find corrosponding pall
string longestPalindrome(string s)
{
    if (s.empty())
        return "";
    if (s.size() == 1)
        return s;
    int start = 0, len = 1, n = s.size();

    for (int i = 0; i < s.size();)
    {
        if (n - i <= len / 2)
            break;

        int j = i, k = i;

        while (k < n - 1 && s[k + 1] == s[k])
            ++k;
        i = k + 1;

        while (k < n - 1 && j > 0 && s[k + 1] == s[j - 1])
        {
            ++k;
            --j;
        }
        int new_len = k - j + 1;
        if (new_len > len)
        {
            start = j;
            len = new_len;
        }
    }

    return s.substr(start, len);
}

int main()
{
    cout << longestPalindrome("12211331");
}