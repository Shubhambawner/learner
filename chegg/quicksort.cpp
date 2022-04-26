#include <iostream>
using namespace std;


// UTILITY FUNCTIONS
// Function to print an array
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
// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high, int size)
{
	int pivot = arr[high]; // pivot
    cout<<"partitioning around last element i.e. pivot = array["<<high<<"] = "<<pivot<<"\n";
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
    cout<<"correct position of pivot is: "<<i+1<<"\nand state of partly sorted array now is:";
    printArray(arr,size);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high, int size)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
        cout<<"quick sort on range of indices: "<<low<<" to "<<high<<" ";
		int pi = partition(arr, low, high, size);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1, size);
		quickSort(arr, pi + 1, high, size);
	}
}



// Driver Code
int main()
{
	int arr[] = {0, 17, 12, 0, 13 ,10, 7 , 0, 11, 8};
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1, n);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}

// This code is contributed by rathbhupendra
