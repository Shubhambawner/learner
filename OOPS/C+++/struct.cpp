// partinit.cpp
// shows initialization of structure variables
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
struct part //specify a structure
{
int modelnumber; //ID number of widget
int partnumber; //ID number of widget part
float cost; //cost of part
};
////////////////////////////////////////////////////////////////
int main()
{ //initialize variable
part part1 = { 6244, 373, 217.55F };
part part2; //define variable
//display first variable
cout << "Model " << part1.modelnumber;
cout << ", part " << part1.partnumber;
cout << ", costs $" << part1.cost << endl;
part2 = part1; //assign first variable to second
//display second variable
cout << "Model " << part2.modelnumber;
cout << ", part " << part2.partnumber;
cout << " , costs $"  << part2.cost << endl;
return 0;
}


/*
Model 6244, part 373, costs $217.55
Model 6244, part 373 , costs $217.55

This program defines two variables of type part: part1 and part2. It initializes part1, prints
out the values of its members, assigns part1 to part2, and prints out its members.

for multiple nested struct, we do:
part part1 = { 6244, 373, {6244, 373}, 217.55F };
and so on...
*/
