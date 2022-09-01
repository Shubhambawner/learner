#include <bits/stdc++.h>
#include "../../DSA/util/recursion_utilities.cpp"
using namespace std;
//* Core Dump/Segmentation fault is a specific kind of error 
//* caused by accessing memory that “does not belong to you.” 

//? reasult: Abnormal termination of program.

//reasons:
//! 1 Dereferencing uninitialized pointer/ accessing uninitialised variable
class node0{
    public:
    int data;
    node0*next;
    node0(){}
};
void uninitializedAccess(string str = __builtin_FUNCTION()){
    _e();
        node0*h = new node0();
    node0 *n = h->next;
    cout<<n<<"\n";
    int g = h->data;
    cout<<g<<"\nexecuted successfully! \n";
}

//! 2 accessing top() of empty stack in stl
void emptyStackTop(){
    _e();
        stack<int> s;
    s.push(3);
    s.push(4);
    for(int i=3;i>=1;i++){ cout<<"\n"<<s.top(); s.pop();}
    cout<<"\nexecuted successfully! \n";
}

//! 3 De-referencing a NULL pointer 
class node{
    public:
    int data=0;
    node*next=NULL;
    node(int a){this->data=a;}
};
void nullPointerAccess(){
    _e();
        node*head=new node(5);
    int n = head->next->data;
    cout<<n<<"\nexecuted successfully! \n";
}

//! 4 Division by int/long variable that is zero
void divisionByZero(){
    _e();
        int a=0;
    int b = 6/a;
    cout<<"\nexecuted successfully! \n"<<a;
}

//! 5 Mod operation(%) by int/long variable that is zero
void modByZero(){
    _e();
        int a=0;
    int b = 6%a;
    cout<<"\nexecuted successfully! \n"<<a;
}
//! 6 removing element from set that is not inserted into it, i.e. set.erase(set.end())
void setErase(){
    _e();
    set<int> t;
    t.insert(4);
    t.erase(t.find(55));
    _w("executed successfully! \n");
}

//! 7 accessing top of empty stack, note that popping from empty stack wont be any problem!
void stackTop(){
    _e();
    stack<int>ss;
    ss.pop();
    ss.pop();
    _e();
    _w(ss.top());
    _w("executed successfully! \n");
}

//! 8 accessing back of the empty ueue, note that popping from empty quwue wont be any problem!
void queueBack(){
    _e();
    queue<int>s;
    s.pop();
    s.pop();
    _e();
    _w(s.back());
    _w("executed successfully! \n");
}

//! 
//! 
//! 
//! 
//! 
//! 
//! 
//! 
//! 
//! 
//! 

int main(){

    // divisionByZero();
    
    // modByZero();

    // nullPointerAccess();

    // emptyStackTop();

    // uninitializedAccess();
    // picks garbage values: executes successfully but reasults are un-desired !

    // setErase();

    // stackTop();

    // queueBack();

}