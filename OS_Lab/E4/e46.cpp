// LRU PAGE REPLACEMENT ALGORITHM
#include <iostream>
using namespace std;
int main()
{
    int i, j, k, min, rs[25], m[10], count[10], flag[25], n, f, pf = 0, next = 1;

    cout << "Enter the length of reference string -- ";
    cin >> n;
    cout << "Enter the reference string -- ";
    for (i = 0; i < n; i++)
    {
        cin >> rs[i];
        flag[i] = 0;
    }
    cout << "Enter the number of frames -- ";
    cin >> f;
    for (i = 0; i < f; i++)
    {
        count[i] = 0;
        m[i] = -1;
    }
    cout << "\nThe Page Replacement process is LRU -- \n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < f; j++)
        {
            if (m[j] == rs[i])
            {
                flag[i] = 1;

                count[j] = next;
                next++;
            }
        }
        if (flag[i] == 0)
        {
            if (i < f)
            {
                m[i] = rs[i];
                count[i] = next;
                next++;
            }
            else
            {
                min = 0;
                for (j = 1; j < f; j++)
                    if (count[min] > count[j])
                        min = j;
                m[min] = rs[i];
                count[min] = next;
                next++;
            }
            pf++;
        }
        for (j = 0; j < f; j++)
            cout << "\t"<< m[j];
        if (flag[i] == 0)
            cout << "\tPF No. -- "<< pf;
        cout << "\n";
    }
    cout << "\nThe number of page faults using LRU are "<< pf;
}