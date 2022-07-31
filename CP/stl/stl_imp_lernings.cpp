#include "../../DSA/util/recursion_utilities.cpp"
using namespace std;

int main()
{
    // //! in multi-set, if 2 elements are equal, they apear in order they were inserted

    // multiset<int> s;
    // s.insert(2);

    // s.insert(2);
    // auto a = ++s.begin();
    // s.insert(2);
    // // output 2
    // if (a == s.begin())
    //     cout << 1;
    // if (a == ++s.begin())
    //     cout << 2;
    // if (a == ++ ++s.begin())
    //     cout << 3;

    // cout << endl;

    // //! in multiset find() returns first occurance of element
    // multiset<int> d;
    // d.insert(1);
    // d.insert(2);
    // d.insert(2);
    // d.insert(2);
    // auto w = d.find(2);
    // // output 1'
    // if (w == d.begin())
    //     cout << 1;
    // else if (w == ++d.begin())
    //     cout << 2;
    // else if (w == ++ ++d.begin())
    //     cout << 3;
    // else if (w == ++ ++ ++d.begin())
    //     cout << 4;

    // //! de referancing end() may leed to undesired consequences( like, trash value or SIGSEV)
    // //! so, for finding a count of elements in multimap,
    // //! do check if its not null, if null count is 0
    // cout << endl;
    // //? wrong way:
    // cout << "no. of 100s in d is: "<< d.count(*d.find(100)) << endl;
    // //* correct:
    // cout << "no. of 100s in d is: " 
    //     << (d.find(100) != d.end()) ? d.count(*d.find(100)) : 0;
    
    //     //OR
    // int count100 = (d.find(100) != d.end()) ? d.count(*d.find(100)) : 0;
    //     //NOT 
    //     // int count100 = d.count(*d.find(100));
    // cout << endl;
     if(false)
     if(true) cout<<1;
     else cout<<2;
}