#include"Myself.h"
class parent
{
private:
    int a = 10;
public:
    parent(){

    };
    virtual void print(){
        cout<<"parent class's function called,data value is: "<<a<<endl;
    }  
};
class child1 : public parent
{
private:
    int data = 20;
public:
    child1(){

    };
    void print(){
        cout<<"virtual function called called from child1 class, data value is: "<<data<<endl;
    } 
    
};
class child2 : public parent
{
private:
    int data = 30;
public:
    child2(){

    };
    void print(){
        cout<<"virtual function called called from child2 class, data value is: "<<data<<endl;
    } 
    
};
int main(){
    parent*A;
    //A1->print();// runtime error, as print function is virtual 

    child2 B;   
    A=&B;   
    A->print(); 

    child1 C;   
    A=&C;
    A->print();
}


