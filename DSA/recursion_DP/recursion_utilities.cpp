#include <bits/stdc++.h>
using namespace std;

string padding = "\n";
void recurse(){
    padding+="|";
    cout<<padding<<"recurse enter";
}
void returnRecurse(){
    string temp = "\n";
    for (int i = 0; i < padding.size()-2; i++)
    {
        temp+="|";
    }
    cout<<padding<<"recurse exit ";
    padding = temp;
}

// utility funnction to print a 2d iterative container vector<vector<int>> list<vector<int>> ...
template <class T>
void print(T arr,  int i = 0)
{

    for (auto g = arr.begin(); g != arr.end(); ++g)
    {
        cout<<padding;
        cout << i++ << "---- ";
        for (auto it = (*g).begin(); it != (*g).end(); ++it)
        {
            cout << *it << " ";
        }
        cout << '|';
    }
}
template <class T>
void srint(T arr,  int i = 0)
{
    cout<<padding;
    for (auto g = arr.begin(); g != arr.end(); ++g)
    {

        
            cout << *g << " ";
        
    }
        cout << "   ";
}
