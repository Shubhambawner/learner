#include <bits/stdc++.h>
using namespace std;
void printArr(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<<" "<<arr[i];
    }cout<<endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;cin>>n;
        int arr[n]; 
        int brr[n];
        for(int i = 0; i<n; i++){
            cin>>arr[i];
            brr[i]=arr[i];
        }
        // printArr(brr, 5);
        sort(&brr[0], &brr[n]);//! Sorts the elements in the range [__first,__last) in ascending order
        // printArr(brr, 5);
        bool flag =true;
        for(int i=0;i<n;i++){
            if(arr[i]==brr[i]){
                if(i+1<n){
                    // cout<<"swapping\n";
                    swap(brr[i],brr[i+1]);
                }else if(i-1>=0){
                    // cout<<"swapping2\n";
                    swap(brr[i-1],brr[i]);
                }else{
                    cout<<"-1\n";flag=false;break;
                }
            }
        }
        if(flag)
        for(int i = 0; i<n; i++)cout<<brr[i]<<" ";
        cout<<endl;
    }
}
