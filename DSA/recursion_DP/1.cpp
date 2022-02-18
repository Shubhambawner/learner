#include<iostream>
using namespace std;

/**
 * @brief infinitely recursive function
 * 
 * @note this will give segmentation fault instead of time limit getting exceeded,  
 * ! this is because recursion uses stack, and memory gets exceeded
 *  
 */
int rcFunction(){
    return rcFunction();
}
/**
 * @brief simple recursion call
 * 
 * @return int 
 */
int rcFunction1(int i){
    if(i==0) return 1;
    cout<< i<<"\n";
    return rcFunction1(--i);
}

int main(){
    //cout<<rcFunction();
    rcFunction1(5);
}