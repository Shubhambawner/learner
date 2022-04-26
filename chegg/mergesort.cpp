// C++ program for Merge Sort
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


// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid, int const right,  int size)
{
    cout<<"merging sub arrays from indices "<<left<< " to "<<mid<<" with sub array from indices "<<mid+1<<" to "<<right<<" \n in array: ";
    printArray(array, size);
    if(left+1>=right)cout<<"(trivial operation)\n";
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Create temp arrays
	auto *leftArray = new int[subArrayOne],
		*rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne = 0, // Initial index of first sub-array
		indexOfSubArrayTwo = 0; // Initial index of second sub-array
	int indexOfMergedArray = left; // Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
    if(!(left+1>=right)){
    cout<<"we get: ";
    printArray(array, size);}
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end, int size)
{
	if (begin >= end){
		return; // Returns recursively
        cout<<"returning back for starting and ending indices = "<<begin<<" and "<<end<< " \n";
        }


	auto mid = begin + (end - begin) / 2;
        cout<<"merge-sort on interval : start = "<<begin<<" end = "<<end<<" mid being: "<<mid<<"\n";
	mergeSort(array, begin, mid, size);
	mergeSort(array, mid + 1, end, size);
	merge(array, begin, mid, end, size);
}


// Driver code
int main()
{
	int arr[] = {0, 17, 12, 0, 13 ,10, 7 , 0, 11, 8};
	auto arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1,arr_size);

	cout << "\nSorted array is \n";
	printArray(arr, arr_size);
	return 0;
}

// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes
