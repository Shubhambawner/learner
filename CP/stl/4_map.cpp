#include <map>
#include <unordered_map>
#include<iostream>
using namespace std;

template<class T, class R>
void print(map<T,R> m){

  //Iterator pointer loop:
  for (auto i = m.begin() ; i != m.end() ; i++) //here only i++ works
  {
    cout<<i->first<<"->"<<i->second<<",\t";
  }
  cout<<"\n";
}


int main()
{

	//1. Initialize container

	map<int, int> mp;
	map<int, int> m2 = { {1,2},{2,3},{5,6},{3,5}};
	map<int, int> m3 = m2;
	
	//2 .Insertion::

	mp.insert({ 2, 30 });
	mp.insert({ 1, 40 });
	mp.insert({ 3, 20 });
	mp.insert({ 4, 50 });
  print<int,int>(mp);

  m2[500] = 4; //it searches in map, iff not found, inserts the key 500, and modifies its value to 4
  m2[300] = 5;
  m2[200] = 42;
  m2[100] = 47;
  print<int,int>(m2);

  m3[23]; //actually it searches in map, iff not found, inserts the key 23, with value 0
  m3[33]; //* inserts the key 33, with value 0
  m3[25]; //* inserts the key 25, with value 0
  m3[46]; //* inserts the key 46, with value 0
  print<int,int>(m3);

  //3. deletion
  int a = m3.erase(23);
  int b = m3.erase(300);
  cout<<a<<" "<<b<<"\n";
  print<int,int>(m3);

	//4. find key in map to access it's value 	
 
  map<int,int>::iterator i = m3.find(33);
  if(i == m3.end() || m3.count(33)){
      cout<<"key Not found!";
  }else{
    cout<<i->first<<"->"<<i->second<<",\n";
  }


  //5. others:
  cout<< m3.size()<< "\t"<< m3.max_size()<< "\t" << m3.at(2) << "\n";


  // if not found in map, a default value is asigned, i.e 0 for int/float/double ,'' for char/str, false for bool
  map<int, int> aa; cout<<aa[23]<<"\n";
  map<int, float> aa2; cout<<aa2[23]<<"\n";
  map<int, string> aa3; cout<<aa3[23]<<"\n";
  map<int, double> aa4; cout<<aa4[23]<<"\n";
  map<int, char> aa5; cout<<aa5[23]<<"\n";
  map<int, bool> aa6; if(!aa6[23]) cout<<"tt\n";
  //map<int, vector<int>> aa4; cout<<aa4[23][0]<<"\n";








//map types:






  //balanced bst implementations (sorted data, log(n) time):
  map<int, int> m = {{7,5},{5,6},{1,3}, {1,4}, {1,5},{2,4}};
  cout<<"printing map:\n";
  for (auto i : m)
  {
    cout<<i.first<<"->"<<i.second<<"\t";
  }cout<<"\n";
  
  multimap<int, int> mm = {{7,5},{5,6},{1,3}, {1,4}, {1,5},{2,4}};
  cout<<"printing multimap:\n";
  for (auto i : mm)
  {
    cout<<i.first<<"->"<<i.second<<"\t";
  }cout<<"\n";
  

  //hash table implementations(unsorted data, constant time):

  unordered_map<int, int> um = {{7,5},{5,6},{1,3}, {1,4}, {1,5},{2,4}};
  cout<<"printing un-ordered map:\n";
  for (auto i : um)
  {
    cout<<i.first<<"->"<<i.second<<"\t";
  }cout<<"\n";
  
  unordered_multimap<int, int> umm = {{7,5},{5,6},{1,3}, {1,4}, {1,5},{2,4}};
  cout<<"printing un-ordered multimap:\n";
  for (auto i : umm)
  {
    cout<<i.first<<"->"<<i.second<<"\t";
  }cout<<"\n";
  
  
  return 0;
}

/*
for map: 

insertion
log(n)

deletion


search: 
log(n)

traversal: 
n

*/

