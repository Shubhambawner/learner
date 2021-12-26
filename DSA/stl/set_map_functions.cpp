//functions applicable to: 
// set, multiset, map, multimap
//(i.e balanced bst)

#include<bits/stdc++.h>
using namespace std;

void print(multiset<int> s){
    for(auto a:s){
        cout<<a<<"\t";
    }cout<<"\n";
}

int main(){
    set<int> s = {10,30,50,20,90,20,90,40};
    multiset<int> ms = {10,30,50,20,90,20,90,40};
    
    //     set is: 10 20 30 40 50 90 
    //multiset is: 10 20 20 30 40 50 90 90

    cout<<*s.lower_bound(20)<<"\n";//20
    cout<<*s.upper_bound(20)<<"\n";//30

    cout<<*s.lower_bound(22)<<"\n";//30
    cout<<*s.upper_bound(22)<<"\n";//30

    ms.erase(ms.find(20)); //erases one instance of element '20' from ms
    ms.erase(20); //erases all instances of element '20' from ms
    
    cout<<*ms.begin()<<"\n"; //smallest
    cout<<*ms.rbegin()<<"\n"; //largest
    
    /*cout<<*ms.cbegin()<<"\n"; //smallest
    cout<<*ms.crbegin()<<"\n"; //largest*/

    multiset<int> s1  {10,30,50,20,90,20,90,40,60};
    multiset<int> s2  {10,30,50,20,90,20,90,40};
    if(s1==s2) cout<<"sets equal\n";
    else cout<<"sets unequal\n";
    
    print(s1);print(s2);
    s1.insert(s2.begin(), s2.end());
    print(s1);
    cout<<s1<<"\n";
    /*  10      20      20      30      40      50      60      90      90
        10      20      20      30      40      50      90      90
        10      10      20      20      20      20      30      30      40      40      50      50      60      90      90      90      90
    */

}