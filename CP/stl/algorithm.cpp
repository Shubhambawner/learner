#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
int main(){

    int arr[] ={1,2,3,4,5,6,7,44,8,9,0};

    sort(arr, arr+11);

    reverse(arr,arr+ 11);

    random_shuffle(arr,arr+11);

    //boolean returner binary_search
    sort(arr, arr+11);
    if( binary_search(arr, arr+11, 44) ) cout<<"44 is there in arr\n";


    vector<int> v = {1,2,3,4,5,6,7,44,8,9,0};

    sort(v.begin(), v.end());

    reverse(v.begin(), v.end());

    random_shuffle(v.begin(), v.end());

    //boolean returner binary_search
    sort(v.begin(), v.end());
    if( binary_search(v.begin(), v.end(), 44) ) cout<<"44 is there in v\n";
    
}