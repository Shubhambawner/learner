// import java.util.*;
public class Quick {

  static void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }

  static int partition(int arr[], int l, int r) {
    int pivot = arr[r];// last element pivot
    int i = l - 1;

    for (int j = l; j < r; j++) {
      if (arr[j] < pivot) {
        i++;
        swap(arr, i, j);
      }
    }
    swap(arr, i + 1, r);
    return i + 1;
  }

  static void quickSort(int arr[], int l, int r) {
    if (l < r) {
      
      int pi = partition(arr, l, r);

      quickSort(arr, l, pi - 1);
      quickSort(arr, pi + 1, r);
    }
  }

  public static void main(String args[]) {
    int arr[] = { -1, 34, 76, 23, 0, 400, 5 };
    int n = arr.length;

    quickSort(arr, 0, n - 1);

    System.out.print("soretd array is : ");
    for (int i = 0; i < n; i++) {
      System.out.print(arr[i] + " ");
    }
    System.out.println();
  }
}
