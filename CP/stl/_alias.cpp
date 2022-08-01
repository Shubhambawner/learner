#include "../../DSA/util/recursion_utilities.cpp"
using namespace std;

int main(){
    cout<<INT8_MAX<<endl;//~~100 (127)
    cout<<INT16_MAX<<endl;//~~10^4
    cout<<INT32_MAX<<endl;//~~10^9
    cout<<INT64_MAX<<endl;//~~10^18
    cout<<INT_MAX<<endl;// INT32_MAX

    cout<<INT8_MIN<<endl;//~~ -100 ( 128)
    cout<<INT16_MIN<<endl;//~~ -10^4
    cout<<INT32_MIN<<endl;//~~ -10^9
    cout<<INT64_MIN<<endl;//~~ -10^18
    cout<<INT_MIN<<endl;// INT32_MAX

    /*
    127
    32767
    2147483647
    9223372036854775807
    2147483647
    -128
    -32768
    -2147483648
    -9223372036854775808
    -2147483648
    */

}