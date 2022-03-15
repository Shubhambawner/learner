#include <bits/stdc++.h>
using namespace std;
int main(){
    //char values:
    // for (int i = 0; i < 256; i++)
    // {
    //     char c = i;
    //     cout<<c<<": character "<<i<<"\n";

    // }

    // char c = 27;
    // cout<<c<<"a got deleated! \n";

    string h = "123";
//    s[0]=''; //! we can replace any other character from string, to any other char, but not '', this is empty character
//!    charValues.cpp:16:10: error: empty character constant
    delete &h[1];
    cout<<h; 
 
}