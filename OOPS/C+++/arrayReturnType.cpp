/*
we return the pointers in c++
functions with pointer return type can take array, modify it, 
but can't return pointer of type array,
they need to return pointer, so the pointer to 1st element of array is returned.


*/

#include <iostream>
using namespace std;
 
void printArray(int arr[], int size){
    int i=0;
    while(size>i){
        cout<<arr[i]<<",\t";i++;
    }
    cout<<" done"<<size<<"\n";
}

int* Swap(int arr[], int n){
    arr[n] = (arr[n]+arr[n+1]);
    arr[n+1] = arr[n] - arr[n+1];
    arr[n] = arr[n] - arr[n+1];
    
    return arr;
}
int main()
{
    int arr[] = {1,2,3,4,5,6};

    cout<<arr<<'\t'<<*arr<<'\t'<<&arr<<'\n';
    // 0x61fea4        1       0x61fea4
    cout<<arr[0]<<'\t'<<&arr[0]<<'\n';
    //1       0x61fea4

    /*
    note that &arr and &arr[0] are same, *arr and arr[0] too are same
    */

    printArray(arr,6);
    int* ptr = Swap(arr,3);
    printArray(arr,6);

    int*a = arr;
    cout<<a[0]<<'\t'<<a[1]<<'\t'<<a[2]<<'\t'<<a[3]<<'\n';
    //1       2       3       5
    /*
    aray name can be converted to pointer!!, works fine!!
    */
   cout<<sizeof(arr)<<'\t'<<sizeof(a)<<'\t'<<sizeof(*a)<<'\n';

    delete[] ptr; //allocated memory must be deleted
    return 0;
}