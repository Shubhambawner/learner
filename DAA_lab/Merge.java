// import java.util.*;
public class Merge {

  static void merge(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a[] = new int[n1];
    int b[] = new int[n2];

    for (int i = 0; i < n1; i++) a[i] = arr[l + i];

    for (int i = 0; i < n2; i++) b[i] = arr[mid + 1 + i];

    int i = 0,j = 0,k = l;

    while (i < n1 && j < n2) {
      if (a[i] <= b[j]) arr[k++] = a[i++]; else arr[k++] = b[j++];
    }

    while (i < n1) 
      arr[k++] = a[i++];
    

    while (j < n2) {
      arr[k++] = b[j++];
    }
  }

  static void mergeSort(int arr[], int l, int r) {
    if (l < r) {
      int mid = (l + r) / 2;
      mergeSort(arr, l, mid);
      mergeSort(arr, mid + 1, r);

      merge(arr, l, mid, r);
    }
  }

  public static void main(String args[]) {
    int arr[] = { 12, 11, -13, 5, 6, 7 };
    int n = arr.length;

    mergeSort(arr, 0, n - 1);

    // print the sorted array
    System.out.print("sorted array is : ");
    for (int i = 0; i < n; i++) {
      System.out.print(arr[i] + " ");
    }
  }
}
