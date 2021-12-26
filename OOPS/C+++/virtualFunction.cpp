#include<iostream>
using namespace std;
class A
{

public:
    virtual const char* virtualFunction(){
        return "A_virtual";
    }
    const char* fc(){
        return "A";
    }
};

class B : public A
{

public:
    virtual const char* virtualFunction(){
        return "B_virtual";
    }
    const char* fc(){
        return "B";
    }
    B(){

    }
};

int main(){
    //with pointers
    A *oa = new B();
    cout<< oa->fc() <<"\n"; //prints A
    cout<< oa->virtualFunction() <<"\n"; //prints B_virtual

    //with normal references
    A oar =  B(); 
    cout<< oar.fc() <<"\n"; //prints A
    cout<< oar.virtualFunction() <<"\n"; 
    //prints A_virtual 
    //i.e, DOWNSLICING happened to virtual function
    //so if its not pointer, virtual functions are meaningless to use, its just like normal functions, downslicing will happen
}

/////////////////////////////////////////////////////////////////////////
/**
 * virtual functuions iff defined in a class, can be used/executed, like normal functions
 * iff thiss class is inherited by other class, then 
 *      the object slicing can be bypassed for the virtual function iff:
 *      thiss class also re-defines the same function, and 
 *      pointer of base class is asigned object of the derived class, 
 *      baseClass*B = new derivedClass();
 *      B->someVirtualFunction();// executes function defined in derived class, not base class
 * 
 * this is an example of runtime polymorphism
 * 
 * */