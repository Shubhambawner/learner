#include "./ru.cpp"
using namespace std;
int main()
{
//     vector<vector<string>> v = {{"aa", "awa", "qaa", "aar"}, {"aa", "qaa", "aar"}, {"rtaa", "aawrawwa", "agqaa", "aahgear"}};
//     vector<list<string>> vv = {{"aa", "awa", "qaa", "aar"}, {"aa", "qaa", "aar"}, {"rtaa", "aawrawwa", "agqaa", "aahgear"}};
//     list<vector<int>> l = {{1, 2}, {3, 4, 5, 6}, {1, 2, 3, 4, 5, 6, 3, 4, 5, 6}, {3, 4, 5, 6}};
//     list<int> s = {1, 2, 3, 4, 5, 6};
//     map<int, list<vector<int>>> m = {{1, {{4, 4, 5, 6}, {6, 6}}}, {3, {{1, 4, 5}, {3, 5, 6}}}, {5, {{3, 4}, {5, 6}}}};

//     cout << v << endl << endl
//          << vv << endl << endl
//          << l << endl << endl
//          << m << endl << endl
//          << s << endl << endl;
unordered_map<int,int> s;
    int n = 4; int arr[4] = {1,2,3,3};
        for(int i = 0; i<n;i++)s[arr[i]]++;
        cout<<s;
}

/*
[
       0[aa, awa, qaa, aar]4 , 
       1[aa, qaa, aar]3 , 
       2[rtaa, aawrawwa, agqaa, aahgear]4        
]3 

[
       0[_ aa _ awa _ qaa _ aar _]4 , 
       1[_ aa _ qaa _ aar _]3 , 
       2[_ rtaa _ aawrawwa _ agqaa _ aahgear _]4 
]3 

[_ 
       0[1, 2]2  _ 
       1[3, 4, 5, 6]4  _ 
       2[1, 2, 3, 4, 5, 6, 3, 4, 5, 6]10  _
       3[3, 4, 5, 6]4
 _]4

[
        1 : [_
              0[4, 4, 5, 6]4  _
              1[6, 6]2
        _]2 ,
        3 : [_
              0[1, 4, 5]3  _
              1[3, 5, 6]3
        _]2 ,
        5 : [_
              0[3, 4]2  _
              1[5, 6]2
        _]2
]3

[_ 1 _ 2 _ 3 _ 4 _ 5 _ 6 _]6

*/