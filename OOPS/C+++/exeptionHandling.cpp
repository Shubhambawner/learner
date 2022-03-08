// xdist2.cpp
// exceptions with arguments
#include <iostream>
#include <string>
using namespace std;
////////////////////////////////////////////////////////////////
class myError
{
    int v = 0;

public:
    myError()
    {
    }
};
class Distance // English Distance class
{
private:
    int feet;
    float inches;

public:
    //--------------------------------------------------------------
    class InchesEx // exception class
    {
    public:
        string origin;                  // for name of routine
        float iValue;                   // for faulty inches value
        InchesEx(string jor, float jin) // 2-arg constructor
        {
            origin = jor; // store string
            iValue = jin; // store inches
        }
    }; // end of exception class
    //--------------------------------------------------------------
    Distance() // constructor (no args)
    {
        feet = 0;
        inches = 0.0;
    }
    //--------------------------------------------------------------
    Distance(int ft, float in) // constructor (two args)
    {
        if (in >= 12.0)
            throw InchesEx("2-arg constructor", in);
        feet = ft;
        inches = in;
    }
    //--------------------------------------------------------------
    void getdist() // get length from user
    {
        cout << "\nEnter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
        if (inches >= 12.0)
            throw InchesEx("getdist() function", inches);
        if (inches == 1)
        {
            throw myError();
        }
        if (inches == 2)
        {
            throw Distance(this->feet, this->inches);
        }
    }
    //--------------------------------------------------------------
    void showdist() // display distance
    {
        cout << feet << "\'-" << inches << "\"";
    }
};
////////////////////////////////////////////////////////////////
int main()
{
    int a = 4;
    while (a-- > 0)
    {
        try
        {
            Distance dist1(17, 3.5); // 2-arg constructor
            Distance dist2;          // no-arg constructor
            dist2.getdist();         // get value
            // display distances
            cout << "\ndist1 = ";
            dist1.showdist();
            cout << "\ndist2 = ";
            dist2.showdist();
        }
        catch (Distance::InchesEx ix) // exception handler
        {
            cout << "\nCongragulations! Initialization error in " << ix.origin
                 << ".\n Inches value of " << ix.iValue
                 << " is too large.";
        }
        catch (myError j)
        {
            cout << "\n cought error from other class!! \n"
                 << '\n';
        }
        catch (Distance d)
        {
            cout << "\n object creating exeption itself thrown as exeption!! \n";
        }
        cout << "\n didn't this code execute? Yes it did!! ";
        // cout<<"\n if there were no errors thrown, object creatd is: ";dist1.showdist();------ cant access members outside any block{}
    }
    cout << "\n did'nt this code execute? NO IT DID'NT!! \n";

    return 0;
}
/*
TAKE AWAY:
* error handling exclusively used when using classes, libraries of functions.
* controll flow of try blok breaks at first exeption being thrown, and catch is
  executed, proceding to code out of try-catch bloks, not breaking off the program.
* throw just throws some object to the catch blok, it can be any object that is accessible
  (here exeption is an object of nested class inside the class throwing error, it may be object of
  some other class or same class as well!  )
* TRY CATCH CAN be placed in a loop as well!!
*/

/*

Enter feet: 1
Enter inches: 1

 cought error from other class!!


 didn't this code execute? Yes it did!!
Enter feet: 1
Enter inches: 2

 object creating exeption itself thrown as exeption!!

 didn't this code execute? Yes it did!!
Enter feet: 1
Enter inches: 3

dist1 = 17'-3.5"
dist2 = 1'-3"
 didn't this code execute? Yes it did!!
Enter feet: 1
Enter inches: 13

Congragulations! Initialization error in getdist() function.
 Inches value of 13 is too large.
 didn't this code execute? Yes it did!!
 did'nt this code execute? NO IT DID'NT!!

*/