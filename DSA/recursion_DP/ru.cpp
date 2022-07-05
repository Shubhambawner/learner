#include <bits/stdc++.h>
#include <boost/core/demangle.hpp>
using namespace std;

string spacing = "\n";

//converts string to depressed style for output
string dep(string s){
    return "\033[3;90m"+s+"\033[0m";
}

string List[3] = {"|~ ", " ~ ", " ~ ."};
string Set[3] = {"(",", ",")"};
string Map[3] = {"[",", ","]"};
string Vector[3] = {"{",", ","}"};
string Pair[3] = {"<"," : ",">"};

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

template <class T>
bool isAdvanced(T t)
{
	string r = boost::core::demangle(typeid(t).name());
	bool a = Count(r, "std::allocator<").size()-Count(r, "std::__cxx11::basic_string").size() > 1;
	return a;
}


template <class T, class R>
ostream &operator<<(ostream &out, const pair<T, R> &v)
{
	out << Pair[0] << v.first << Pair[1] << v.second << Pair[2];
	return out;
}

template <class T>
ostream &handle(ostream &out, T v, string start="[", string mid=", ", string end="]"){
	bool isAdv = isAdvanced(v);
	if (isAdv)
	{
		spacing += "    ";
	}
	out << dep(to_string(v.size())) << start;
	for (auto i = v.begin(); i != v.end(); i++)
	{
		if (isAdv) out << spacing;
		out << *i << mid;
	}
	for (int i = 0; i < mid.size(); i++) out << "\b";

	if (isAdv)
	{
		spacing.erase(spacing.size() - 4);
		out << spacing;
	}
	out << end;
	return out;
}

template <class T>
ostream &operator<<(ostream &out, const list<T> v)
{
	return handle(out, v, List[0], List[1], List[2]);
}

template <class T, class R>
ostream &operator<<(ostream &out, const map<T, R> v)
{
	return handle(out,v);
}

template <class T>
ostream &operator<<(ostream &out, const set<T> v)
{
	return handle(out,v,Set[0], Set[1], Set[2]);
}

template <class T>
ostream &operator<<(ostream &out, const vector<T> v)
{
	return handle(out, v,Vector[0], Vector[1], Vector[2]);
}
