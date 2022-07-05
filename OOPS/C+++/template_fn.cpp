#include <boost/core/demangle.hpp>
#include <bits/stdc++.h>
using namespace std;

// to show behaviour of template function at compile time
int i = 4;
template <class p,class q>
void red(p v)
{
    if (i)
    {
        i--;
        cout << boost::core::demangle(typeid(v).name()) << " " << v << "\n";
        q temp = v * 100000;
        red(temp);
    };
}

int main(){
    red<bool,int>(true);
}

/*
template_fn.cpp:In instantiation of 'void red(p) [with p = bool; q = int]':
template_fn.cpp:20:23:   required from here
template_fn.cpp:15:12: error: no matching function for call to 'red(int&)'
   15 |         red(temp);
      |         ~~~^~~~~~
*/