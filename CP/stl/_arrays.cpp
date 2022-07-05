#include<bits/stdc++.h>
using namespace std;
int main(){

    //! initializer list for creating array:
    int arr[7] = {}; // 0 0 0 0 0 0 0 
    int brr[7] = { 10 }; // 10 0 0 0 0 0 0 
    int brr[7]; // 0 0 0 0 16 0 4199705 
    //The array will be initialized to 0 if we provide the empty initializer list or just specify 0 in the initializer list.


    for(auto i: arr){
        cout<<i<<" ";
    }
}