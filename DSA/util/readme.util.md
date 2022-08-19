# print_stl_operator_overloaded
function: overloads << os stream operator for printing all kinds of stl containers, if nested identifies the nesting and prints inner containers recursively
* feature: includes string **spacing**, that is also modified by recursive function
todo: cant print those initialised with custom compare functions, 
so, containers like : set<int, decltype(somefunction)*> cant be printed yet

# print_vardiac_function
function: w() prints anything and everything that is passed inn, space separated, after **spacing**


# recursion_utilities
functions:
recurse() : increments spacing, prints the beginning of fn call
returnrecurse() : decrements spacing, prints end of fn call

----------------------------------------------------------------