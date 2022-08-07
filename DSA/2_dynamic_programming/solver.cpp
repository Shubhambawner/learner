#include "../../DSA/util/recursion_utilities.cpp"
using namespace std;

// calculate Minimum HP needed to go from index i,j to end, n-1,m-1
    int calculateMinimumHPfrom(int i, int j, vector<vector<int>>& dungeon,vector<vector<int>>& dp, int n , int m){
        int ans = dungeon[i][j], down = INT_MAX, right = INT_MAX;
        if(i==n-1 && j==m-1){
            if(ans>0)return 1;
            else return 1 - ans;
        }
        if(i<n-1){
            down = calculateMinimumHPfrom(i+1, j, dungeon, dp, n , m);
            if(ans>=down)return 1;
            else down = down - ans ;
        }
        if(j<m-1){    
            right = calculateMinimumHPfrom(i, j+1, dungeon, dp, n , m);
            if(ans>=right)return 1;
            else right = right - ans ;
        }
            return min(down, right);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return calculateMinimumHPfrom(0,0,dungeon,dp, n , m);
    }

int main() {
    vector<vector<int>> dungeon = {{-2,-3,3},{-5,-10,1},{10,30,-5}};

  cout<<calculateMinimumHP(dungeon);
}