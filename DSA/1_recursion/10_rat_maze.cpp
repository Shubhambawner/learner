// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:

int n = 0;
string temp;
vector<string> paths;
vector<vector<int>> maze;
void rc(int r, int c, char t)
{
    if(r<0 || c<0 || r>= n || c>= n || maze[r][c]==0){
        return;
    }
    if (r == n - 1 && c == n - 1)
    {
        temp.push_back(t);
        paths.push_back(temp);
        temp.pop_back();
        return;
    }
    maze[r][c]=0;
    if(t!='q')temp.push_back(t);
        rc(r + 1, c, 'D');
        rc(r, c - 1, 'L');
        rc(r, c + 1, 'R');
        rc(r - 1, c, 'U');
    temp.pop_back();
    maze[r][c]=1;
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    // Your code goes her
    maze = m;
    this->n = n;
    rc(0,0,'q');
    return paths;
}
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends