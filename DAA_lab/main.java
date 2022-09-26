// import java.util.*;
 class Bubble {

   static void bubbleSort(int arr[], int n){
    int counter = 1;

    while(counter < n){
      for(int i=0; i<n-counter; i++){
         if(arr[i] > arr[i+1])
         {
             int temp = arr[i];
             arr[i] = arr[i+1];
             arr[i+1] = temp;
         }
      }
         counter++;
    }
   }

   static void print(int arr[], int n){
    System.out.print("sorted array is : ");
       for(int i=0; i<n; i++){
         System.out.print(arr[i] + " ");
       }
     }

     
  public static void main(String args[]){
         int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
         int n = arr.length;

          bubbleSort(arr,n);
          print(arr,n);
     } 
};
