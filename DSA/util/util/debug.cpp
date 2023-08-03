#include <bits/stdc++.h>
#include <typeinfo>
#include <cxxabi.h>
#include <cstdlib>
#include <memory>

using namespace std;

string spacing = "\n";
// increment/decrement in spacing for nested stl containers
int far = 7;
bool indexing = true;

// converts string to depressed style for output
// output styling: https://stackoverflow.com/a/54062826
string dep(string s, int color = 90)
{
	return "\033[3;" + to_string(color) + "m" + s + "\033[0m";
}

// contains 3 elements for start, mid(concatenating elements), end of container while printing it out
string List[3] = {"[_ ", " _ ", " _]"};
string Set[3] = {"(", ", ", ")"};
string Map[3] = {"[", ", ", "]"};
string Vector[3] = {"[", ", ", "]"};
string Pair[3] = {"", " : ", ""};

// TODO
string Queue[3] = {"", " : ", ""};
string PQueue[3] = {"", " : ", ""};
string DQueue[3] = {"", " : ", ""};
string Stack[3] = {"", " : ", ""};

// occurances of pattern ptr(*) in string txt, with ptr having unique characters
// *: for which all of lps array is 0
// https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
vector<int> Count(string txt, string ptr)
{
	vector<int> ans;
	int c = 0;
	for (int i = 0; i < txt.size(); i++)
	{
		if (txt[i] == ptr[c])
		{
			c++;
			if (c == ptr.size())
			{
				ans.push_back(i);
				c = 0;
			}
		}
		else
			c = 0;
	}
	return ans;
}

string demangle(const char* mangledName) {
    int status = -1;

    // Demangle the mangled name using abi::__cxa_demangle.
    char* demangledNameCStr = abi::__cxa_demangle(mangledName, nullptr, nullptr, &status);

    string demangledName;
    if (status == 0) {
        // If demangling was successful, copy the result to a C++ string.
        demangledName = demangledNameCStr;
        free(demangledNameCStr); // Free the memory allocated by abi::__cxa_demangle.
    } else {
        // If demangling failed, set the original mangled name as the result.
        demangledName = mangledName;
    }

    return demangledName;
}

// finds wether type of stl container being passed(i.e. T) is nested(contains any other container inside)
template <class T>
string getType(T t){
	const char *type_of_t = typeid(t).name();	 // returned raw type of t, https://en.cppreference.com/w/cpp/types/type_info/name
	string r = demangle(type_of_t); // converted type_of_t to human redable form
	// cout<<dep(r)<<endl;
	return r;
}

bool isNested(string r)
{
	return Count(r, "std::allocator").size() - Count(r, "std::__cxx11::basic_string").size() > 1;
	//* finds no. of containers in type's description, but as string is also a container, we substract it
}

bool isQueueStack(string r){
	return Count(r, "stack").size() || Count(r, "queue").size() || Count(r, "deque").size(); 
}


// generates output stream for given iterable container T, using start mid and end strings
// if it is nested container, it will be printed automatically in separate lines using spacing recursively
template <class T>
ostream &handle(ostream &out, T v, string start = "[", string mid = ", ", string end = "]", bool indexing = true)
{

	string dataType = getType(v);
	bool isAdv = isNested(dataType);
	
	// if(isAdv)out <<spacing ;
	out << start;
	if (isAdv)
	{
		for (int i = 0; i < far; i++)
		{
			spacing += " ";
		}
	}
	int j = 0;

	for (auto i = v.begin(); i != v.end() && j < 50; i++, j++)
	{
		if (isAdv)
		{
			out << spacing;
			if (indexing)
				out << dep(to_string(j));
		}
		out << *i;

		if (j < v.size() - 1)
			out << mid;

		if (j == 49)
		{
			if (isAdv)
				out << spacing;
			out << dep("..." + to_string(v.size() - 50) + " more ");
		}
	}

	if (isAdv)
	{
		spacing.erase(spacing.size() - far);
		out << spacing;
	}
	out << end;
	out << dep(to_string(v.size())) << " ";

	return out;
}

// pair is seperately overloaded, not like all others
// overloaded ostream operator<<
template <class T, class R>
ostream &operator<<(ostream &out, const pair<T, R> &v)
{
	string dataType = getType(v.second);
	bool a = isNested(dataType);
	out << " " << Pair[0];
	out << v.first << Pair[1] << v.second;
	out << Pair[2];
	return out;
}


