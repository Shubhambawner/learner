#include<iostream>
#include<string>
using namespace std;
int main(){
    while(true)
    {
        string j;
        cout<<"enter anything or press enter\t";
        getline(cin, j);cout<<"j read as:\t"<<j<<endl;
        cout<<"but, dose getline wait for user input?\n";
        if(j.length() == 0){
            cout<<j<<"getline did it!! \n";
        }
    }
}

/*
        char j;
        cin>>j;
        if(j[0]=='\n'){
            //new line user input can't be detected this way!!!!!!
            cout<<"newline detected!!\n";
        }
        if (cin.get() == '\n') {
            //pressed enter can be, bur new line can't be detected this way too!!!!!!
            cout << "ENTER WAS PRESSED\n";
        }

*/


/*output

enter anything or press enter   something
j read as:      something
enter anything or press enter
j read as:
getline did it!!
enter anything or press enter

*/