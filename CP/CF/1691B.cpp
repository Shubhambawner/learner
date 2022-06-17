#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, vector<int>> o;
        for (int a = 0; a < n; a++)
        {
            int size = 0;
            cin >> size;
            o[size].push_back(a + 1);
        }
        bool it = false;
        for (auto i = o.begin(); i != o.end(); i++)
        {
            if (i->second.size() == 1)
            {
                it = true;
                cout<<"-1\n";
                break;
            }
            int temp = i->second[i->second.size() - 1];
            for (int j = i->second.size() - 1; j >= 0; j--)
            {
                i->second[j] = i->second[j - 1];
            }
            i->second[0] = temp;
        }
        if (!it)
        {
            for (auto i : o)
            {
                for (auto j : i.second)
                {
                    cout << j << " ";
                }
            }
            cout << "\n";
        }
    }
}