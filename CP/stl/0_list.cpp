//* https://www.geeksforgeeks.org/list-cpp-stl/

#include <iostream>
#include <list>
#include <forward_list>
#include <iterator>
using namespace std;

void showlist(list <int> g)
{
	list <int> :: iterator it;
	for(it = g.begin(); it != g.end(); ++it)
		cout << *it<< " " ;
	cout << '\n';
}
void showlist(forward_list <int> g)
{
	forward_list <int> :: iterator it;
	for(it = g.begin(); it != g.end(); ++it)
		cout << *it<< " " ;
	cout << '\n';
}

int main()
{
    //creation
	list<int>  l = {1,2,3,4,5,6,7,8,9} ;
	list<int>  l2(l);
	list<int>  l3 = l;

    	
    //stack/queue/dequeue----------------------------------------

    l.push_back(30); //1,2,3,4,5,6,7,8,9,30
    l.pop_back(); //1,2,3,4,5,6,7,8,9
    l.push_front(30);//30, 1,2,3,4,5,6,7,8,9
    l.pop_front();//1,2,3,4,5,6,7,8,9

    //accessing elements:-------------------------------------------
    //cout<<l[0]<<"---\n"; //!not possible in list!!
    //!only way: pointers:
    
    //pointer iterator operations---------------------------------
    auto n =  l.begin();//*n = 1
    n++;//*n=2
    n--;//*n=1
    //move iterator n, 2 times
    advance(n,2);//*n = 3

    //-------------------------------------------------------------
    //insertion

    //1.insertion before ierator 'n', i.e b4 element 3 of l

    l.insert(n,500);//1 2 500 3 4 5 6 7 8 9 
    l.insert(n,2,200);//1 2 500 200 200 3 4 5 6 7 8 9  

    int arr[4]={10,20,30,40};
    l.insert(n,&arr[0],&arr[4]); //1 2 500 200 200 10 20 30 40 3 4 5 6 7 8 9 
    //till arr[4], not inclusive of it

    //--------------------------------------------------------
    //removal of elements: 
    
    //1.pointed by iterator n:
    n = l.erase(n);//*n = 3, so 3 will get erased, *n=4 now
    //note, modifying n this way is mandatory, else segmentation fault appears

    // is list empty?
    cout<<l.empty(); // 1 if not, 0 if is empty

    //2.from node a to b, b exclusive

    auto a = l.begin();
    l.erase(a,n);//4 5 6 7 8 9 erased everything from a to n
   
    //----------------------------------------------

    l.reverse(); // 9 8 7 6 5 4
   
    l.sort(); //4 5 6 7 8 9

    //--------------------------------------------------
    // forward_list : singly linked list

    forward_list<int> fl;
    fl.assign({1,2,3,4,5,6})  ;
    auto p = fl.begin();//*a=1
    advance(p,3);//*a=4

    fl.erase_after(p);

    fl.sort();

    fl.reverse();

    showlist(fl);
}
