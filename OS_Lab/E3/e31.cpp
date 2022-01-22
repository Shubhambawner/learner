//first fit
#include<iostream>
using namespace std;

int main()
{
    //let the max. size be 25
    int fragment[25], b[25], f[25], i, j, nb, nf, temp;
    int bf[25], arrF[25];

    cout << "\n\tMemory Management Scheme - First Fit";
    cout << "\nEnter the number of blocks:";
    cin>>nb;
    cout << "Enter the number of files:";
    cin>>nf;
    cout << "\nEnter the size of the blocks:-\n";
    for (i = 1; i <= nb; i++)
    {
        cout<<"Block :"<<i;
        cin>>b[i];
    }
    cout << "Enter the size of the files :-\n";
    for (i = 1; i <= nf; i++)
    {
        cout << "File :"<<i;
        cin>>f[i];
    }
    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1)
            {
                temp = b[j] - f[i];
                if (temp >= 0)
                {
                    arrF[i] = j;
                    break;
                }
            }
        }

        fragment[i] = temp;
        bf[arrF[i]] = 1;
    }
    cout << "\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragment";
    for (i = 1; i <= nf; i++)
    cout<<"\n"<<i<<"\t\t"<<f[i]<<"\t\t"<<arrF[i]<<"\t\t"<<b[arrF[i]]<<"\t\t"<<fragment[i]<<"\n";
}
