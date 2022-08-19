// overloaded ostream operator<<
template <class T, class R>
ostream &operator<<(ostream &out, const pair<T, R> &v)


// find the type of any variable t, https://en.cppreference.com/w/cpp/types/type_info/name
#include <boost/core/demangle.hpp>
#include <typeinfo>
string t = "asd";
const char *type_of_t = typeid(t).name();	 
string r = boost::core::demangle(type_of_t);  // converted type_of_t to human redable form
// so,	r is 'std::__cxx11::basic_string'

// console output styling: https://stackoverflow.com/a/54062826
string dep(string s, int color = 90)
{
	return "\033[3;" + to_string(color) + "m" + s + "\033[0m";
}


// Variadic function Template that takes variable number of arguments and prints all of them space separated recursively.
template <typename T, typename... Types>
void w_recursive(T var1, Types... var2)
{
    cout  << var1 << " ";
 
    w_recursive(var2...);
}
// base case, is MUST
void w_recursive()
{
}


// to know function caller name: https://www.techiedelight.com/find-name-of-the-calling-function-in-cpp/
w(__func__, __PRETTY_FUNCTION__, __FUNCTION__);

// vardiac macros: https://gcc.gnu.org/onlinedocs/cpp/Variadic-Macros.html
#define e(...) e(__PRETTY_FUNCTION__, __VA_ARGS__)
