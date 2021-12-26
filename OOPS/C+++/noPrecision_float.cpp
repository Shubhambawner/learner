#include<iostream>
using namespace std;
int main(){
    double a = 145e200, b = 145e1;
    //hovering cursor over literal '145e200' we get it's actual value is 1.449999999966e202, not exact 145x10^200
    cout<<a+b;
    if(a+b==145e200+1451){
        cout<<"\na+b==145e200+1451";
    }
    if(a+b==145e200+1450){
        cout<<"\na+b==145e200+1450\n";
    }
    //here we know that a+b=145x10^200 + 1450, but boolean
}