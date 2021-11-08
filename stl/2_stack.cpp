// CPP program to illustrate
// Implementation of top() function
#include <iostream>
#include <stack>
using namespace std;

int main()
{
  int aa,ba,ca;
  cin>>aa>>ba>>ca;
	stack<int> mystack;
	mystack.push(aa);
	mystack.push(ba);
	mystack.push(ca);

	// Stack top
  cout << --mystack.top()<<endl;
  int*ptr = &mystack.top();
  cout<<ptr-2<<endl;
  
  
  stack<string> data;
  data.push("1efsdf");
  data.push("2sdf");
  data.push("3sdf");
  data.push("4sdf");
  data.push("5sdf");
  
  string*aptr = &data.top();
  string a =*aptr;
  int i = 0;
  while (i++<data.size())
  {
     string t = *(aptr-i);
      if(t!="")
      {a=t+"."+a;
      }    
  }
  cout<<a;
	return 0;
}
