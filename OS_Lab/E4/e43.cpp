// C-SCAN DISK SCHEDULING ALGORITHM
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int h, i, n;

    cout << "enter the no of track requests to be traveresd: ";
    cin >> n;
    int t[n];
    cout << "enter the initial position of head: ";
    cin >> h;

    cout << "enter the track requests: ";
    for (i = 0; i < n; i++)
    {
        cin >> t[i];
        
    }

    sort(t, t + n);

    cout << "request hitting sequence: \n";
    for (i = 0; i < n; i++)
    {
        if (t[i] >= h)
        {
            cout << t[i] << " ";
            
        }
    }
    int Min = t[0];
    for (i = n - 1; i >= 0; i--)
    {
        if (t[i] < h)
            {
                Min = min(h-Min, h-t[i]);
                cout << t[i] << " ";}
    }
    cout << "\ntotal header movements: " << t[n-1] - (h - Min);
    cout << "avg is " << (float)(t[n-1] - (h - Min))/ n;
}