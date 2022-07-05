#include "./ru.cpp"

string padding = "\n";

void recurse()
{
    padding += "|  ";
    cout << padding << "recurse enter";
}

void returnRecurse(char a = ' ')
{

    cout << padding << "recurse end " << a;
    padding = padding.erase(padding.size() - 3);
}

template <class T>
void srint(T arr, int i = 0)
{
    cout << padding << "[";
    for (auto g = arr.begin(); g != arr.end(); ++g)
    {

        cout << *g << " ";
    }
    cout << "]   ";
}

// utility funnction to print a 2d iterative container vector<vector<int>> list<vector<int>> ...
template <class T>
void print(T arr, string label = "collection", int i = 0)
{
    cout << padding << label << ": " << arr.size();
    if (isAdvanced(arr))
    {
        cout << "[";
        padding += "   ";
        for (auto g = arr.begin(); g != arr.end(); ++g)
        {
            cout << padding;
            cout << i++ << ": " << g->size() << "[";
            for (auto it = (*g).begin(); it != (*g).end(); ++it)

            {
                cout << ", " << print(*it);
            }
            cout << " ]";
        }
        padding = padding.erase(padding.size() - 3);
        cout << padding << "]";
    }
    else
    {
        cout << arr;
    }
}

template <class T>
void print2(T arr, int i = 0)
{

    for (auto g = arr.begin(); g != arr.end(); ++g)
    {
        cout << padding;
        cout << i++ << ": [\n";
        for (auto it = (*g).begin(); it != (*g).end(); ++it)
        {
            cout << *it << " \n";
        }
        cout << "]";
    }
}

// utility funnction to print a 3d iterative container vector<vector<int>> list<vector<int>> ...
template <class T>
void trint(T arr, string label = "collection", int i = 0)
{
    cout << padding << label << ": " << arr.size() << "[";
    padding += "   ";
    for (auto g = arr.begin(); g != arr.end(); ++g)
    {
        print(*g, to_string(i++));
    }
    padding = padding.erase(padding.size() - 3);
    cout << padding << "]";
}

