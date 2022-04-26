#include <iostream>
using namespace std;
void swapping(int &a, int &b)
{ // swap the content of a and b
    int temp;
    temp = a;
    a = b;
    b = temp;
}

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

void selectionSort(int *array, int size)
{
    int i, j, imin;
    for (i = 0; i < size - 1; i++)
    {
        cout<<"for index = "<<i<<" \nserching minimum from here till the end, \n";
        imin = i; // get index of minimum data
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[imin])
                imin = j;
        }
        cout<<"minimum is found at index: "<<imin<<" so, swaping indices "<< i<< " and "<<imin<<" we get: ";
        // placing in correct position
        swap(array[i], array[imin]);
        display(array,size);
    }
}
int main()
{
    int arr[] = {0, 17, 12, 0, 13 ,10, 7 , 0, 11, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Array before Sorting: ";
    display(arr, n);
    selectionSort(arr, n);
    cout << "Array after Sorting: ";
    display(arr, n);
}