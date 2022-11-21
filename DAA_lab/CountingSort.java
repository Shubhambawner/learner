public class CountingSort {

  static void countSort(int[] a, int n) { // function to perform counting sort
    //int max = 42;
    int max = a[0];
    for (int i = 1; i < n; i++) 
      if (a[i] > max) max = a[i];
    

    int[] count = new int[max + 1]; //create count array with size [max+1]
    int[] b = new int[n]; //create clone of a

    for (int i = 0; i <= max; ++i) count[i] = 0; // Initialize count array with all zeros

    for (int i = 0; i < n; i++) count[a[i]]++; // Store the count of each element
    
    for (int i = 1; i <= max; i++) count[i]+=count[i-1]; // count[j] gives no. of elements <= j in the array a[]
    
    for (int i = n-1; i>=0; i--) 
      b[--count[a[i]]]=a[i];

    for (int i = 0; i < b.length; i++) 
      a[i]=b[i];

  }

  /* Function to print the array elements */
  static void print(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) System.out.print(a[i] + " ");
  }

  public static void main(String args[]) {
    int a[] = { 11, 31, 24, 7, 31, 0, 31, 16, 39, 41 };
    int n = a.length;
    System.out.println("\nBefore sorting array elements are - ");
    print(a, n);
    countSort(a, n);
    System.out.println("\nAfter sorting array elements are - ");
    print(a, n);
    System.out.println();
  }
}
