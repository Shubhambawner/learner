//print name 5 times

#include <bits/stdc++.h>
using namespace std;

int c = 5;
void f1(string name)
{
    if (c == 0)
    {
        c = 5;
        return;
    }
    cout << name << "\n";
    c--;
    f1(name);
}

int i = 1;
void f2(int n)
{
    if (i <= n)
    {
        cout << i << "\n";
        i++;
        f2(n);
    }else{
        i=1;
        return;
    }
}

void f3(int n){
    if(n==0) return;
    cout<<n<<"\n";
    f3(--n); //here we cant put post operator
}

//!backtraking style in recursion: we place working blok after the recursive call

void f4(int n){ 
    if(n==0) return;
    f3(n-1);
    cout<<n<<"\n";
}
int main()
{
    //f1("TUF");
    //f2(7);
    //f3(7);
    f4(7);
}