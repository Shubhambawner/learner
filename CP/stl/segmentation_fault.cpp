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



    //! Division by int/long variable that is zero
    // divisionByZero();
    
    //! Mod operation(%) by int/long variable that is zero
    // modByZero();

    //! De-referencing a NULL pointer
    // nullPointerAccess();

    //! 2 accessing top() of empty stack in stl
    // emptyStackTop();

    // //! 1 Dereferencing uninitialized pointer/ accessing uninitialised variable
    // uninitializedAccess();
    // picks garbage values: executes successfully but reasults are un-desired !

    // setErase();

    list<int> l;
    l.pop_back();
    // _w(l);

    queue<int>s;
    // s.pop();
    _w(isQueueStack(getType(s)));
    cout<<s;
}