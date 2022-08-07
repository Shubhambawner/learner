#include "../../DSA/util/recursion_utilities.cpp"
using namespace std;

// rc(m,n) gives paths from cell m,n to 0,0 at bottom right.
int rc(int m, int n) {
    // Write your code here.
    int ans=0;
    if(m==0 && n==0) return ans;
    else if(m==0) ans+=rc(m,n-1);
    else if(n==0) ans+=rc(m-1,n);
    else ans+= rc(m-1,n)+rc(m,n-1);
    
    return ans;
}

// rc(m,n) gives paths from cell m,n to 0,0 at bottom right.
// So, dp[m][n] stores  gives paths from cell m,n to 0,0 at bottom right.
int rc(int m, int n, vector<vector<int>>& dp) {
    // Write your code here.
    if(dp[m][n]!=0)return dp[m][n];

    int ans=0;
    if(m==0 && n==0) return ans;
    else if(m==0) ans+=rc(m,n-1,dp);
    else if(n==0) ans+=rc(m-1,n,dp);
    else ans+= rc(m-1,n,dp)+rc(m,n-1,dp);
    
    return dp[m][n] = ans;
}

int uniquePaths(int m, int n) {
	// Write your code here.
    // return rc(m,n);
    // vector<vector<int>> dp(m,vector<int>(n,0));
    // return rc(m,n,dp);

    //* Space Ops:
    // since in the table dp, a row once created is only once used (to create a row above it)
    // we just need to store the freshly created row and create new row on top of it, 

    vector<vector<int>> dp(2,vector<int>(n,0));
    dp[0]=vector<int>(n,1);
    dp[1][n-1]=1;
    for(int i=m-2;i>=0;i--){
        dp[1][n-1]=1;
        for(int j=n-2;j>=0;j--){
            dp[1][j]=dp[0][j]+dp[1][j+1];
        }
        swap(dp[0],dp[1]);
        dp[1]=vector<int>(n,0);
    }
    return dp[0][0];
}

int main(){
    cout<<endl<<uniquePaths(2,2);
    cout<<endl<<uniquePaths(3,2);
    cout<<endl<<uniquePaths(1,1);
}