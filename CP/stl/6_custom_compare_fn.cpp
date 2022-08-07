//! usefull for sorting complex data structures, 
//! maintaining sets/multisets/maps/multimaps of complex data structures
// https://en.cppreference.com/w/cpp/named_req/Compare
/*
Establishes strict weak ordering relation with the following properties
For all a, comp(a,a)==false
If comp(a,b)==true then comp(b,a)==false
if comp(a,b)==true and comp(b,c)==true then comp(a,c)==true
*/

#include "../../DSA/util/recursion_utilities.cpp"
using namespace std;

//! THUMB RULE
//! v1 will apear before v2 if this function returns true, if returns false, will apear after v2

bool customCompare1(const vector<int>&v1,const vector<int>&v2){
    return abs(v1[0]-v1[1])<abs(v2[0]-v2[1]);
}
bool customCompare2(const vector<int>&v1,const vector<int>&v2){
    return (v1[0]*v1[1])<(v2[0]*v2[1]);
}

int main(){
    vector<vector<int>> r = {{5,5},{6,4},{7,3},{8,2},{9,1}};

    //sort difference smallest to largest
    sort(r.begin(),r.end(),customCompare1);
    // cout<<r<<endl;  // o/p: [5, 5]2  [6, 4]2  [7, 3]2  [8, 2]2  [9, 1]2  

    // sort product smallest to largest
    sort(r.begin(),r.end(),customCompare2);
    // cout<<r<<endl; //o/p: [9, 1]2  [8, 2]2  [7, 3]2  [6, 4]2  [5, 5]2

    set<vector<int>,decltype(customCompare1)*> customSet(customCompare1);
    customSet.insert({9,1});
    customSet.insert({6,4});
    customSet.insert({5,5});
    customSet.insert({7,3});
    customSet.insert({8,2});
    for (auto x : customSet) {
        // cout << x << ' ';
    }// o/p: [5, 5]2  [6, 4]2  [7, 3]2  [8, 2]2  [9, 1]2 
    cout<<endl;
    set<vector<int>,decltype(customCompare2)*> customSet2(customCompare2);
    customSet2.insert({9,1,5});
    customSet2.insert({9,1});
    customSet2.insert({6,4});
    customSet2.insert({5,5});
    customSet2.insert({7,3});
    customSet2.insert({8,2});
    for (auto x : customSet2) {
        cout << x << ' ';
    }
    //o/p: [9, 1, 5]2  [8, 2]2  [7, 3]2  [6, 4]2  [5, 5]2 
    multiset<vector<int>,decltype(customCompare2)*> customSet3(customCompare2);
    customSet3.insert({9,1,3});
    customSet3.insert({6,4});
    customSet3.insert({9,1,7});
    customSet3.insert({5,5});
    customSet3.insert({5,5,-1});
    customSet3.insert({9,1,2});
    customSet3.insert({8,2});
    for (auto x : customSet3) {
        // cout << x << ' ';
    }// o/p: [9, 1, 3]3  [9, 1, 7]3  [9, 1, 2]3  [8, 2]2  [6, 4]2  [5, 5]2  [5, 5, -1]3  
    
}