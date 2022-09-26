public class kMinMax {

  static int getKthElem(int arr[], int n, int k, MaxHeap pq) {
    if (n < k) System.out.println("k more than n!");

    for (int i = 0; i < n; i++) {
      pq.add(arr[i]);
    }
    int ans = 0;

    while (k-- > 0) {
      ans = pq.poll();
    }
    return ans;
  }

  public static void main(String[] args) {
    int arr[] = { 5, 4, 3, -3, 45, 344, 0 };
    int n = arr.length;
    int k = 15;

    MaxHeap pq = new MaxHeap(n);
    System.out.print(
      k + "th Largest element is : " + getKthElem(arr, n, k, pq) + "\n"
    );

    MinHeap pr = new MinHeap(n);
    System.out.print(
      k + "th Smallest element is : " + getKthElem(arr, n, k, pr)
    );
  }
}

class MaxHeap {

  int[] Heap;
  int size, maxsize;

  MaxHeap(int maxsize) {
    this.maxsize = maxsize;
    this.size = 0;
    Heap = new int[this.maxsize];
  }

  int parent(int pos) {
    return (pos - 1) / 2;
  }

  int leftChild(int pos) {
    return (2 * pos) + 1;
  }

  int rightChild(int pos) {
    return (2 * pos) + 2;
  }

  void swap(int fpos, int spos) {
    int tmp = Heap[fpos];
    Heap[fpos] = Heap[spos];
    Heap[spos] = tmp;
  }

  void heapify(int pos) {
    int largest = pos;
    int l = leftChild(pos);
    int r = rightChild(pos);

    if (l < size && priority(l, largest)) largest = l;
    if (r < size && priority(r, largest)) largest = r;

    if (largest != pos) {
      swap(largest, pos);
      heapify(largest);
    }
  }

  void add(int element) {
    Heap[size] = element;
    int current = size;
    while (priority(current, parent(current))) {
      swap(current, parent(current));
      current = parent(current);
    }
    size++;
  }

  int poll() {
    int popped = Heap[0];
    Heap[0] = Heap[--size];
    heapify(0);
    return popped;
  }

  //return true if element at pos2 is HIGHER in priority thatn that of pos1
  boolean priority(int pos2, int pos1) {
    return Heap[pos2] > Heap[pos1]; // by default a max-heap
  }
}

class MinHeap extends MaxHeap {

  MinHeap(int maxsize) {
    super(maxsize);
  }

  //return true if element at pos2 is HIGHER in priority thatn that of pos1
  boolean priority(int pos2, int pos1) {
    return Heap[pos2] < Heap[pos1]; // min-heap
  }
}
