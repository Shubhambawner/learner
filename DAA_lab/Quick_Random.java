import java.util.Random;

// import java.util.*;
public class Quick_Random {

  static void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }

  static int partition(int arr[], int l, int r) {
    int pivot = arr[r]; // last element pivot
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
      swap(arr, getPivot(l, r), r);
      int pi = partition(arr, l, r);

      quickSort(arr, l, pi - 1);
      quickSort(arr, pi + 1, r);
    }
  }

  static int pivotAt = 0;

  private static int getPivot(int l, int r) {
    Random rand = new Random();
    int random = rand.nextInt(r - l) + l;

    if(pivotAt==1)return l;
    if(pivotAt==2)return r;
    if(pivotAt==3)return random;
    if(pivotAt==0)return (r-l)/2 + l;

    return random;
  }

  static void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
      System.out.print(arr[i] + " ");
    }
    System.out.println();
  }

  public static void main(String args[]) {
    int arr[] = { 1, 34, 76, 23, 70, 40, 5 };
    int n = arr.length;

    String pivotName[] = {"middle", "last", "first", "random"};

    for(int i=0;i<4;i++){  
      pivotAt = i;
      quickSort(arr, 0, n - 1);
      System.out.println("array sorted using pivot at "+pivotName[pivotAt]+" element: ");
      print(arr, n);
    }
  }
}
