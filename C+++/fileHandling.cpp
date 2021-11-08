//#include<conio.h>
#include<iostream>
#include<fstream>
using namespace std;
void printArr(char ans[]){
    for (int i = 0; i < 100; i++)
    {
        cout<<ans[i];
    }
    cout<<endl;
}
int main(){
    fstream file;char ans[100] ;
  
    file.open("C:\\abc.txt");//opens the file internally for being read or writen
    cout<<file.is_open()<<endl;    
    file.getline(ans, 100);// gets line of 50 chars and puts it to char[] ans
    cout<<ans<<endl;
    file.getline(ans, 100);// gets line of 50 chars and puts it to char[] ans
    cout<<ans<<endl;file.getline(ans, 100);// gets line of 50 chars and puts it to char[] ans
    cout<<ans<<endl;file.getline(ans, 100);// gets line of 50 chars and puts it to char[] ans
    cout<<ans<<endl;
    file.close();
    
    return 0 ;
}
