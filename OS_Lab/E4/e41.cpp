#include <iostream>
using namespace std;

//this data structure will store all processes data
struct Process
{
    //let max. number of resources be 10
    int all[10];
    int max[10];
    int need[10];
    int flag;
};
int main()
{
    
    int i, j, k, p, b, n, r, g, cnt = 0, id, newr;
    cout << "Enter number of processes -- ";
    cin >> n;

    struct Process f[n];
    int fl;
    //this will store all data of initially available resources
    int Avail[10], seq[10];

    cout << "Enter number of resources  -- ";
    cin >> r;
    for (i = 0; i < n; i++)
    {
        cout << "Enter details for Process P"<<i<<" ";
        cout << "\nEnter initial resource allocation\t -- \n";
        for (j = 0; j < r; j++){
            cout<<"units of resource R"<<j+1<<" alloted initially : ";
            cin >> f[i].all[j];}
        cout << "Enter Maximum units of resources needed by process:\t -- \n";
        for (j = 0; j < r; j++)
           { cout<<"for resource R"<<j<<"\t";
               cin >> f[i].max[j];}
        f[i].flag = 0;
    }
    cout << "\nEnter Resources Available at beginning: \t -- \n";
    for (i = 0; i < r; i++){
        cout<<"units of resource R"<<i<<" Available initially : ";
        cin >> Avail[i];}
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            f[i].need[j] = f[i].max[j] - f[i].all[j];
            if (f[i].need[j] < 0)
                f[i].need[j] = 0;
        }
    }
    cnt = 0;
    fl = 0;
    while (cnt != n)
    {
        g = 0;
        for (j = 0; j < n; j++)
        {
            if (f[j].flag == 0)
            {
                b = 0;
                for (p = 0; p < r; p++)
                {
                    if (Avail[p] >= f[j].need[p])
                        b = b + 1;
                    else
                        b = b - 1;
                }
                if (b == r)
                {
                    cout << "\nP"<<j<<" is visited";
                    seq[fl++] = j;
                    f[j].flag = 1;
                    for (k = 0; k < r; k++)
                        Avail[k] = Avail[k] + f[j].all[k];
                    cnt = cnt + 1;
                    cout << "(";
                    for (k = 0; k < r; k++)
                        cout <<  Avail[k];
                    cout << ")";
                    g = 1;
                }
            }
        }
        if (g == 0)
        {
            cout << "\n REQUEST NOT GRANTED -- DEADLOCK OCCURRED";
            cout << "\n SYSTEM IS IN UNSAFE STATE";
            goto y;
        }
    }
    cout << "\nSYSTEM IS IN SAFE STATE";
    cout << "\nThe Safe Sequence is -- (";
    for (i = 0; i < fl; i++)
        cout << "P"<<seq[i]<<" " ;
    cout << ")";
y:
    cout << "\nProcess\t\tAllocation\t\tMax\t\t\tNeed\n";
    for (i = 0; i < n; i++)
    {
        cout << "P"<<i<<"\t";
        for (j = 0; j < r; j++)
            cout << f[i].all[j]<<"\t\t";
        for (j = 0; j < r; j++)
            cout << f[i].max[j]<<"\t\t";
        for (j = 0; j < r; j++)
            cout << f[i].need[j]<<"\t\t";
        cout << "\n";
    }
}

/*
Enter number of processes -- 2
Enter number of resources  -- 2
Enter details for Process P0 
Enter initial resource allocation        -- 
units of resource R1 alloted initially : 0  
units of resource R2 alloted initially : 1
Enter Maximum units of resources needed by process:      -- 
for resource R0 1
for resource R1 1
Enter details for Process P1 
Enter initial resource allocation        -- 
units of resource R1 alloted initially : 1  
units of resource R2 alloted initially : 0
Enter Maximum units of resources needed by process:      -- 
for resource R0 1
for resource R1 1

Enter Resources Available at beginning:          --
units of resource R0 Available initially : 0 0
units of resource R1 Available initially : 
 REQUEST NOT GRANTED -- DEADLOCK OCCURRED
 SYSTEM IS IN UNSAFE STATE
Process         Allocation              Max                     Need
P0      0       1       1       1       1       0
P1      1       0       1       1       0       1
**/