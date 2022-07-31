#include "../../DSA/util/recursion_utilities.cpp"
using namespace std;

int main(){
    cout<<5/2; //! integer division: b*(a/b) + a%b = a 
    //! OR, we can say, a/b truncates to lower side in integer division

    double f = 1/2 + 2/2; // f = 1
    double f = (1+2)/2; // f = 1
    double f = ((double)(1+2))/2; // f = 1.5
    cout<<f;
}