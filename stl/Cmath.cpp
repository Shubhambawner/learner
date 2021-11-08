#include<cmath>
#include<bits/stdc++.h>
using namespace std;

    
    
int main(){
    //max/min------------------------------
    int a=4,b=5;
    cout<<max(a,b)<<"\n";
    cout<<min(a,b)<<"\n";

    //square/cube roots----------------------
    cout<< sqrt(a) <<"\n"; //2
    cout<< cbrt(8) <<"\n"; //2
    cout<< hypot(12, 5) << "\n"; //13 hypotenuse triple: 5, 12, 13
    //if the values are not exact integers, float till 4 decimal will be returned

    //exp functions------------------------
    cout<< exp(3) <<"\n"; //20.0855
    cout<< exp2(3.5) <<"\n";  //11.3137
    cout<< pow(10, 2) <<"\n"; //100

    //log function---------------------------
    cout<< log(20.0855) << "\n"; // 3 surprisingly, the values are precise! 
    cout<< log2(11.3137) << "\n";  // 3.5 surprisingly, the values are precise!

    //float->int functions------------------------
    cout<< ceil(-2.50) <<" "<< ceil(2.50)   << "\n"; //-2 3 increase
    cout<< floor(-2.50)<<" "<< floor(2.50)  << "\n"; //-3 2 decrease
    cout<< round(-2.50)<<" "<< round(2.50)  << "\n"; //-3 3 take it away from 0 
    cout<< trunc(-2.50)<<" "<< trunc(2.50)  << "\n"; //-2 2 take it closer to 0 

    //absolute value---------------------------
    cout<< abs(-232) << "\n"; // max(a, -a)

    //floating point comparison ---------------------
    

    
    
}