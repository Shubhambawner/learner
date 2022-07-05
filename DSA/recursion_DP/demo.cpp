#include "./ru.cpp"
using namespace std;
int main()
{
    vector<vector<string>> v = {{"aa", "awa", "qaa", "aar"}, {"aa", "qaa", "aar"}, {"rtaa", "aawrawwa", "agqaa", "aahgear"}};
    vector<list<string>> vv = {{"aa", "awa", "qaa", "aar"}, {"aa", "qaa", "aar"}, {"rtaa", "aawrawwa", "agqaa", "aahgear"}};
    list<vector<int>> l = {{1, 2}, {3, 4, 5, 6}, {1, 2, 3, 4, 5, 6, 3, 4, 5, 6}, {3, 4, 5, 6}};
    list<int> s = {1, 2, 3, 4, 5, 6};
    map<int, list<vector<int>>> m = {{1, {{4, 4, 5, 6}, {6, 6}}}, {3, {{1, 4, 5}, {3, 5, 6}}}, {5, {{3, 4}, {5, 6}}}};

    cout << v << endl << endl
         << vv << endl << endl
         << l << endl << endl
         << m << endl << endl
         << s << endl << endl;
}