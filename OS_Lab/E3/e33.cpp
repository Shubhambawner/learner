// WORST-FIT
#include <iostream>
using namespace std;


int main()
{
    int Fragment[25], b[25], f[25], i, j, nb, nf, temp, high = 0;
    static int bf[25], ff[25];

    cout<<"\n\tMemory Management Scheme - Worst Fit";
    cout<<"\nEnter the number of blocks:";
    cin>>nb;
    cout<<"Enter the number of files:";
    cin>>nf;
    cout<<"\nEnter the size of the blocks:-\n";
    for (i = 1; i <= nb; i++)
    {
        cout<<"Block "<<i<<":";
        cin>>b[i];
    }
    cout<<"Enter the size of the files :-\n";
    for (i = 1; i <= nf; i++)
    {
        cout<<"File "<<i<<":";
        cin>>f[i];
    }
    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1) // if bf[j] is not allocated
            {
                temp = b[j] - f[i];
                if (temp >= 0)
                    if (high < temp)
                    {
                        ff[i] = j;
                        high = temp;
                    }
            }
        }
        Fragment[i] = high;
        bf[ff[i]] = 1;
        high = 0;
    }
    cout<<"\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragment";
    for (i = 1; i <= nf; i++)
        cout<<"\n"<<i<<"\t\t"<<f[i]<<"\t\t"<<ff[i]<<"\t\t"<<b[ff[i]]<<"\t\t"<<Fragment[i]<<"\n";
}

