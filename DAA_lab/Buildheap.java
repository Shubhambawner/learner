public class Buildheap {

  static void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;

    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
      int temp = arr[i];
      arr[i] = arr[largest];
      arr[largest] = temp;

      heapify(arr, n, largest);
    }
  }

  static void buildHeap(int arr[], int n) {
    for (int i = (n - 2) / 2; i >= 0; i--) heapify(arr, n, i);
  }

  static void heapSort(int arr[], int n) {
    buildHeap(arr, n);
    System.out.print("after heap : ");
    printHeap(arr, n);

    for (int i = n - 1; i >= 1; i--) {
      int temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp;

      heapify(arr, i, 0);
    }
  }

  static void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
      System.out.print(arr[i] + " ");
    }
  }

  public static void main(String args[]) {
    int arr[] = { 1, 3, -15, 4, 600, 10, 9, 15 };
    int n = arr.length;

    heapSort(arr, n);
    System.out.print("\nsorting of elements : ");
    printHeap(arr, n);
  }
}
