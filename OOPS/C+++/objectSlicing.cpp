#include <iostream>    
using namespace std;    
class Animal {                                          //  base class declaration.  
    public:    
    string color = "Black";      
};   

class Pet {
    public:
    string color = "pink";
};
class Dog: public Animal,Pet                       // inheriting Animal class.  
{      
 public:    
    string color = "Grey"; //if not over-riden, will throw an error, as animl & pet both define it!!     
};    
int main(void) {    
     Animal d= Dog();      
    cout<<d.color<<'\n'; //Black  

    Animal e;
    Dog foo;
    e = foo;//downslicing
    cout<<e.color<<'\n'; //Black

    Animal *ep;
    Dog *foop = new Dog();
    ep = foop;
    cout<<ep->color <<'\n'; //Black


}    

/*
OBJECT SLICING::
-------------------------------------------------------------------------------------
how can we asign foo to e ?(e is animal f is dog(which is animal!))
derived class objects can be asigned to base class objects, 
-------------------------------------------------------------------------------------
here, the extra atributes of derived class are sliced off from the object, 
and all the over-riding of methods and parameters is reversed to normal!!!
--------------------------------------------------------------------------------------
in other words, derived class object is converted 
to base class obj and asigned to base class object
------------------------------------------------------------------------------------
so, here f as an animal is asigned.
------------------------------------------------------------------------------------
same with pointers
if base class pointer assigned derived class's object, 
it cant access the extra parameters! 
*/

/*

so, untill runtime the properties of object e remain undecided, as compiler 
dosnt himself make any objects and asign one to other...
(it dosen't execute, just convert code to machine readable)

*/





















































































































/*
maybee this happens at run time, machine takes data from some memory location
(of object foo's methods and parameters(that is given by compiler)) and dumps to some memoy location
(of object e's methods and parameters(that too is given to it by compiler))
OR 
maybee compiler just provides the referance adresses,
like for some function to be excuted at some line, then
the relative adress of place where it's defination is placed after compiling
and orders to copy all parameters to be passed into method to that location are 
placed as compiled code for that line 
*/