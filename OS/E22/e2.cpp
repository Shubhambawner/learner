#include<bits/stdc++.h>
using namespace std; 
int main() 
{ 
int n, i, tm, nob, p=0, bs, mr[20], ifrag[20], tif=0, tef=0, efrag[20]; 
cout<<"Enter the total memory available(in bytes): "; 
cin>>tm; 
cout<<"Enter the block size (in bytes): "; 
cin>>bs; 
cout<<"Enter the number of process: "; 
cin>>n; 
for(i=0;i<n;i++) 
{ 
cout<<"Enter memory required for process"<<i+1<<"(in bytes): "; 
cin>>mr[i]; 
}nob=tm/bs; 
cout<<"Number of blocks available in memory "<<nob<<endl; 
cout<<"Process memory required\tallocated\tinternal fragmentation"<<endl; 
for(i=0;i<n&&p<nob;i++) 
{ 
if(mr[i]<=bs) 
{ 
ifrag[i]=bs-mr[i]; 
cout<<i+1<<"\t\t"<<mr[i]<<"\t\t"<<"YES"<<"\t\t"<<ifrag[i]<<endl; 
p++;tif=ifrag[i]+tif; 
} 
else {cout<<i+1<<"\t\t"<<mr[i]<<"\t\t"<<"NO"<<"\t\t-----"<<endl; 
} 
} 
if(n>i){ 
 cout<<"memory is full. Remaining process can not be accommodated"<<endl;} 
while(i<n){tef=tef+mr[i];i++;} 
cout<<"total internal fragmentation is :"<<tif<<endl; 
cout<<"total external fragmentation is :"<<tef<<endl; 
} 