
/*

set is bst
unorderd set is hash table

multiset is
unordered multiset is

*/



#include<set> //set & multi-set
#include<unordered_set> //unorderd set & unorderd multi-set
#include <iostream>
using namespace std;
int main(){





    //*********************************************************************************
    //simple set(balanced bst)
    //use when SORTED order needed, and check is element inserted previously or not

    //initialise
    set<int> s1 = {10,2,30,55,-1,0,3,3,3}; //3 will be inserted once only -- log(n!)
    set<int> s2;
    set<int> s3 = s1;

    //insert element -- log(r), r: size at time of inertion
    s1.insert(5);
    s1.insert(5);

    
    //iterate via auto --??
    for (auto i : s1 ) //i is int, not iterator!
    {
        cout<<i <<"\t";
    }cout<<"\n";

    //erase element -- log(r), r: size at time of inertion
    s1.erase(s1.find(2));

    //iterate via pointer --??
    set<int>::iterator i1 = s1.begin();
    for(i1;i1!= s1.end(); i1++){
        cout<<*i1 <<"\t";
    }cout<<"\n";

    
    //chek is it there? -- log(n)
    //way 1:
    cout<<" is five there? \n"; //count gives 0 for false, 1 for true
    if(s1.count(5)) 
    cout<< "yes\n"; else cout << "no\n";

    //way 2:
    cout<<" is 30 there? ";
    if(s1.find(302) != s1.end())  //find gives pointer to location of element in set, iff not found gives past end pointer
    cout<< "yes\n"; else cout << "no\n";


    //size
    cout<<"Size: "<< s1.size() <<"\n";

/*

-1      0       2       3       5       10      30      55
-1      0       3       5       10      30      55
 is five there? 
yes
 is 30 there? no
Size: 7
*/








    //***********************************************************************
    //multiset (?) 
    //use when SORTED order needed, & also get number of times element has been inserted

    //initialise
    multiset<int> ms1 = {10,2,30,55,-1,0,3,3,3}; //3 will be inserted thrice -- log(n!)
    multiset<int> ms2;
    multiset<int> ms3 = ms1;

    //insert element -- log(r), r: size at time of inertion
    ms1.insert(5);
    ms1.insert(5);

    
    
    //iterate via auto --??
    for (auto i :ms1 ) //i is int, not iterator!
    {
        cout<<i <<"\t";
    }cout<<"\n";

    //erase element -- log(r), r: size at time of inertion
    ms1.erase(ms1.find(2));

    //iterate via pointer --??
    multiset<int>::iterator i3 = ms1.begin();
    for(i3;i3!= ms1.end(); i3++){
        cout<<*i3 <<"\t";
    }cout<<"\n";

    //chek is it there? -- log(n)
    //way 1:
    cout<<" is five there? \n"; //count gives 0 for false, 1 for true
    if(ms1.count(5)) 
    cout<< "yes\n"; else cout << "no\n";

    
    //way 2:
    cout<<" is 30 there? ";
    if(ms1.find(302) != ms1.end())  //find gives pointer to location of element in set, iff not found gives past end pointer
    cout<< "yes\n"; else cout << "no\n";

    
    //size
    cout<<"\nSize: "<< ms1.size() <<"\n";

    /*
    -1      0       2       3       3       3       5       5       10      30      55
    -1      0       3       3       3       5       5       10      30      55        
    is five there? 
    yes
    is 30 there? no

    Size: 10
    */














    //***********************************************************************
    //unordered_set (hash table) 
    //use when sorted order not needed, but check is element there or not

    //initialise
    unordered_set<int> us1 = {10,2,30,55,-1,0,3,3,3}; //3 will be inserted once only -- o(n)
    unordered_set<int> us2;
    unordered_set<int> us3 = us1;

    //insert element -- log(r), r: size at time of inertion
    us1.insert(5);
    us1.insert(5);

    
    
    //iterate via auto -- O(n)
    for (auto i : us1 ) //i is int, not iterator!
    {
        cout<<i <<"\t";
    }cout<<"\n";

    //erase element -- O(1)
    us1.erase(us1.find(2));

    //iterate via pointer -- O(n)
    unordered_set<int>::iterator i2 = us1.begin();
    for(i2;i2!= us1.end(); i2++){
        cout<<*i2 <<"\t";
    }cout<<"\n";

    //chek is it there? -- O(1)
    //way 1:
    cout<<" is five there? \n"; //count gives 0 for false, 1 for true
    if(us1.count(5)) 
    cout<< "yes\n"; else cout << "no\n";

    
    //way 2:
    cout<<" is 30 there? ";
    if(us1.find(302) != us1.end())  //find gives pointer to location of element in set, iff not found gives past end pointer
    cout<< "yes\n"; else cout << "no\n";

    
    //size
    cout<<"\nSize: "<< us1.size() <<"\n";

    /*
    5       3       -1      0       55      30      2       10
    5       3       -1      0       55      30      10
    is five there? 
    yes
    is 30 there? no

    Size: 7
    */













    //***********************************************************************
    //unordered_multiset (hash table) 
    //use when sorted order not needed, but check number of times element has been inserted

    //initialise
    unordered_multiset<int> ums1 = {10,2,30,55,-1,0,3,3,3}; //3 will be inserted once only -- o(n)
    unordered_multiset<int> ums2;
    unordered_multiset<int> ums3 = ums1;

    //insert element -- log(r), r: size at time of inertion
    ums1.insert(5);
    ums1.insert(5);

    
    
    //iterate via auto -- O(n)
    for (auto i : ums1 ) //i is int, not iterator!
    {
        cout<<i <<"\t";
    }cout<<"\n";

    //erase element -- O(1)
    ums1.erase(ums1.find(2));

    //iterate via pointer -- O(n)
    unordered_set<int>::iterator i4 = ums1.begin();
    for(i4;i4!= ums1.end(); i4++){
        cout<<*i4 <<"\t";
    }cout<<"\n";

    //chek is it there? -- O(1)
    //way 1:
    cout<<" is five there? \n"; //count gives 0 for false, 1 for true
    if(ums1.count(5)) 
    cout<< "yes\n"; else cout << "no\n";

    
    //way 2:
    cout<<" is 30 there? ";
    if(ums1.find(302) != ums1.end())  //find gives pointer to location of element in set, iff not found gives past end pointer
    cout<< "yes\n"; else cout << "no\n";

    
    //size
    cout<<"\nSize: "<< ums1.size() <<"\n";

    /*
    10      2       30      55      0       -1      3       3       3       5       5 
    10      30      55      0       -1      3       3       3       5       5
    is five there? 
    yes
    is 30 there? no

    Size: 10
    */


}


