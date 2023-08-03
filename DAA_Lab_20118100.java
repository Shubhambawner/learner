public class DAA_Lab_20118100 {
  public static void swap(int arr[],int n,int m){
    int temp = arr[n];
    arr[n] = arr[m];
    arr[m] = temp; 
  }
    public static void selectionSort(int arr[]){
      int n = arr.length;
      for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        // System.out.println("For position: "+i);
        for (int j = i+1; j < n; j++) {
          if(arr[j]<arr[minIndex]) minIndex = j;
        }
        // System.out.println("\tminimum element at index "+minIndex+"\nswaping elements...");
        swap(arr,i,minIndex);
      }
    }

    public static void print(int arr[]){
      for (int i = 0; i < arr.length; i++) {
        System.out.print(arr[i]+", ");
      }
      System.out.println();
    }

  
    public static void main(String args[]) {
      int arr[] = {1,1,23,-34,53,1, 34,22};
      selectionSort(arr);
      print(arr);
    }
  }
  