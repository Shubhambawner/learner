#include<iostream>
using namespace std;
class nitrr
{
private:
    int r;
public:
    nitrr(int r);
    int Print(){
        return r;
    };

    nitrr operator +(nitrr &iota);
    
};

nitrr::nitrr(int r)
{
    this->r=r;
    
}


nitrr nitrr:: operator+(nitrr &iota){
    return this->r+iota.r;
}

int main(){
    int a,b;
    cout<<"enter 2 numbers: "<<endl;
    cin>>a>>b;
    nitrr it(a);nitrr cse(b);
    nitrr d = (it+cse);

    cout<<"the sum is "<< d.Print(); 
}