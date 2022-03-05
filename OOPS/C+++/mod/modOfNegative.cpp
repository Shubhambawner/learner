//mod operator on -ve numbers

#include<iostream>
using namespace std;
int main(){
    int a = 5%6;cout<<a<<'\n';
    int a = (0-5)%6;cout<<a<<'\n';
    return 0;
}
/*
o/p is:
5
-5
-----------------------------
SO, IT MEANS:
(-a)%b = -(a%b)
-----------------------------
and, if +ve remainder is required, 
we do THIS:
if(a<0){ a = a%b + b }
NOT THIS: 
if(a<0){ a = -(a%b)  }
*/   
