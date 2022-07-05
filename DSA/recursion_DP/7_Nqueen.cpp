#include<bits/stdc++.h>
#include<iostream>
#include "./recursion_utilities.cpp"
using namespace std;


// no of queens placed
int p = 0;
// no of squares
const int n = 8;
// row pointer
int r = 0;

vector<vector<string>> ans;
vector<string> temp(n, string(n,'_'));

bool row[n] = {true} ; //! this is not sufficient to innitialise array with all true !! 
    bool column[n] = {true} ; //? how should wwe do it then?
    bool d1[2*n - 1] = {true} ;
    bool d2[2*n - 1] = {true} ;

bool canPlace(int r, int c){
    if(r<0 || r>=n) cout<<"r out of bounds 1\n";
    if(c<0 || c>=n) cout<<"c out of bounds 1\n";

    //cout<<row[r] << column[c]  <<  d1[r+c]  <<  d2[r-c+n];
    
    return row[r] && column[c] && d1[r+c] && d2[r-c+n];
}

// place queen at row r, column c
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

// remove placed queen at row r, column c
void Qremove(int r, int c){
    //cout<<"removing "<<r<< " "<<c<<"\n";

    //if(r<0 || r>=n) cout<<"r out or bounds 3\n";
    //if(c<0 || c>=n) cout<<"c out or bounds 3\n";
    
    row[r] = true;
    column[c] = true;
    d1[r+c] = true;
    d2[r-c+n] = true;
    temp[r][c] = '_';
}
/*
for among all sq. of first row, choose a square where queen can be placed,
for each choice, place it there and ,
do same with rest of the remaning board recursively.
if there is no row in remaning bord, i.e. current row number == n, the n queens have been placed, return
*/

void N_Queens(){
    //cout<<r<<" "<<n<<" "<<"==\n";
    if(r == n){
        ans.push_back(temp);
        return;
    }

    for(int c = 0; c<n; c++){
        //cout<<r<<" "<<c<<" \n";
            if(canPlace(r,c)){
                Qplace(r,c);
                r++;
                N_Queens();
                r--;
                Qremove(r,c);
            }
        }
}


int main(){
    for(int i=0; i<9;i++)row[i]=true;
    for(int i=0; i<9;i++)column[i]=true;
    for(int i=0; i<17;i++)d1[i]=true;
    for(int i=0; i<17;i++)d2[i]=true;
    N_Queens();
    print2(ans);
}