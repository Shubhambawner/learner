#include<iostream>
#include<bits/stdc++.h>
#include<Windows.h>//necessary include for color maniulation
using namespace std;
int main(){
    string a = "\tabc\n";int j = 0;
    cout<<a;
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    while (j<256)
    {
        SetConsoleTextAttribute(color, j);
        cout<<j << a;
        j++;
    }
    cout<<"which color to produce?\n";
    while(true){
    cin>>j;
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, j);
	cout<<j << a;
    }
    
}



