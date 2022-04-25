#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,p,q,x,y;
    cin>>a>>b>>p>>q>>x>>y;

    vector<vector<int>> ans;

    vector<int> p1 = {a,b};
    vector<int> p2 = {p,q};
    vector<int> p3 = {x,y};

    vector<vector<int>> temp = {p1, p2, p3};


    sort(temp.begin(), temp.end(), )
}
// int main()
// {
//     int a,b,p,q,x,y;
//     cin>>a>>b>>p>>q>>x>>y;

//     vector<vector<int>> ans;

//     vector<int> p1 = {a,b};
//     vector<int> p2 = {p,q};
//     vector<int> p3 = {x,y};

//     vector<int> joint = findJoint(p1, p2);

//     ans.push_back(p1);
//     if(Vequal(p2, joint)){
//     ans.push_back(p2);}
//     else
//     {ans.push_back(joint);
//     ans.push_back(joint);
//     ans.push_back(p2);}

//     int dd1 = sqrt((p-x)*(p-x) + (q-y)*(q-y));
//     int dd2 = sqrt((joint[0]-x)*(joint[0]-x) + (joint[1]-y)*(joint[1]-y));

//     int m,n;
//     if(dd1<dd2){
//         m=p; n= q;
//     }else{
//         m = joint[0];
//         n = joint[1];
//     }

//     vector<int> temp = {m,n};

//     vector<int> joint2 = findJoint(temp, p3);

//     if(Vequal(p3, joint2)){
//     ans.push_back(p2);
//     }else
//     {ans.push_back(joint);
//     ans.push_back(joint);
//     ans.push_back(p2);}

// }

