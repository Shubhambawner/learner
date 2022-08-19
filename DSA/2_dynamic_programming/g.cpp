// { Driver Code Starts
#include<bits/stdc++.h>
#include "../../DSA/util/recursion_utilities.cpp"
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    bool canVisit(int i, int j, vector<vector<int>>& grid,vector<vector<int>>& dp,int n, int m){
        e(i,j);
        
        if(!(i>=0 && i<n && j>=0 && j<m)) return false;

        //w('e');
        if(grid[i][j]==2)return true;
        //w('q');
        if(dp[i][j]!=-1)return dp[i][j];
        //w('r');
        bool is = false;
        int t = grid[i][j];
        grid[i][j]=0;

        for(int x = -1;x<2;x++){
            for(int y = -1;y<2;y++){
                w(i,x,j,y);
                if((x==0 && y==0))continue;
                if( i+x>=0 && i+x<n && j+y>=0 && j+y<m && grid[i][j]!=0)
                    is = is || canVisit(i,j,grid,dp,n,m);
            }    
        }

        grid[i][j]=t;
        b(is);
        return dp[i][j] = is;
    }
    
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    bool is = canVisit(i,j,grid,dp,n,m);
                    if(grid[i][j]==1) return is;
                }
            }    
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc = 1;
	// cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends