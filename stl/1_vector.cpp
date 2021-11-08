#include<iostream>
#include<vector>
using namespace std;

template<class T>
void print(vector<T> a){

    //iterator pointer:
    for (auto i = a.begin(); i < a.end(); i++)
    {
        cout<<a[i-a.begin()]<<"|";
        cout<<*(i)<<"\t";
    }
    
    cout<<"\n";
}

void f(char*a, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<", ";
    }
    cout<<"-- vector as array!\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //initialisers:
    vector<char> a(10, 'a');
    vector<char> b = {'a','g','a'};
    vector<char> c = b;
    print<int>({1,2,3,4});

    //methods:

    a.pop_back();
    a.push_back('f');
    

    a.reserve(20);
    cout<<a.size()<<"\t"<<a.capacity()<<"\n";

    
    a.insert(a.begin()+1, 'z'); print(a);
    a.erase(a.begin()+1); print(a);
    
    //others
    f(&a[0], a.size());
}