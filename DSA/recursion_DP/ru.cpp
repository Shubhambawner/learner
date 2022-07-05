#include <bits/stdc++.h>
#include <boost/core/demangle.hpp>
#include <typeinfo>
using namespace std;

string spacing = "\n";
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

// occurances of pattern ptr(*) in string txt
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

// finds wether type of stl container being passed(i.e. T) is nested(contains any other container inside)
template <class T>
bool isNested(T t)
{
	const char *type_of_t = typeid(t).name();	 // returned raw type of t, https://en.cppreference.com/w/cpp/types/type_info/name
	string r = boost::core::demangle(type_of_t); // converted type_of_t to human redable form
	return Count(r, "std::allocator").size() - Count(r, "std::__cxx11::basic_string").size() > 1;
	// finds no. of containers in type's description, but as string is also a container, we substract it
}


// generates output stream for given container T, using start mid and end strings
// if it is nested container, it will be printed automatically in separate lines using spacing recursively
template <class T>
ostream &handle(ostream &out, T v, string start = "[", string mid = ", ", string end = "]", bool indexing = true)
{
	bool isAdv = isNested(v);
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
	bool a = isNested(v.second);
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