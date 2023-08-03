#include<bits/stdc++.h>
using namespace std;

//returns position, NOT the index
//if the element is not present, returns the -ve of the nearest index, so ,to insert it, compare with return value, if biger, add after, else add b4
int Binary_Search(int *arr, int start, int end, int target)
{
    int mid = (start + end) / 2;
    if (arr[mid] == target)
        return mid+1;
    else if (arr[mid] > target || start==end)
    {
        if(start==mid) return -1*mid;
        return Binary_Search(arr, start, mid - 1, target);
    }
    else if (arr[mid] < target)
    {
        
        return Binary_Search(arr, mid + 1, end, target);
    }
    return 0;
}
int main(){
    int arr[] = {10,20,30,40};
    while (true)
    {
        int j;cin>>j;
        cout<<Binary_Search(arr, 0,3,j)<<'\n';
    }
    
    
}