// #include "../../DSA/util/recursion_utilities.cpp"
#include<bits/stdc++.h>
using namespace std;

//https://atcoder.jp/contests/dp/tasks/dp_b
// min cost to jump from 0 to n-1th stone, where jumpont from stone i to j cost = |i-j|
int main(){
	int n,k;cin>>n>>k;
	vector<int>arr(n,0);
  for(auto &i:arr){
  	cin>>i;
  }
  vector<int> dp(k,0);
  dp[n-1] = 0;
  for(int i=n-2;i>=0;i--){
    if(i<k){
        dp[i]=abs(arr[i+1]-arr[i])+dp[i+1];
        for(int j=min(i+k,n-1);j>i+1;j--)
            dp[i]=min(abs(arr[j]-arr[i])+dp[j],dp[i]);
    }
    
  }
  cout<<dp[0];
}