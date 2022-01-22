// TWO LEVEL DIRECTORY ORGANIZATION
#include <iostream>
#include <string.h>
using namespace std;
struct
{
    char nameD[10], nameF[10][10];
    int FCT;
} dir[10];
int main()
{
    int i, ch, dcnt, k;
    char f[30], d[30];

    dcnt = 0;
    while (1)
    {
        cout<<"\n\n1. Create Directory\t2. Create File\t3. Delete File";
cout<<"\n4. Search File\t\t5. Display\t6. Exit\tEnter your choice -- ";
cin>>ch;
switch(ch)
{
        case 1:
            cout<<"\nEnter name of directory -- ";
            cin>>dir[dcnt].nameD;
            dir[dcnt].FCT = 0;
            dcnt++;
            cout<<"Directory created";
            break;
        case 2:
            cout<<"\nEnter name of the directory -- ";
            cin>>d;
            for (i = 0; i < dcnt; i++)
                if (strcmp(d, dir[i].nameD) == 0)
                {
                    cout<<"Enter name of the file -- ";
                    cin>>dir[i].nameF[dir[i].FCT];
                    dir[i].FCT++;
                    cout<<"File created";
                    break;
                }
            if (i == dcnt)
                cout<<"Directory "<<d<<" not found";
            break;
        case 3:
            cout<<"\nEnter name of the directory -- ";
            cin>>d;
            for (i = 0; i < dcnt; i++)
            {
                if (strcmp(d, dir[i].nameD) == 0)
                {
                    cout<<"Enter name of the file -- ";
                    cin>>f;
                    for (k = 0; k < dir[i].FCT; k++)
                    {
                        if (strcmp(f, dir[i].nameF[k]) == 0)
                            
                            {
                                cout<<"File "<<f<<" is deleted ";
                                dir[i].FCT--;
                                strcpy(dir[i].nameF[k], dir[i].nameF[dir[i].FCT]);
                                goto jmp;
                            }
                    }
                    cout<<"File "<<f<<" not found";
                    goto jmp;
                }
            }
            cout<<"Directory "<<d<<" not found";
        jmp:
            break;
        case 4:
            cout<<"\nEnter name of the directory -- ";
            cin>>d;
            for (i = 0; i < dcnt; i++)
            {
                if (strcmp(d, dir[i].nameD) == 0)
                {
                    cout<<"Enter the name of the file -- ";
                    cin>>f;
                    for (k = 0; k < dir[i].FCT; k++)
                    {
                        if (strcmp(f, dir[i].nameF[k]) == 0)
                        {
                            cout<<"File "<<f<<" is found ";
                            goto jmp1;
                        }
                    }
                    cout<<"File "<<f<<" not found";
                    goto jmp1;
                }
            }
            cout<<"Directory "<<d<<" not found";
        jmp1:
            break;
        case 5:
            if (dcnt == 0)
                cout<<"\nNo Directory's ";
            else
            {
                cout<<"\nDirectory\tFiles";
                for (i = 0; i < dcnt; i++)
                {
                    cout<<"\n"<< dir[i].nameD<<"\t\t";
                    for (k = 0; k < dir[i].FCT; k++)
                        cout<<"\t"<<dir[i].nameF[k];
                }
            }
            break;
        default:
            break;
}
    }
}
