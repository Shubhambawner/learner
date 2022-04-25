#include<bits/stdc++.h>
#include<iostream>
#include "./recursion_utilities.cpp"
using namespace std;



int p = 0;
const int n = 8;
int r = 0;

vector<vector<string>> ans;
vector<string> temp(n, string(n,'U'));

bool row[n] = {true} ; //! this is not sufficient to innitialise array with all true !! 
    bool column[n] = {true} ; //? how should wwe do it then?
    bool d1[2*n - 1] = {true} ;
    bool d2[2*n - 1] = {true} ;

bool canPlace(int r, int c){
    if(r<0 || r>=n) cout<<"r out or bounds 1\n";
    if(c<0 || c>=n) cout<<"c out or bounds 1\n";

    //cout<<row[r] << column[c]  <<  d1[r+c]  <<  d2[r-c+n];
    
    return row[r] && column[c] && d1[r+c] && d2[r-c+n];
}

void Qplace(int r, int c){
     //cout<<"placing "<<r<< " "<<c<<"\n";

    //if(r<0 || r>=n) cout<<"r out or bounds 2\n";
    //if(c<0 || c>=n) cout<<"c out or bounds 2\n";
    row[r] = false;
    column[c] = false;
    d1[r+c] = false;
    d2[r-c+n] = false;
    temp[r][c] = 'Q';
}

void Qremove(int r, int c){
    //cout<<"removing "<<r<< " "<<c<<"\n";

    //if(r<0 || r>=n) cout<<"r out or bounds 3\n";
    //if(c<0 || c>=n) cout<<"c out or bounds 3\n";
    
    row[r] = true;
    column[c] = true;
    d1[r+c] = true;
    d2[r-c+n] = true;
    temp[r][c] = 'U';
}
void Nplace(){
    //cout<<r<<" "<<n<<" "<<"==\n";
    if(r == n){
        if(p==n) ans.push_back(temp);
        return;
    }

    for(int c = 0; c<n; c++){
        //cout<<r<<" "<<c<<" \n";
            if(canPlace(r,c)){
                Qplace(r,c);
                r++;p++;
                Nplace();
                r--;p--;
                Qremove(r,c);
            }
        }
}


int main(){
    for(int i=0; i<9;i++)row[i]=true;
    for(int i=0; i<9;i++)column[i]=true;
    for(int i=0; i<17;i++)d1[i]=true;
    for(int i=0; i<17;i++)d2[i]=true;
    Nplace();
    print2(ans);
}