#include <bits/stdc++.h>
using namespace std;

string padding = "\n";
void recurse(){
    padding+="|  ";
    cout<<padding<<"recurse enter";
}
void returnRecurse(){
    
    cout<<padding<<"recurse end";
    padding = padding.erase(padding.size()-3);
}
void returnRecurse(char a){
    
    cout<<padding<<"recurse end "<<a;
    padding = padding.erase(padding.size()-3);
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
void print2(T arr,  int i = 0)
{

    for (auto g = arr.begin(); g != arr.end(); ++g)
    {
        cout<<padding;
        cout << i++ << "---- \n";
        for (auto it = (*g).begin(); it != (*g).end(); ++it)
        {
            cout << *it << " \n";
        }
        cout << "|\n";
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
