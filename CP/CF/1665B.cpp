#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;cin>>N;
    while(N--){ 
        int n;cin>>n;
        int arr[n];
        map<int,int> mp;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(!mp[arr[i]])mp[arr[i]]=1;
            else mp[arr[i]]++;
        }
        int maxSame = 0;
        for(auto i= mp.begin(); i!=mp.end(); i++){
            maxSame = max(maxSame, i->second);
        }
        int steps = 0, counter = maxSame;
        while(counter<n){
            counter*=2;
            steps++;
        }
        cout<< steps+ n - maxSame<< "\n";
    }

}