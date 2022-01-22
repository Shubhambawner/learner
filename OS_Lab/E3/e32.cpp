//best fit
#include <iostream>
using namespace std;

int main()
{
    int Fragment[25], b[25], f[25], i, j, nb, nf, temp, low = 10000;
    int bf[25], arrF[25];

    cout << "\nFile system: best fit";
    cout << "\nEnter the number of blocks:";
    cin >> nb;
    cout << "Enter the number of files:";
    cin >> nf;
    cout << "\nEnter the size of the blocks:-\n";
    for (i = 1; i <= nb; i++)
        {cout << "Block " << i << ":";
    cin >> b[i];}
    cout << "Enter the size of the files :-\n";
    for (i = 1; i <= nf; i++)
    {
        cout << "File " << i << ":";
        cin >> f[i];
    }
    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1)
            {
                temp = b[j] - f[i];
                if (temp >= 0)
                    if (low > temp)
                    {
                        arrF[i] = j;

                        low = temp;
                    }
            }
        }
        Fragment[i] = low;
        bf[arrF[i]] = 1;
        low = 10000;
    }
    cout << "\nFile No\tFile Size \tBlock No\tBlock Size\tFragmentment";
    for (i = 1; i <= nf && arrF[i] != 0; i++)
        cout << "\n"
             << i << "\t\t" << f[i] << "\t\t" << arrF[i] << "\t\t" << b[arrF[i]] << "\t\t" << Fragment[i] << "";
}