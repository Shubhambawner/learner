#include<iostream>
using namespace std;
int main(){
    int a[10]={0};
    int *b[10]={0};
    b = &a;
    *b[0] = 100;
    cout<<a[0];
} 