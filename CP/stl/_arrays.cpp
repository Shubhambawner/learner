#include<bits/stdc++.h>
using namespace std;
int main(){

    //! initializer list for creating array:
    int crr[7] = {}; // 0 0 0 0 0 0 0 
    int brr[7] = { 10 }; // 10 0 0 0 0 0 0 
    int grr[7]; // 0 0 0 0 16 0 4199705 
    //The array will be initialized to 0 if we provide the empty initializer list or just specify 0 in the initializer list.

    //int arr[2][4];
    /*
    16 0 4199705 0 
    1 0 29 0 
    */
   int arr[2][4]={{0}};
   /*
    0 0 0 0 
    0 0 0 0
   */

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    
}