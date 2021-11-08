#include<iostream>
using namespace std;




class nitrr
{
private:
    int data;
public:
    nitrr(int a);
    friend int multiply(nitrr one, nitrr two);
    ~nitrr();
};

nitrr::nitrr(int a)
{
    this->data = a;
}

nitrr::~nitrr()
{
}

int multiply(nitrr a, nitrr b){
    return a.data * b.data;
}

int main(){
    int a,b;
    cout<<"enter 2 numbers: "<<endl;
    cin>>a>>b;
    nitrr it(a);nitrr cse(b);
    cout<<"the product is "<<multiply(it,cse); 
}