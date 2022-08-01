#include "../../DSA/util/recursion_utilities.cpp"
using namespace std;

vector<vector<int>> grid;
    int uniquePaths(int m, int n) {
        grid =  vector<vector<int>>(m,vector<int>(n,0));
        m--;n--;
        grid[m][n]=1;
        // cout<<grid<<endl;

        for(int i =m;i>=0;i--){
            for(int j=n;j>=0;j--){
                if(j<n) grid[i][j]+=grid[i][j+1];
                if(i<m) grid[i][j]+=grid[i+1][j];
                // cout<<i<<" "<<j<<" "<<<<endl;
            }
        }
        // cout<<grid<<endl;
        
        return grid[0][0];
    }

int main(){
    cout<<endl<<uniquePaths(3,7);
}