#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;


int main() {
    int t, k; cin>> t>> k;
    multimap<int, int> umm1;
    multimap<int, int> umm2;
    
    while(t--){
        int a,b;cin>> a>>b;
        umm1[a]=b;
        umm2[b]=a;
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
