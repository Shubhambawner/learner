#include<iostream> 
using namespace std;

/*

in c++ there is no arrayIndexOutOfBounds exeption,
declear array of size 3, access/ modify element at arr[7], no error!!

(then why the hell we declear there size?)

*/


int main()
{
int brr[1];
cout<<brr[7]<<'\n';
brr[7]= 88;
cout<<"new brr: "<<brr[7];

return 0;
}

/*

10425964
new brr: 88

*/
