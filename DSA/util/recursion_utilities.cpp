#include "./ru.cpp"

void recurse()
{
    spacing += "|  ";
    cout << spacing << "recurse enter";
}

void returnRecurse(char a = ' ')
{

    cout << spacing << "recurse end " << a;
    spacing = spacing.erase(spacing.size() - 3);
}

// depricated: utility funnction to print a 2d iterative container vector<vector<int>> list<vector<int>> ...
// can print it all directly, << got overloaded!
template <class T>
void srint(T arr, int i = 0)
{
    cout << spacing << "[" << arr << "]   ";
}

// depricated: utility funnction to print a 2d iterative container vector<vector<int>> list<vector<int>> ...
// can print it all directly, << got overloaded!
template <class T>
void print(T arr, string label = "collection", int i = 0)
{
    cout << spacing << label << ": " << arr.size();
    if (isAdvanced(arr))
    {
        cout << "[";
        spacing += "   ";
        for (auto g = arr.begin(); g != arr.end(); ++g)
        {
            cout << spacing;
            cout << i++ << ": " << g->size() << "[";
            for (auto it = (*g).begin(); it != (*g).end(); ++it)

            {
                cout << ", " << print(*it);
            }
            cout << " ]";
        }
        spacing = spacing.erase(spacing.size() - 3);
        cout << spacing << "]";
    }
    else
    {
        cout << arr;
    }
}

// depricated: utility funnction to print a 3d iterative container vector<vector<int>> list<vector<int>> ...
// can print it all directly, << got overloaded!
template <class T>
void print2(T arr, int i = 0)
{

    for (auto g = arr.begin(); g != arr.end(); ++g)
    {
        cout << spacing;
        cout << i++ << ": [\n";
        for (auto it = (*g).begin(); it != (*g).end(); ++it)
        {
            cout << *it << " \n";
        }
        cout << "]";
    }
}

// depricated: utility funnction to print a 3d iterative container vector<vector<int>> list<vector<int>> ...
// can print it all directly, << got overloaded!
template <class T>
void trint(T arr, string label = "collection", int i = 0)
{
    cout << spacing << label << ": " << arr.size() << "[";
    spacing += "   ";
    for (auto g = arr.begin(); g != arr.end(); ++g)
    {
        print(*g, to_string(i++));
    }
    spacing = spacing.erase(spacing.size() - 3);
    cout << spacing << "]";
}

