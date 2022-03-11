//mod operator on -ve numbers

#include<iostream>
using namespace std;


int main(){
    int a = 5%6;cout<<a<<'\n'; // 5
    int a1 = (0-5)%6;cout<<a1<<'\n'; //-5
    
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
