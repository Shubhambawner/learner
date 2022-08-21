#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

template<class T>
void print(T*start, T*end){
    cout<<"printing sequence : ";
    for(T*i=start; i!=end;i++){ 
        cout<<*i<<" ";
    }
    cout<<"\n";
}

int main(){

    int arr[] ={1,2,3,4,5,6,7,44,8,9,0};

    swap(arr[1], arr[2]);

    sort(arr, arr+11);

    reverse(arr,arr+ 11);

    random_shuffle(arr,arr+11);

    sort(arr, arr+11);
    print<int>(arr, arr+11);
    //boolean returner binary_search
    if( binary_search(arr, arr+11, 44) ) cout<<"44 is there in arr\n";
    cout<<"44 is there at "<<find(arr, arr+11, 44) - arr<<"th of arr\n";


    vector<int> v = {1,2,3,4,5,6,7,44,8,9,0};

    sort(v.begin(), v.end());
    //* https://www.geeksforgeeks.org/sort-c-stl/ 

    reverse(v.begin(), v.end());

    random_shuffle(v.begin(), v.end());

    //boolean returner binary_search
    sort(v.begin(), v.end());
    if( binary_search(v.begin(), v.end(), 44) ) cout<<"44 is there in v\n";
    
    cout<<max(1,2);

    // gcd of 2 numbers
    cout<<__gcd(55,100);
}