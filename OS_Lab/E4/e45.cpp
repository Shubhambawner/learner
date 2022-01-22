// FIFO PAGE REPLACEMENT ALGORITHM
#include <iostream>
using namespace std;
int main()
{
    int i, j, k, f, pf = 0, count = 0, rs[25], m[10], n;

    cout << "\n Enter the length of reference string -- ";
    cin >> n;
    cout << "\n Enter the reference string -- ";
    for (i = 0; i < n; i++)
        cin >> rs[i];
    cout << "\n Enter no. of frames -- ";
    cin >> f;
    for (i = 0; i < f; i++)
        m[i] = -1;
    cout << "\n The Page Replacement Process is FIFO-- \n";
    for (i = 0; i < n; i++)
    {
        for (k = 0; k < f; k++)
        {
            if (m[k] == rs[i])
                break;
        }
        if (k == f)
        {
            m[count++] = rs[i];
            pf++;
        }
        for (j = 0; j < f; j++)
            cout << "\t"<< m[j];
        if (k == f)
            cout << "\tPF No. "<< pf;
        cout << "\n";
        if (count == f)
            count = 0;
    }
    cout << "\n The number of Page Faults using FIFO are "<< pf;
}