
#include<iostream>
using namespace std;

int main(){
    int T;
    cin>>T;
    while (T-->0)
    {
        int n, index=0;
        cin>> n;
        int locations[n+1][2];//0th is wasted space ):
        int arr[2*n];//0th is wasted space ):
        for(index; index<2*n; index++){
            int ai;
            cin>>ai;
            arr[index]=ai;
            if (locations[ai][0]==0)    
            {
                locations[ai][0] == index;
            } else{
                locations[ai][1] == index;
            }            
        }
        int stack=0;
        for (int i = 0; i < 2*n; i++)
        {
            if (locations[arr[i]][1]==i)
            {                
                locations[arr[i]][0]= arr[locations[arr[i]][0]]- --stack;
            }else{
                arr[i] = stack;
            }
             
        }
        
        
    }
    
    
}

/*ZYM~@X)wQ.-HS95*/
