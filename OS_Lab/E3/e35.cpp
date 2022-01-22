// SINGLE LEVEL DIRECTORY ORGANIZATION
#include <iostream>
#include <string.h>
using namespace std;
struct
{
    char nameD[10], nameF[10][10];
    int FCT;
} dir;
int main()
{
    int i, ch;
    char f[30];

    dir.FCT = 0;
    cout<<"\nEnter name of directory -- ";
    cin>> dir.nameD;
    while (1)
    {
cout<<"\n\n1. Create File\t2. Delete File\t3. Search File \n4. Display Files\t5. Exit\nEnter your choice -- ";
cin>>ch;
switch(ch)
{
        case 1:
            cout<<"\nEnter the name of the file -- ";
            cin>> dir.nameF[dir.FCT];
            dir.FCT++;
            break;
        case 2:
            cout<<"\nEnter the name of the file -- ";
            cin>> f;
            for (i = 0; i < dir.FCT; i++)
            {
                if (strcmp(f, dir.nameF[i]) == 0)
                {
                    cout<<"File "<<f<<" is deleted " ;
                    strcpy(dir.nameF[i], dir.nameF[dir.FCT - 1]);
                    break;
                }
            }
            if (i == dir.FCT)
                cout<<"File "<<f<<" not found";
            else dir.FCT--;
            break;
        case 3:
            cout<<"\nEnter the name of the file -- ";
            cin>> f;
            for (i = 0; i < dir.FCT; i++)
            {
                if (strcmp(f, dir.nameF[i]) == 0)
                {
                    cout<<"File "<<f<<" is found ";
                    break;
                }
            }
            if (i == dir.FCT)
                cout<<"File "<<f<<" not found";
            break;
        case 4:
            if (dir.FCT == 0)
                cout<<"\nDirectory Empty";
            else
            {
                cout<<"\nThe Files are -- ";
                for (i = 0; i < dir.FCT; i++)
                    cout<<"\t"<<dir.nameF[i]<<"\n" ;
            }
            break;
        default:
            break;
}
    }
}
