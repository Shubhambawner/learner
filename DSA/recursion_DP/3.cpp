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

//* print sub-sequences
//! more efficient way: power set algorithm
list<list<int>> List;
list<int> temp;
void getSubsequences(int arr[], int size, int start = 0)
{
    if (start >= size)
    {
        List.push_back(temp);
        return;
    }
    temp.push_back(arr[start]);
    getSubsequences(arr,size, start + 1);
    temp.pop_back();
    getSubsequences(arr,size, start + 1); 
}
void print(list<list<int>> arr, int i = 1)
{
    while (!arr.empty())
    {
        cout<<i++<<"----";
        list<int> g = *arr.begin();
        list<int>::iterator it;
        for (it = g.begin(); it != g.end(); ++it)
            cout << *it << " ";
        cout << '\n';
        arr.pop_front();
    }
}
int main()
{
    // cout<<palindrome("MADAM");
    // cout<<flip("1234567890");
    // cout<<fibonacci(10);
    int arr[] = {1, 2, 3, 4, 5};
    getSubsequences(arr,16);
    print(List);
    cout << "\nend\n";
}