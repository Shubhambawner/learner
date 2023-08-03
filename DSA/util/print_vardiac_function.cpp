#include "print_stl_operator_overloaded.cpp"

/* //? why needed? cout can do all the printing the _w or _w_ are doing: for recurse and return recurse functions:
we can do _w(t...);
but not cout<<t...;
so this file

recursion_utilities.cpp:21:12: error: expected ';' before '...' token
   21 |     cout<<t...;
      |            ^~~
      |            ;
recursion_utilities.cpp:21:9: error: parameter packs not expanded with '...':
   21 |     cout<<t...;
      |     ~~~~^~~
    
*/
// base case
void _w_recursive()
{
}

 
// Variadic function Template that takes
// variable number of arguments and prints
// all of them space separated recursively.
template <typename T, typename... Types>
void _w_recursive(T var1, Types... var2)
{
    cout  << var1 << " ";
 
    _w_recursive(var2...);
}

// Variadic function Template that takes
// variable number of arguments and prints
// all of them space separated recursively _with spacing maintained.
template <typename... Types>
void _w(Types... var2)
{
    cout << spacing  ;
 
    _w_recursive(var2...);
}

// base case
void _w_()
{
}

template <typename... Types>
void _w_(Types... var2)
{
    cout << spacing  ;
 
    _w_(var2...);
}

// int main(){
//     _w({"www","refsfd","234w3"},true,233,24214124214,23.23412);
// }