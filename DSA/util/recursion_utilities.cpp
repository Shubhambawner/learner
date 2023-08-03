#include "./print_vardiac_function.cpp"

string unitSeperator = "|     ";
string enterArrow = "|-----";

// recurse enter _e()
template <typename T, typename... Types>
void _e(T functionName, Types... t)
{
    string fnName = (string)functionName+"() ";
    string enterSpace=spacing;

    if(enterSpace.size()>=unitSeperator.size()){ 
        enterSpace = enterSpace.erase(enterSpace.size() - unitSeperator.size());
        enterSpace+=enterArrow;
    }

    cout<<enterSpace<<fnName;
    spacing += unitSeperator;
    _w(t...);
}
void _e()
{
    spacing += unitSeperator;
    cout << spacing;
}


//b(): recurse exit/base case ; _e(args): recurse enter; _w(): print anything with current spacing
template <typename... Types>
void _b(Types... t)
{
    spacing = spacing.erase(spacing.size() - unitSeperator.size());
    _w(dep("return "), t...);
}
//b(): recurse exit/base case ; _e(args): recurse enter; _w(): print anything with current spacing
void _b()
{
    spacing = spacing.erase(spacing.size() - unitSeperator.size());
    _w(dep("return"));
}

//b(): recurse exit/base case ; _e(args): recurse enter; _w(): print anything with current spacing
#define _e(...) _e( __FUNCTION__ __VA_OPT__(,) __VA_ARGS__)
#define recurse _e
#define returnRecurse _b