#include "./print_stl_operator_overloaded.cpp"


// base case
void w_recursive()
{
}
 
// Variadic function Template that takes
// variable number of arguments and prints
// all of them space separated recursively.
template <typename T, typename... Types>
void w_recursive(T var1, Types... var2)
{
    cout  << var1 << " ";
 
    w_recursive(var2...);
}

// Variadic function Template that takes
// variable number of arguments and prints
// all of them space separated recursively with spacing maintained.
template <typename... Types>
void w(Types... var2)
{
    cout << spacing  ;
 
    w_recursive(var2...);
}
 
// int main(){
//     w({"www","refsfd","234w3"},true,233,24214124214,23.23412);
// }