//! no support for stack/que for printing
//! no error thrown when undefined variables are printed
#include <bits/stdc++.h>
#include <typeinfo>
#include <cxxabi.h>
#include <cstdlib>
#include <memory>
using namespace std;string spacing = "\n";int far = 7;bool indexing = true;string dep(string s, int color = 90){return "\033[3;" + to_string(color) + "m" + s + "\033[0m";}string List[3] = {"[_ ", " _ ", " _]"};string Set[3] = {"(", ", ", ")"};string Map[3] = {"[", ", ", "]"};string Vector[3] = {"[", ", ", "]"};string Pair[3] = {"", " : ", ""};string Queue[3] = {"", " : ", ""};string PQueue[3] = {"", " : ", ""};string DQueue[3] = {"", " : ", ""};string Stack[3] = {"", " : ", ""};vector<int> Count(string txt, string ptr){vector<int> ans;int c = 0;for (int i = 0; i < txt.size(); i++){if (txt[i] == ptr[c]){c++;if (c == ptr.size()){ans.push_back(i);c = 0;}}else c = 0;}return ans;}string demangle(const char* mangledName){int status = -1;char* demangledNameCStr = abi::__cxa_demangle(mangledName, nullptr, nullptr, &status);string demangledName;if (status == 0){demangledName = demangledNameCStr;} else{demangledName = mangledName;}return demangledName;}
template <class T>string getType(T t){const char *type_of_t = typeid(t).name();string r = demangle(type_of_t);return r;}
bool isNested(string r){return Count(r, "std::allocator").size() - Count(r, "std::__cxx11::basic_string").size() > 1;}
bool isQueueStack(string r){return Count(r, "stack").size() || Count(r, "queue").size() || Count(r, "deque").size(); }
template <class T>ostream &handle(ostream &out, T v, string start = "[", string mid = ", ", string end = "]", bool indexing = true){string dataType = getType(v);bool isAdv = isNested(dataType);out << start;if (isAdv){for (int i = 0; i < far; i++){spacing += " ";}}int j = 0;for (auto i = v.begin(); i != v.end() && j < 50; i++, j++){if (isAdv){out << spacing;if (indexing)out << dep(to_string(j));}out << *i;if (j < v.size() - 1)out << mid;if (j == 49){if (isAdv)out << spacing;out << dep("..." + to_string(v.size() - 50) + " more ");}}if (isAdv){spacing.erase(spacing.size() - far);out << spacing;}out << end;out << dep(to_string(v.size())) << " ";return out;}
template <class T, class R>ostream &operator<<(ostream &out, const pair<T, R> &v){string dataType = getType(v.second);bool a = isNested(dataType);out << " " << Pair[0];out << v.first << Pair[1] << v.second;out << Pair[2];return out;}
template <class T>ostream &operator<<(ostream &out, const list<T> v){return handle(out, v, List[0], List[1], List[2], indexing);}
template <class T, class R>ostream &operator<<(ostream &out, const map<T, R> v){return handle(out, v, Map[0], Map[1], Map[2], false);}
template <class T>ostream &operator<<(ostream &out, const set<T> v){return handle(out, v, Set[0], Set[1], Set[2], indexing);}
template <class T>ostream &operator<<(ostream &out, const vector<T> v){return handle(out, v, Vector[0], Vector[1], Vector[2], indexing);}
template <class T>ostream &operator<<(ostream &out, const forward_list<T> v){return handle(out, v, List[0], List[1], List[2], indexing);}
template <class T, class R>ostream &operator<<(ostream &out, const multimap<T, R> v){return handle(out, v, Map[0], Map[1], Map[2], false);}
template <class T>ostream &operator<<(ostream &out, const multiset<T> v){return handle(out, v, Set[0], Set[1], Set[2], indexing);}
template <class T, class R>ostream &operator<<(ostream &out, const unordered_map<T, R> v){return handle(out, v, Map[0], Map[1], Map[2], false);}
template <class T>ostream &operator<<(ostream &out, const unordered_set<T> v){return handle(out, v, Set[0], Set[1], Set[2], indexing);}
template <class T, class R>ostream &operator<<(ostream &out, const unordered_multimap<T, R> v){return handle(out, v, Map[0], Map[1], Map[2], false);}
template <class T>ostream &operator<<(ostream &out, const unordered_multiset<T> v){return handle(out, v, Set[0], Set[1], Set[2], indexing);}
template <class T>ostream &operator<<(ostream &out, const stack<T> v){out<<"no support for stack/que for printing\n";return out;}
template <class T>ostream &operator<<(ostream &out, const priority_queue<T> v){out<<"no support for stack/que for printing\n";return out;}
template <class T>ostream &operator<<(ostream &out, const queue<T> v){out<<"no support for stack/que for printing\n";return out;}
template <class T>ostream &operator<<(ostream &out, const deque<T> v){out<<"no support for stack/que for printing\n";return out;}void _w_recursive(){} 
template <typename T, typename... Types>void _w_recursive(T var1, Types... var2){cout  << var1 << " "; _w_recursive(var2...);}
template <typename... Types>void _w(Types... var2){cout << spacing  ; _w_recursive(var2...);}void _w_(){}
template <typename... Types>void _w_(Types... var2){cout << spacing  ; _w_(var2...);}string unitSeperator = "|     ";string enterArrow = "|-----";
template <typename T, typename... Types>void _e(T functionName, Types... t){string fnName = (string)functionName+"() ";string enterSpace=spacing;if(enterSpace.size()>=unitSeperator.size()){ enterSpace = enterSpace.erase(enterSpace.size() - unitSeperator.size());enterSpace+=enterArrow;}cout<<enterSpace<<fnName;spacing += unitSeperator;_w(t...);}void _e(){spacing += unitSeperator;cout << spacing;}
template <typename... Types>void _b(Types... t){spacing = spacing.erase(spacing.size() - unitSeperator.size());_w(dep("return "), t...);}
void _b(){spacing = spacing.erase(spacing.size() - unitSeperator.size());_w(dep("return"));}
#define _e(...) _e( __FUNCTION__ __VA_OPT__(,) __VA_ARGS__)
#define recurse _e
#define returnRecurse _b