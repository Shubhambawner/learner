#include<iostream>
using namespace std;

class animal{
    public:
        string color = "white";
        void printTrait(){
            cout<<color;
        };
};
class snake: public animal{
    public:
        string color = "black";
        string trait = "venom";
        void printTrait(){
            cout<<trait;
            cout<<color;
        }
};
int main(){
    animal*aa;
    aa = new snake();
    //cout<<aa->trait<<'\n';
    aa->printTrait(); //venomblack
}
/*

object slicing dose occur when abstract base class pointer asigned 
derived clas objects pointer

HOWEVER 

method overloading is not reversed, as they were'nt defined in first place!!
so not directly, but through these methods, 
the sliced off methods and parameters can be accessed !!

*/