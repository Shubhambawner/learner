#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int n, m[20], i, j, sb[20], s[20], b[20][20], x;

    cout << "Enter no. of files: ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "Enter starting block and size of file " << i + 1 << " : ";
        cin >> sb[i] >> s[i];
        cout << "Enter blocks occupied by file " << i + 1 << " :";
        cin >> m[i];
        cout << "enter blocks of file " << i + 1 << " :";
        for (j = 0; j < m[i]; j++)
            cin >> b[i][j];
    }
    cout << "File"
         << "\t"
         << "index"
         << "\t"
         << "length" << endl;
    for (i = 0; i < n; i++)
    {
        cout << i + 1 << "\t" << sb[i] << "\t" << m[i] << endl;
    }
    cout << "\nEnter file name: ";
    cin >> x;
    cout << "file name is: " << x << endl;
    i = x - 1;
    cout << "Index is: " << sb[i];
    cout << "Block occupied are: ";
    for (j = 0; j < m[i]; j++)
        cout << b[i][j];
}