// CPP program to illustrate
// Implementation of top() function
#include <iostream>
#include <stack>
using namespace std;

//! do not use stack from stl, use vector/list as a stack instead!!
//!sisnce all the operations of stack i.e. push, pop, top are there in vector and list
//! Because :
    //! there is no way to add items in bulk
    //! there is no pointer to iterate
    //! there is no other way of getting other elements of stack untill they are brought on top
    //! if we try to access the top() when stack is empty, it BREAKS THE CODE, SEGMENTATION FAULT



void printStack(stack<int>*st);

int main()
{
  // stack initialisation
  stack<int>myStack;

  // stack push
  myStack.push(1);
  myStack.push(2);
  myStack.push(3);
  myStack.push(4);//! there is no way to add items in bulk

  // stack size
  cout << myStack.size()<<"\n";

  //stack top
  cout<<myStack.top()<<"\n";
    //! if we try to access the top() when stack is empty, it BREAKS THE CODE, SEGMENTATION FAULT
    stack<int>myStack2;
    //cout<<myStack2.top(); // <-- will break the code


  //stack pop
   myStack.pop();

  //iterate
  printStack(&myStack);
  printStack(&myStack);
  
  //swaping contents of two stacks
  printStack(&myStack);
  printStack(&myStack2);

  myStack2.swap(myStack);
  
  printStack(&myStack);
  printStack(&myStack2);
}

void printStack(stack<int>*st){
  //iterate over stack
  stack<int> temp;
  int L = st->size();
  for(int i=0; i<L;i++){//!there is no pointer to iterate
    cout<<st->top()<<"\t";

    //!there is no other way of getting other elements of stack untill they are brought on top
    temp.push(st->top());
    st->pop();
  }
  cout<<"\n";
  for (int i = 0; i < L; i++)
  {
    st->push(temp.top());
    temp.pop();
  }
}

/*
4
4
3       2       1
3       2       1
3       2       1
*/
