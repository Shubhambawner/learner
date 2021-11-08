#include<iostream>
#include<stack>
#include <map>
#include <vector>
#include <string>
using namespace std;

/*
string getline() {
    string oio = "";
    string token;
    string nl = "\n";
    cin >> token;cout<<"token got: "<<token;
    while (token != nl) {
        oio += token;
        cin >> token;
        cout<<"w :"<<token<< (token==nl)<<nl;
     };cout<<"oio__:"<<oio<<nl;
    return oio;
}
*/
vector<string> token(string lin, char cut) {
    vector<string> g1;
    int a = 0;
    for (int i = 0; i < lin.size(); i++) {
        string token;
        if (lin[i] == cut) {
            g1.push_back(token); a++;
        }
        else {
            token += lin[i];
        }
    }/*
    string arr[a];a=0;
    for (auto i = g1.begin(); i < g1.end(); i++)
    {
        arr[a]=*i;a++;
    }*/

    return g1;
}
int main() {
    int a, b;
    map<string, string> amap; stack<string>Stk;
    cin >> a >> b;cout<<"w8"<<a<<b;
    while (a-- > 0)
    {
        string linex;
        cout<<a;
        getline(cin, linex);//getline accepts char array of fix length, and , other parameter  a int less than char array.
        vector<string> g1 = token(linex, ' ');
        for (int i = 0; i < g1.size(); i++)
        {
            cout << g1[i] << endl;cout<<"w2";
        }
    }
}
















