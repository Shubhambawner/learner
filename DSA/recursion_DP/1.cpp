#include<iostream>
using namespace std;

/**
 * @brief infinitely recursive function
 * 
 * @note this will give segmentation fault instead of time limit getting exceeded,  
 * ! this is because recursion uses stack
 * 
 * 
 * @return int 
 */
int rcFunction(){
    return rcFunction();
}