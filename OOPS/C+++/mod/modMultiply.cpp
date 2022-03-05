//to print product of a, b, c modulo 10:

#include<iostream>
using namespace std;
int main()
{
    int a = 10005;
    int b = 20005;
    int c = 30005;
    //cout<<(a*b*c)%10; --> error: out of bounds, as a*b*c is an int, which is > 2*10^9; 
    cout<<(a%10)*(b%10)*(c%10)<<endl;//---> wrong ans,output is > 10, but %10 cant be >10
    cout<<((a%10)*(b%10)*(c%10))%10<<endl;
} 
/*
o/p:
125
5
TTHIS MEANS:
    (a * b)%m = ((a%m)*(b%m))%m
    while adding or multiplying in mod, the values get bigger than dividend!!! 
*/