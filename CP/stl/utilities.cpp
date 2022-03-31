#include<bits/stdc++.h>
using namespace std;
template<class T>
void print(T*start, T*end){
    cout<<"printing sequence : ";
    for(T*i=start; i!=end;i++){ 
        cout<<*i <<" ";
    }
    cout<<"\n";
}


int main(){
    int a[10] = {1,2,3,4,5,6,7,8,9,0};
    print(a,a+10);

    list<int> b = {1,2,3,4};
    cout<<*b.begin();
   // print(b.begin(), b.end());
}