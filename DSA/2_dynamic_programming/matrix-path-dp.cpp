#include "../../DSA/util/recursion_utilities.cpp"
using namespace std;

// https://leetcode.com/problems/unique-paths/submissions/
// TLE on dp as well!


vector<vector<int>> grid;


int dp(int m,int n){
    if(m==0 && n==0){
        return grid[m][n] = 1;
    if(grid[m][n]!=0) return grid[m][n];
    }else if(n==0){
        return grid[m][n] = dp(m-1,n);
    }else if(m==0){
        return grid[m][n] = dp(m,n-1);
    }else return grid[m][n] = dp(m-1,n)+dp(m,n-1);
}
int uniquePaths(int m, int n) {
    grid =  vector<vector<int>>(m,vector<int>(n,0));
    m--;n--;
    return dp(m,n);    
}

int main(){

    cout<<endl<<uniquePaths(3,7);
}