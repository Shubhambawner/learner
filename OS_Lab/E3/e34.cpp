//Write a C program to simulate paging technique of memory management.
#include<iostream>
using namespace std;
main()
{
int MS, ps, nop, np, remPages, i, j, x, y, pa, offset;
int s[10], fno[10][20];

cout<<"\nEnter the memory size -- ";
cin>>MS;
cout<<"\nEnter the page size -- ";
cin>>ps;
nop = MS/ps;
cout<<"\nThe no. of pages available in memory are -- "<<i<<" ";
cout<<"\nEnter number of processes -- ";
cin>>np;
remPages = nop;
for(i=1;i<=np;i++)
{
cout<<"\nEnter no. of pages required for p["<<i<<"]-- ";
cin>>s[i];
if(s[i] >remPages)
{
cout<<"\nMemory is Full";
break;
}
remPages = remPages - s[i];
cout<<"\nEnter pagetable for p["<<i<<"] --- ";
for(j=0;j<s[i];j++)
cin>>fno[i][j];
}
cout<<"\nEnter Logical Address to find Physical Address ";
cout<<"\nEnter process no. and pagenumber and offset -- ";
cin>>x>>y>>offset;

if(x>np || y>=s[i] || offset>=ps)
cout<<"\nInvalid Process or Page Number or offset";
else
{
pa=fno[x][y]*ps+offset;
cout<<"\nThe Physical Address is -- "<<pa;
}

}