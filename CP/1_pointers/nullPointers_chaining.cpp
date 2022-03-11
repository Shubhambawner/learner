//! if a pointer of any object type is NULL ,and we try to access it's parameters, we get SEGMENTATION Fault
//* to solve this, whenever we are accessing any pointer's parameters, we put a check:
//* tnode = (tnode)? tnode->next : NULL ; (i.e. if tnode is null, we will not get seg.fault)
//? Chaining with && logic
//* program wont look for further parameters of && if one is NULL/false
//ex.: if(a3 && a3->next) cout<<"h\n"; if a3 is null this wont throw error, as a3->next is not accessed !



#include<iostream>
using namespace std;
struct node{
    int val; node*next;
    node(){

    }
};
int main(){
    node*a3 = NULL;
    if(a3 && a3->next && a3->next->next) cout<<"h\n";
    cout<<"&& works\n"; //* && works
    if(a3 || a3->next) cout<<"h\n";
    cout<<"|| works\n"; //*dosnt work
}