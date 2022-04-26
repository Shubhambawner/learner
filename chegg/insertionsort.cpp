#include<iostream>
using namespace std;

void display(int A[], int size)
{
    cout<<"{";
	for (auto i = 0; i < size; i++){
		cout << A[i] ;
        if(i!=size-1){
            cout<< " ,";
        }}
    cout<<"}\n";
}
void insertionSort(int *array, int size) {
   int key, j;
   for(int i = 1; i<size; i++) {
      key = array[i];//take value
      j = i;
      cout<<"for index = "<<i<<", arr[index] = "<<array[i]<<" \nserching it's correct posotion from starting, \n";
        
      while(j > 0 && array[j-1]>key) {
         array[j] = array[j-1];
         j--;
      }
        array[j] = key;   //insert in right place
      cout<<"correct posotion found at index: "<<j<<" so, shifting all elements in between to right, and inserting  "<< key<< " at "<<j<<" we get: ";
      display(array, size);
   }
}
int main() {
   int arr[] = {0, 17, 12, 0, 13 ,10, 7 , 0, 11, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Array before Sorting: ";
    display(arr, n);
    insertionSort(arr, n);
    cout << "Array after Sorting: ";
    display(arr, n);
   
}