// overloaded ostream operator<<
template <class T>
ostream &operator<<(ostream &out, const list<T> v)
{
	return handle(out, v, List[0], List[1], List[2], indexing);
}

// overloaded ostream operator<<
template <class T, class R>
ostream &operator<<(ostream &out, const map<T, R> v)
{
	return handle(out, v, Map[0], Map[1], Map[2], false);
}

// overloaded ostream operator<<
template <class T>
ostream &operator<<(ostream &out, const set<T> v)
{
	return handle(out, v, Set[0], Set[1], Set[2], indexing);
}

// overloaded ostream operator<<
template <class T>
ostream &operator<<(ostream &out, const vector<T> v)
{
	return handle(out, v, Vector[0], Vector[1], Vector[2], indexing);
}

// overloaded ostream operator<<
template <class T>
ostream &operator<<(ostream &out, const forward_list<T> v)
{
	return handle(out, v, List[0], List[1], List[2], indexing);
}

// overloaded ostream operator<<
template <class T, class R>
ostream &operator<<(ostream &out, const multimap<T, R> v)
{
	return handle(out, v, Map[0], Map[1], Map[2], false);
}

// overloaded ostream operator<<
template <class T>
ostream &operator<<(ostream &out, const multiset<T> v)
{
	return handle(out, v, Set[0], Set[1], Set[2], indexing);
}
// overloaded ostream operator<<
template <class T, class R>
ostream &operator<<(ostream &out, const unordered_map<T, R> v)
{
	return handle(out, v, Map[0], Map[1], Map[2], false);
}

// overloaded ostream operator<<
template <class T>
ostream &operator<<(ostream &out, const unordered_set<T> v)
{
	return handle(out, v, Set[0], Set[1], Set[2], indexing);
}

// overloaded ostream operator<<
template <class T, class R>
ostream &operator<<(ostream &out, const unordered_multimap<T, R> v)
{
	return handle(out, v, Map[0], Map[1], Map[2], false);
}

// overloaded ostream operator<<
template <class T>
ostream &operator<<(ostream &out, const unordered_multiset<T> v)
{
	return handle(out, v, Set[0], Set[1], Set[2], indexing);
}

// overloaded ostream operator<<
template <class T>
ostream &operator<<(ostream &out, const stack<T> v)
{
	out<<"no support for stack/que for printing";
		return out;
}

// overloaded ostream operator<<
template <class T>
ostream &operator<<(ostream &out, const priority_queue<T> v)
{
	out<<"no support for stack/que for printing";
		return out;
}

// overloaded ostream operator<<
template <class T>
ostream &operator<<(ostream &out, const queue<T> v)
{
	out<<"no support for stack/que for printing";
		return out;
}

// overloaded ostream operator<<
template <class T>
ostream &operator<<(ostream &out, const deque<T> v)
{out<<"no support for stack/que for printing";
		return out;
}


//////////////////
//////////////////
//////////////////
//////////////////
//////////////////
//////////////////
//////////////////
//////////////////
//////////////////
//////////////////
//////////////////
//////////////////
//////////////////
//////////////////


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


/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////

string unitSeperator = "|     ";
string enterArrow = "|-----";

// recurse enter _e()
template <typename T, typename... Types>
void _e(T functionName, Types... t)
{
    string fnName = (string)functionName+"() ";
    string enterSpace=spacing;

    if(enterSpace.size()>=unitSeperator.size()){ 
        enterSpace = enterSpace.erase(enterSpace.size() - unitSeperator.size());
        enterSpace+=enterArrow;
    }

    cout<<enterSpace<<fnName;
    spacing += unitSeperator;
    _w(t...);
}
void _e()
{
    spacing += unitSeperator;
    cout << spacing;
}


//b(): recurse exit/base case ; _e(args): recurse enter; _w(): print anything with current spacing
template <typename... Types>
void _b(Types... t)
{
    spacing = spacing.erase(spacing.size() - unitSeperator.size());
    _w(dep("return "), t...);
}
//b(): recurse exit/base case ; _e(args): recurse enter; _w(): print anything with current spacing
void _b()
{
    spacing = spacing.erase(spacing.size() - unitSeperator.size());
    _w(dep("return"));
}

//b(): recurse exit/base case ; _e(args): recurse enter; _w(): print anything with current spacing
#define _e(...) _e( __FUNCTION__ __VA_OPT__(,) __VA_ARGS__)
#define recurse _e
#define returnRecurse _b