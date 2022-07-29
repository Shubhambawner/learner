#include "./ru.cpp"
using namespace std;

int sum=0;
    void rc(vector<int>& arr){
      cout<<arr<<" "<<sum<<endl;
        if(arr.size()==1){
            return;
        }
        vector<int> brr;
        int n = arr.size();
        for(int i =0; i<n;i+=2){
            int j=arr[i];
            int tp=j;
            if(i<n-1){j*=arr[i+1];tp=max(tp,arr[i+1]);}
            brr.push_back(tp);
            sort(brr.begin(),brr.end());
            if(i<n-1) sum+=j;
        }
            sort(brr.begin(),brr.end());
        return rc(brr);
    }
    int mctFromLeafValues(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        rc(arr);
        return sum;
    }

int main()
{
      vector<int> arr={7,12,8,10};
      cout<<mctFromLeafValues(arr);
}

/*
[
       0[aa, awa, qaa, aar]4 , 
       1[aa, qaa, aar]3 , 
       2[rtaa, aawrawwa, agqaa, aahgear]4        
]3 

[
       0[_ aa _ awa _ qaa _ aar _]4 , 
       1[_ aa _ qaa _ aar _]3 , 
       2[_ rtaa _ aawrawwa _ agqaa _ aahgear _]4 
]3 

[_ 
       0[1, 2]2  _ 
       1[3, 4, 5, 6]4  _ 
       2[1, 2, 3, 4, 5, 6, 3, 4, 5, 6]10  _
       3[3, 4, 5, 6]4
 _]4

[
        1 : [_
              0[4, 4, 5, 6]4  _
              1[6, 6]2
        _]2 ,
        3 : [_
              0[1, 4, 5]3  _
              1[3, 5, 6]3
        _]2 ,
        5 : [_
              0[3, 4]2  _
              1[5, 6]2
        _]2
]3

[_ 1 _ 2 _ 3 _ 4 _ 5 _ 6 _]6

*/