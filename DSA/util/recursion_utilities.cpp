#include "./print_vardiac_function.cpp"
#include "./depricated.cpp"

string unitSeperator = "|     ";
string enterArrow = "|-----";

// recurse enter e()
template <typename T, typename... Types>
void e(T functionName, Types... t)
{
    string fnName = (string)functionName+"() ";
    string enterSpace=spacing;

    if(enterSpace.size()>=unitSeperator.size()){ enterSpace = enterSpace.erase(enterSpace.size() - unitSeperator.size());
    enterSpace+=enterArrow;}

    cout<<enterSpace<<fnName;
    spacing += unitSeperator;
    w(t...);
}
void e()
{
    spacing += unitSeperator;
    cout << spacing;
}


//b(): recurse exit/base case ; e(args): recurse enter; w(): print anything with current spacing
template <typename... Types>
void b(Types... t)
{
    spacing = spacing.erase(spacing.size() - unitSeperator.size());
    w(dep("return "), t...);
}
//b(): recurse exit/base case ; e(args): recurse enter; w(): print anything with current spacing
void b()
{
    spacing = spacing.erase(spacing.size() - unitSeperator.size());
    w(dep("return"));
}

//b(): recurse exit/base case ; e(args): recurse enter; w(): print anything with current spacing
#define e(...) e( __FUNCTION__ __VA_OPT__(,) __VA_ARGS__)
#define recurse e
#define returnRecurse b