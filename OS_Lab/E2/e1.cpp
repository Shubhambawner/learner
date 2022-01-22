// SEQUENTIAL FILE ALLOCATION
#include <iostream>
#include <string.h>
using namespace std;

struct fileTable
{
    char name[20]; 
    //name of directory can't be larger than 20 char!
    int sb, nob;
} DirectoryFileTable[30];

int main()
{
    int i, j, n;
    char s[20];

    cout<<"Enter no of files :";
    cin>>n;
    for (i = 0; i < n; i++)
    {
        //here we are asuming that data is valid, i.e. files wont overlap, as 
        //verificaton algorithms are out of scope. 
        cout<<"\nEnter file name "<<i + 1<<" :" ;
        cin>>DirectoryFileTable[i].name;
        cout<<"Enter starting block of file "<<i + 1<<" :" ;
        cin>>DirectoryFileTable[i].sb;
        cout<<"Enter no of blocks in file "<<i + 1<<" :" ;
        cin>>DirectoryFileTable[i].nob;
    }
    cout<<"\nEnter the file name to be searched-- ";
    cin>>s;
    for (i = 0; i < n; i++)
        if (strcmp(s, DirectoryFileTable[i].name) == 0) break;
    if (i == n)
        cout<<"\nFile Not Found";
    else
    {
        cout<<"\nFILE NAME\tSTART BLOCK\tNO OF BLOCKS";
        cout<<"\n"<<DirectoryFileTable[i].name
            <<"\t\t"<<DirectoryFileTable[i].sb<<"\t\t"
            <<DirectoryFileTable[i].nob<<"\n" ;
        cout<<"\nBLOCKS OCCUPIED:\n";
        for (j = 0; j < DirectoryFileTable[i].nob; j++)
            cout<<DirectoryFileTable[i].sb + j<<", ";
    }
    
}