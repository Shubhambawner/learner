#include <string>
#include <bits/stdc++.h>
using namespace std;

int main(){

    //int to string
    int a=12;
    string as = to_string(a);
    cout<<as<<"\n";

    //string to int
    string str1 = "45.33";
    char str3[] = "31337 geek";
 
    int myint1 = stoi(str1); //stoi("45.33") is 45
    int myint3 = stoi(str3); //stoi("31337 geek") is 31337

    //boolean:
    bool f = -34;cout<<f<<"\n";//1
    int b = f;cout<<b<<"\n";//1
    /*
    any non-zero int is bool "true" & int 0 is "false" bolean
    so, 
    */
 
    //char array to string
    char chr3[] = "31337 geek\n";
    string e(chr3);
    cout<<e; 

    //string to char array
    string st = "Geek\\sForGeeks"; //the c_str() returns const pointer to null terminated contents.
    const char *str = st.c_str();
    cout << str[4];
    if(-2)cout<<"aaaaa\n";
    
    //operations:

    //find char/string
    string str2 = "findthedog\n";
    int i = str2.find('g');
    int i2 = str2.find("dog");
    cout<<"dog at: "<<i2<<"\n"; //7

    //modify character
    str2[i] = 'T';
    cout<<str2; // findthedoT

    //substr function
    string sub = str2.substr(7);//doT from index 7 to end
    sub = str2.substr(4,7);//thedoT 7 chars from from index 4 including itself
    cout<<sub;

    //erase function
    string se = sub.erase(3); //the everything from index 3 incl. itself erased!
    sub="12345";
    se = sub.erase(2,2); //125 everything from index 3 incl. itself erased!
    cout<<se;

    //
    
}