#include <bits/stdc++.h>
using namespace std;
void printArr(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m,n,k;cin>>n>>m>>k;
        char arr[n]; 
        char brr[m];
        for(int i = 0; i<n; i++){
            cin>>arr[i];
        }
        for(int i = 0; i<m; i++){
            cin>>brr[i];
        }
        // printArr(brr, 5);
        sort(&brr[0], &brr[m]);//Sorts the elements in the range [__first,__last) in ascending order
        sort(&arr[0], &arr[n]);//Sorts the elements in the range [__first,__last) in ascending order
        // printArr(brr, 5);
        bool flag =true;
        vector<int> crr;
        
        int a=0,b=0,kk=0;
        int bs = 0, as = 0;
        while(a<n && b<m){
            if(arr[a]==brr[b]){
                if(as){
                    crr.push_back(brr[b]);b++;
                    as=0;bs=1;//cout<<1<<endl;
                }else{
                    crr.push_back(arr[a]);a++;
                    as=1;bs=0;//cout<<2<<endl;
                }
                kk=1;
            }else if(arr[a]>brr[b]){
                if(bs==k){
                    crr.push_back(arr[a]);a++;bs=0;as=1;//cout<<3<<endl;
                }else{
                    crr.push_back(brr[b]);b++;bs++;as=0;//cout<<4<<endl;
                }
            }else{
                if(as==k){
                    crr.push_back(brr[b]);b++;as=0;bs=1;//cout<<5<<endl;
                }else{
                    crr.push_back(arr[a]);a++;as++;bs=0;;//cout<<6<<endl;
                }
            }
        }
        for (int i = 0; i < crr.size(); i++)
        {
            cout<<(char)crr[i];
        }
        cout<<endl;
    }
}


