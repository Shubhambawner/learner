#include<iostream>
using namespace std;

class foo{
    public:
    int a = 0;bool b = false;string j = "";
    foo(){
        //this->a=a;
    }
};
class hoo{
    public:
    int a = 0;
    bool b = false;
    hoo(int a){
        this->a=a;
    }
};

int Size(int arr[7]){
    cout<<arr<<'\n';// 0x61fe6c
    return sizeof(arr);

    /*
    NO WAY TO RETURN SIZE OF ARRAY INSIDE FUNCTION, SO HAVE TO PASS IT SPARATELY
    
    sizeof.cpp:21:22: warning: 'sizeof' on array function parameter 'arr' will return size of 'int*' [-Wsizeof-array-argument]
     return sizeof(arr)/sizeof(arr[0]);
                      ^
    sizeof.cpp:20:14: note: declared here
        int Size(int arr[]){
          ~~~~^~~~~
    
    */

}


int main(){
    cout<<"(int)"<<sizeof(int)<<'\n';  //4
    cout<<"(long long)"<<sizeof(long long)<<'\n';  //8
    cout<<"(double)"<<sizeof(double)<<'\n';  //8
    cout<<"(long)"<<sizeof(long)<<'\n';  //4
    cout<<"(float)"<<sizeof(float)<<'\n';  //4
    cout<<"(bool)"<<sizeof(bool)<<'\n';  //1
    cout<<"(float)"<<sizeof(float)<<'\n';  //4
    cout<<"(char)"<<sizeof(char)<<'\n';  //1

    foo bar;
    cout<<"(foo)"<<sizeof(bar)<<'\n';//1
    hoo var(3);
    cout<<"(hoo)"<<sizeof(var)<<'\n';//1

        
    int arr[5];
    cout<<sizeof(arr)<<'\t'<<sizeof(arr[1])<<'\n'; //20      4

    bool brr[5];
    cout<<sizeof(brr)<<'\t'<<sizeof(brr[1])<<'\n'; //5       1

    int j;
    cin>>j;
    int crr[j]; //7
    cout<<sizeof(crr)<<'\t'<<sizeof(crr[0])<<'\n'; //28      4
    cout<<"Size(arr): "<<Size(arr)<<'\n';// 1
    
    string g;
    cin>>g;//anything
    cout<<sizeof(g)<<'\n';  //24

    
}
/*

(int)4
(long long)8
(double)8
(long)4
(float)4
(bool)1
(float)4
(foo)32
(hoo)8
20      4
5       1
9
36      4
rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
24

*/