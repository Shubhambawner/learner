#include "printutil.cpp"
using namespace std;

int fibonachi(int a)
{
      _e(a);
      if (a == 0 || a == 1)
      {
            _b();
            return a;
      }
      int g = fibonachi(a - 1) + fibonachi(a - 2);
      _b();
      return g;
}

int main()
{
      vector<vector<string>> v = {{"aa", "awa", "qaa", "aar"}, {"aa", "qaa", "aar"}, {"rtaa", "aawrawwa", "agqaa", "aahgear"}};
      vector<list<string>> vv = {{"aa", "awa", "qaa", "aar"}, {"aa", "qaa", "aar"}, {"rtaa", "aawrawwa", "agqaa", "aahgear"}};
      list<vector<int>> l = {{1, 2}, {3, 4, 5, 6}, {1, 2, 3, 4, 5, 6, 3, 4, 5, 6}, {3, 4, 5, 6}};
      list<int> s = {1, 2, 3, 4, 5, 6};
      map<int, list<vector<int>>> m = {{1, {{4, 4, 5, 6}, {6, 6}}}, {3, {{1, 4, 5}, {3, 5, 6}}}, {5, {{3, 4}, {5, 6}}}};
      stack<int> stk;
      string dd;
      cout<<stk;
      cout << dd << v << vv << l << s << m << dd;
      _w(v, vv, l, s, m, dd);
      _w("string", 'g', 44, 2342345, vv);

      fibonachi(6);
}