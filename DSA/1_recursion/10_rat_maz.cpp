//{ Driver Code Starts
//Initial template for C++
#include "./recursion_utilities.cpp"
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    int a = 0;
    vector<int> A;
    vector<vector<int> > ans;
    void rc(int starter, int t, vector<int> temp){
        recurse();cout<<spacing<<starter<<" "<<A;
        if(t>a){
            returnRecurse('t');
            return;}
        if(t==a && starter==A.size()){
            ans.push_back(temp);
            cout<<spacing<<ans;
            returnRecurse('o');
            return;
        }
        int s2 = starter;
        
        int tt = t;
        vector<int> tempt = temp;
        
        while(s2+1<A.size() && A[s2]==A[s2+1])s2++;
        while(t <= a){
            cout<<spacing<<t<<" "<<a<<" "<<temp;
            t+=A[starter];
            temp.push_back(A[starter]);
        }
        while(t>=tt){
            cout<<spacing<<tt;
            rc(s2+1,t,temp);
            t-=A[starter];
            temp.pop_back();
        }
        returnRecurse('w');
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        this->a=B;
        this->A=A;
        sort(A.begin(),A.end());
        vector<int>temp;
        rc(0,0,temp);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends