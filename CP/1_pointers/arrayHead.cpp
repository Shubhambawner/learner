/*
we return the pointers in c++
functions with pointer return type can take array, modify it, 
but can't return pointer of type array,
they need to return pointer, so the pointer to 1st element of array is returned.
*/
//! array head pointer of array of size n is:
//! of type int[n]*
//! value same to first element's pointer, can also be de referenced to get thi 1st element

#include <iostream>
using namespace std;
 
void printArray(int arr[], int size);
int* SwapN(int arr[], int n);

int main()
{
    int arr[] = {1,2,3,4,5,6};

    cout<<arr<<'\t'<<&arr[0]<<'\n';     //0x61fea4       0x61fea4

    printArray(arr,6);
    int* ptr = SwapN(arr,3);
    printArray(ptr,6);

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

void printArray(int arr[], int size){
    int i=0;
    while(size>i){
        cout<<arr[i]<<",\t";i++;
    }
    cout<<" done"<<size<<"\n";
}
int* SwapN(int arr[], int n){ //* swap nth and (n+1)th elements in array 
    arr[n] = (arr[n]+arr[n+1]);
    arr[n+1] = arr[n] - arr[n+1];
    arr[n] = arr[n] - arr[n+1];
    
    return arr;
}