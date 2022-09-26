public class MaxSum {

  static int maxCrossSum(int arr[], int l, int m, int h) {
    int sum = 0;
    int left_sum = Integer.MIN_VALUE;
    for (int i = m; i >= l; i--) {
      sum = sum + arr[i];
      if (sum > left_sum) left_sum = sum;
    }

    sum = 0;
    int right_sum = Integer.MIN_VALUE;
    for (int i = m; i <= h; i++) {
      sum = sum + arr[i];
      if (sum > right_sum) right_sum = sum;
    }

    return Math.max(
      left_sum + right_sum - arr[m],
      Math.max(left_sum, right_sum)
    );
  }

  static int maxSubArraySum(int arr[], int l, int h) {
    if (l > h) return Integer.MIN_VALUE;
    if (l == h) return arr[l];

    int m = (l + h) / 2;

    return Math.max(
      Math.max(maxSubArraySum(arr, l, m - 1), 
      maxSubArraySum(arr, m + 1, h)),
      maxCrossSum(arr, l, m, h)
    );
  }

  public static void main(String[] args) {
    int arr[] = { 2, -3, -4, 5, -1, 2, -4, 6, -1, 1 };
    int n = arr.length;
    int max_sum = maxSubArraySum(arr, 0, n - 1);

    System.out.println("Maximum contiguous sum is " + max_sum);
  }
}
