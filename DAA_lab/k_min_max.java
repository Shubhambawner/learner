import java.util.*;
public class k_min_max {

  static void kLargest(int arr[], int n, int k){
     PriorityQueue <Integer> pq = new PriorityQueue<Integer>();
     for(int i=0; i<n; i++){
        pq.add(arr[i]);
      
        if(pq.size() > k)
          pq.poll();
     }
      
      while(!pq.isEmpty()){
        System.out.print(pq.peek()+ " ");
        pq.poll();
      }
      //  return pq.peek();
  }

   static void kSmallest(int arr[], int n, int k){
    PriorityQueue<Integer> pq = new PriorityQueue<Integer>(Collections.reverseOrder());

    for(int i=0; i<n; i++){
      pq.add(arr[i]);

      if(pq.size() > k)
        pq.poll();
    }
    while(!pq.isEmpty()){
      System.out.print(pq.peek()+ " ");
      pq.poll();
    }
      // return pq.peek();

   }

  public static void main(String[] args){
    int arr[] = {11,3,2,1,15,5,4};
     int n = arr.length;
     int k =3;
     System.out.print(k + " Largest elements are : ");
     kLargest(arr, n, k);

     System.out.println();

     System.out.print(k + " Smallest elements are : ");
     kSmallest(arr, n, k);
    //  System.out.println(k + " largest element are : " + kthLargest(arr,n,k) );
    //  System.out.println(k + " Smallest element are : " + kthSmallest(arr,n,k) );
  }
};
