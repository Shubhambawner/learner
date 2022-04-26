#include <iostream>
using namespace std;
void swapping(int &a, int &b)
{ // swap the content of a and b
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void display(int *array, int size)
{
    cout << "{";
    for (int i = 0; i < size; i++){
        cout << array[i] ;
        if(i!=size-1){
            cout<< " ,";
        }}
    cout << "}\n";
}
/* function to sort arr using shellSort */
void shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements arr[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        cout<<"for gap = "<<gap<<" starting from inxex: "<<gap<<" as start of insertion-sort with this gap \n";
        for (int i = gap; i < n; i += 1) {
            // add arr[i] to the elements that have been gap sorted
            // save arr[i] in temp and make a hole at position i
            int temp = arr[i];
            cout<<"for index: "<<i<<" "<<" we have array[i] = "<< temp <<" ";
            // shift earlier gap-sorted elements up until the correct
            // location for arr[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            
            if(j!=i)
            {cout<<"correct position of "<<temp<<" in h-sorted array with gap "<<gap<<" is "<<j<<" , \nso ,shifting all elements in between with gap interval of "<<gap<<"\nand putting this element at right place, \n"
            <<"array is: ";
            display(arr, n);}
            else cout<<"no change needed, moving ahead, \n";
            // put temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }
    }
}
int main()
{
    int arr[] = {0, 17, 12, 0, 13 ,10, 7 , 0, 11, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Array before Sorting: ";
    display(arr, n);
    shellSort(arr, n);
    cout << "Array after Sorting: ";
    display(arr, n);
}