#include<iostream>
#include <cstring>
using namespace std;
int main(){

    string j = "1234567";
    string h = string(j, 1, 3); //* constructor to construct from other strings
    
    //string length
    cout<<j.length()<<"\n";

    //string operations:
    //1. concatanation: 
    string g = j+j;

    //string conversions:

    //string -> char-array 
    //1. while initialisation:
        char arr[] = "";//only string literal can be passed, NOT any pre defined string variable
        cin>>arr;
        cout<<arr<<"\n";// will take inn input string , but without spaces!!!!!
    //2. strcpy method:
        // declaring character array
        int n = g.length()+1;
        char char_array[n];
    
        // copying the contents of the string to char array
        strcpy(char_array, g.c_str());
    
        for (int i = 0; i < g.length(); i++)
            {cout << char_array[i]<<", ";}
        cout<<"--\n";
        
    //char-array -> string
    //1. via constructer
    string jj(arr); 
    cout<<jj<<"\n";
    //2. via overloaded '=' operator
    string jk = arr;
    cout<<jk<<"\n";





}