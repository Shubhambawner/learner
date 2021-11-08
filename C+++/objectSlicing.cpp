#include<iostream>
using namespace std;

class A
{
    public:
    int a_var;
    A(int a) : a_var(a) {}
    
};

class B : public A
{
    public:
    int b_var;
    B(int a, int b) : A(a), b_var(b) {}
    
};

B &getB()
{
    static B b(1, 2);
    return b;
}

int main()
{
    // Normal assignment by value to a
    A a(3);
    //a.a_var == 3
    a = getB();
    // a.a_var == 1, b.b_var not copied to a

    B b2(3, 4);
    //b2.a_var == 3 ,b2.b_var == 4
    A &a2 = b2;
    // Partial assignment by value through reference to b2
    a2 = getB();
    // b2.a_var == 1, b2.b_var == 4!
    cout<<a.a_var<<a.b_var<<a2.a_var<<a2.b_var<<b2.a_var<<b2.a_var<<endl;
    return 0;
}

//(explained in runtimePoly.cpp)