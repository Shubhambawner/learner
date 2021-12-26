#include<bitset>
#include<iostream>
using namespace std;

//binary numbers: array of bits, 32x less space than int

void print(bitset<4> b){
    cout<<b[3];
    cout<<b[2];
    cout<<b[1];
    cout<<b[0]<<"\n";
}
void print(bitset<64> b){
    int n=64;
    //reverse order indexing i.e from right to left
    for (int i = n-1; i >= 0; i--)
    {
        cout<<b[i];
    }
    
    cout<<"\n";
}
int main(){
    bitset<4> b("1010");
    bitset<4> a("1100");

    //int to bitset
    bitset<64> ar(302); //64 bit is enough for a long long int type too!!
    print(ar);

    print(b&a);
    print(b|a);
    print(b^a);
    print(~a);
    /*
    1000
    1110
    0110
    0011
    */

    b.flip(3);
    cout<<b;
    
}