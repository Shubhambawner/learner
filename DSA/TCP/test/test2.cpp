//frpg problem


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


int main() {
    int n,m;cin>>n>>m;
    string nString;cin>>nString;
    multimap<long long int,double> G;
    multimap<long long int,double>::iterator ptr1;
    bool flag = true;
    while(n--){
        long long int x,y;
        cin>>x>>y;
        G.insert({x,y});
        if(flag){
            ptr1 = G.begin();
            flag = false;
        }
    }
    
    multimap<long long int,double>::iterator ptr = ptr1; 

    for(int i = 0; i<m;i++){
        char dir = nString[i];
        
        if(dir=='A'){
            for(auto i = ptr; i!=G.end(); i++){//cout<<i->first<<" "<<i->second<<" "<<ptr->first<<" "<<ptr->second<<"\n";
                if(i->first-i->second == ptr->first-ptr->second && i->first>ptr->first){
                    ptr->second = 0.45;
                    ptr = i;//cout<<"-----\n";
                    break;
                }
            }
        }else if(dir=='B'){
            for(auto i = ptr; i!=G.end(); i++){//cout<<i->first<<" "<<i->second<<" "<<ptr->first<<" "<<ptr->second<<"\n";
                if(i->first+i->second == ptr->first+ptr->second && i->first>ptr->first){
                    ptr->second = 0.45;
                    ptr = i;//cout<<"-----\n";
                    break;
                }
            }
        }else if(dir=='C'){
            for(auto i = ptr; i!=G.end(); i--){//cout<<i->first<<" "<<i->second<<" "<<ptr->first<<" "<<ptr->second<<"\n";
                if(i->first+i->second == ptr->first+ptr->second && i->first<ptr->first){
                    ptr->second = 0.45;
                    ptr = i;//cout<<"-----\n";
                    break;
                }
            }
        }else if(dir=='D'){
            for(auto i = ptr; i!=G.end(); i--){//cout<<i->first<<" "<<i->second<<" "<<ptr->first<<" "<<ptr->second<<"\n";
                if(i->first-i->second == ptr->first-ptr->second && i->first<ptr->first){
                    ptr->second = 0.45;
                    ptr = i;//cout<<"-----\n";
                    break;
                }
            }
        }else{
            cout<<dir<<" error\n";
        }
                   // cout<<dir<<"\n";

    }
    cout<<ptr->first<<" "<<ptr->second<<"\n";
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
/***
 * *
 * 
6 12
AAAAAABCCCDD
1 1
2 2
3 3
4 4
5 3
6 2
*/