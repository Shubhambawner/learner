#include<iostream>
using namespace std;
int main(){
    int a[10]={0};
    int *b[10]={0};
    b[0] = &a[0];
    cout<<b<<'\t'<< &a <<'\t';  //if we do: b=&a; it will give incompatible types in assignment of 'int (*)[10]' to 'int* [10]'
    //! although the array's pointer is nothing but pointer to 1st element, they are different by the defination, and cant be equated/asigned to eacn other
    *b[0] = 100;
    cout<<a[0];
} 
