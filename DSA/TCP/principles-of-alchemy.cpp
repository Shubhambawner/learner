#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t; cin>>t;
    while(t--){
        int n; cin>> n;
        int h = n - floor(sqrt(n));
        if(h%2==0){
            cout<<"Edward\n";
        }else{
            cout<<"Alphonse\n";
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
