public class RodCutting {
    static int maxPrise(int n, int[] prices, int[] dp){
        if(dp[n]!=-1)return dp[n];
        
        int m = 0;

        for (int i = 1; i <= n; i++) 
            m = Math.max(maxPrise(n-i, prices,dp) + prices[i-1], m);

        return dp[n]=m;
    }

    public static void main(String args[])
    {
        int prices[] = {   1, 5, 8, 9, 10, 17, 17, 20   };
        int size = prices.length;

        int dp[] = new int[size+1];
        dp[0] = 0;
        for (int i = 0; i < dp.length; i++) dp[i]=-1;

        System.out.println("Maximum Obtainable Value is "
                           + maxPrise(size,prices,dp));
    }
}
