#include <bits/stdc++.h>
#include "../util/recursion_utilities.cpp"
using namespace std;

//* Variable sized window:
/*
to find smallest substring that has all characters of string t
logic:

*/

string minWindow(string s, string t)
{
    vector<int> tm(128, 0);
    for (auto i : t)
        tm[i]++;
    vector<int> w(128, 0);
    int count = t.size(), d = 1000000, head = 0, i = 0, j = 0, n = s.size();
    while (j <= n)
    {
        while (count == 0 && i < j)
        {
            if (j - i < d)
            {
                head = i;
                d = j - i;
            }
            w[s[i]]--;
            if (w[s[i]] < tm[s[i]])
                count++;
            i++;
        }
        if (j == n)
            break;
        w[s[j]]++;
        if (w[s[j]] <= tm[s[j]])
            count--;
        j++;
    }
    if (d == 1000000)
        return "";
    else
        return s.substr(head, d);
}