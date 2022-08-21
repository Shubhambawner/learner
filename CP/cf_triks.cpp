#include<bits/stdc++.h>
using namespace std;
int main(){
    for(int n=1;n<50;n++){
    cout<<(__builtin_ffs(n))<<" "<<(log2(n)+1)<<endl;
    }
}