// Optimized implementation of Bubble sort
#include <iostream>
using namespace std;
 /* Function to print an array */
void printArray(int A[], int size)
{
    cout<<"{";
	for (auto i = 0; i < size; i++){
		cout << A[i] ;
        if(i!=size-1){
            cout<< " ,";
        }}
    cout<<"}\n";
}
   
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
         cout<<"for index: "<<j<<" arr[j] = "<<arr[j]<<" arr[j+1] = "<<arr[j+1]<< " ";
        if (arr[j] > arr[j+1])
        {
            cout<<"swapping indices "<<j<<" and "<<j+1<<" we get: ";
           swap(&arr[j], &arr[j+1]);
           printArray(arr, n);
           swapped = true;
        }else{
            cout<<"no need to swap, as "<< arr[j]<<" <= "<< arr[j+1]<<"\n";
        }
     }
  
     // IF no two elements were swapped by inner loop, then break
     if (swapped == false)
        break;
   }
}
  

// Driver program to test above functions
int main()
{
    int arr[] = {0, 17, 12, 0, 13 ,10, 7 , 0, 11, 8};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("initial array: ");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}