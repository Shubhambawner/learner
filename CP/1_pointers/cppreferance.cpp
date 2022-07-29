#include "../../DSA/util/recursion_utilities.cpp"

int main(){
    //! "=" sign with variable names in cpp means hard copy of a created and is put in b
    map<int,vector<int>> a={{1,{2}}};
    map<int,vector<int>> b = a; b[0].push_back(3);
    // cout<<a<<endl<<b<<endl;
    /*
    output:
    [
            1 : [2]1   
    ]1
    [
            0 : [3]1 , 
            1 : [2]1
    ]2
    */
   //! this "&" maens the object in memory is refered to by c and a both now
   map<int,vector<int>>& c = a; c[0].push_back(3);
    // cout<<a;
    c=b;
    c[0].push_back(3);
    cout<<a<<endl<<b<<endl<<c;
    /*output
    [
        0 : [3]1 ,
        1 : [2]1
    ]2
    */
}
/*
!difference between referance and pointers:
1. referance has to be initialised at time of declearing, 
pointer can be decleared NULL, then asigned value 
2. referance once initialised, cant be changed, 
( dosnt throw error like const, but re-asigning makes no change as well)
 A pointer can be re-assigned. 
 This property is useful for the implementation of data structures like a linked list, a tree, etc.
3. pointer itself is a separate data type, it has its own memory space(which stores memorry address of something or NULL). 
referance shares the memory space (actual object) with each other

each object in cpp has:
memory space: where actual data lies
address: to that memory space: which can be said as pointer to it, this is what can be stored in differenty as a pointer to this object
referance, or name of that object as refered in code, while compiling this name is replaced by the address
*/
/*
while in JS:
memory space: where actual data lies
referance: name of that object as refered in code, Internaly associated with memory adress,
if its not a basic data type, asigning a referance to other object, both will refer to same memory spaece
to make deep copy we have to do JSON.parse(JSON.stringify()) or recursively...

*/