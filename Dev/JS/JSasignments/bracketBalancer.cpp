#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isBalanced(string s) {
    if(s.size()%2==1)return "NO";
    stack<char> st;
    for (auto c: s) {
        if(c=='(' || c=='[' || c=='{') st.push(c);
        else{
            if(c==')'){
                if(st.empty() || st.top() != '(') return "NO";
                else st.pop();}
            if(c==']'){
                if(st.empty() || st.top() != '[') return "NO";
                else st.pop();}
            if(c=='}'){
                if(st.empty() || st.top() != '{') return "NO";
                else st.pop();}
        }
    }
    if( st.size()==0)return "YES";
    else return "NO";
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string s;
        cin >> s;
        cout << isBalanced(s) << endl;
    }
    return 0;
}
