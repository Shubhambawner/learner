// FCFS
#include <iostream>
using namespace std;
int main()
{
    float avhm;
    int n;
    cout << "enter the number of requests: ";
    cin >> n;
    int t[n], T[n], i, tot = 0, h;
    cout << "enter the initial position of head: ";
    cin >> h;

    cout << "enter all the track requests to be traversed: ";
    for (i = 0; i < n; i++)
    {
        cin >> t[i];
        if (i != 0)
        {
            T[i] = abs(t[i] - t[i - 1]);
            tot += T[i];
        }
    }
    T[0] = abs(h - t[0]);
    tot += T[0];

    cout << "Track rquest traversed\t\ttDifference between tracks\n";
    for (i = 0; i < n; i++)
        cout << t[i] << "\t\t\t\t " << T[i] << "\n";
    avhm = (float)tot / n;
    cout << "\nAverage header movements: " << avhm;
}