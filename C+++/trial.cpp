#include<iostream>
#include<cstdlib>
using namespace std;



int main(){
    cout<<"hello"<<'\n';
    char comand[] = 
 "cd \"c:\\Users\\Shubham\\mySpacs\\codeVS.code-workspace\\my c++\\C+++\\\" ; if ($?) { g++ stack.cpp -o stack } ; if ($?) { .\\stack }";   
    string i1,i2,i3;
    system(".\\stack ; 1 2 3");
    cin>>i1>>i2>>i3;
    cout<<i1<<'\n'<<i2<<'\n'<<i3<<'\n';
  //system("3+4");
}
