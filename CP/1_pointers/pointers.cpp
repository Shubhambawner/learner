#include <iostream>
#include<stack>
using namespace std;
void addA(stack<string>*stak){
   //? *stak.push("A"); /* error: request for member 'push' in 'stak', which is of pointer type */
   //! here, stak is object of type: stack<string>*
   stak->push("A");
   cout<<stak<<'\n';
}
void sq(int*a){
    *a+=10;cout<<a<<" "<<*a<<'\n';
}
int main(){
    int a = 1;sq(&a);
    int*p = &a;sq(p);

    int b = 5+ *p;cout<<b<<endl;
    
    stack<string> stak ;
    stak.push("a");
    stak.push("b");
    addA(&stak);
    cout<<stak.top()<<endl;
    cout<<&stak.top()<<endl;
    // cout<<*stak.top(); /*no match for 'operator*'*/
    
}
/*output:       code:-
0x61fe90 11     sq(&a);
0x61fe90 21     sq(p);
26              cout<<b<<endl;
0x61fe68        cout<<stak<<'\n';
A               cout<<stak.top()<<endl;
0x2717b10       cout<<&stak.top()<<endl;
*/
/*
pointers are of 2 types: 
*pointer of basic data type ex. int string char bool 
    1] initialise: int*a = &someInt; 
        any variable name with '&' also rturns pointer,(pass by referance)
    2] refer as pointer: cout<<a; (prints 0x61fe90)
    3] refer adress variable: int b = 10 + *a; (de refrencing)
*pointer of derived object ex. stack, node,..
    1] initialise: stack<string>*Stk = &someStak; 
        any object name with '&' also rturns pointer,(pass by referance)
    2] refer as pointer: cout<<Stk; (prints 0x61fe90)
    3} de-referencing:
          *Stk is invalid, as Stk dosnt dosnt have any value, being an object it has references 
          to its parameters and methods, to access these, we use: 
          Stk->parameter; or Stk->method();
         
    
*/




















































