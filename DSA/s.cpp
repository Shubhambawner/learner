#include "./util/recursion_utilities.cpp"
using namespace std;


int y = 0;
double getSqroot(double a,double b, double f2, double precision){
    // w(a,b,f2,precision);
    double mid = ((a+b)/2);
    if(y++==10)return mid;
    if((mid+precision)*(mid+precision)>=f2 && (mid-precision)*(mid-precision)<=f2 )return mid;
    else if(mid*mid<f2) return getSqroot((a+b)/2,b,f2,precision);
    else return getSqroot(a, (a+b)/2 ,f2,precision);
}

int main(){
    double f2 = 5;
    double a = 0;
    while(a*a<f2)a++;
    a--;
    double precision = 0.00000001;
    while(abs(a*a-f2)>precision){
        if(a*a<f2){
            a+=(f2-a*a)/(2*a);
            // cout<<(f2-a*a)/(2*a)<<endl;
        }else{
            a-=(a*a-f2)/(2*a);
            // cout<<(a*a-f2)/(2*a)<<endl;
        }
            // cout<<abs(a*a-f2)<<" "<<a*a<<endl;
    }
    cout<<a<<endl;

    cout<<getSqroot((double)0,f2,f2,precision);
}