#include "../../DSA/util/recursion_utilities.cpp"
using namespace std;
// https://leetcode.com/problems/unique-paths/submissions/
// TLE on recursion

vector<vector<int>> grid;
    int uniquePaths(int m, int n) {
        if(m==1 && n==1){
            return 1;
        }else if(n==1){
            return uniquePaths(m-1,n);
        }else if(m==1){
            return uniquePaths(m,n-1);
        }else return uniquePaths(m-1,n)+uniquePaths(m,n-1);
    }

int main(){
    cout<<endl<<uniquePaths(3,7);
}