//PROGRAM
#include <iostream>
using namespace std;
int P_number, Philosopher_ID[20],  P_Hungry, hu[20], c;
void one();
void two();
main()
{
    int status[20],i;
    
    cout<<"\n\nDINING PHILOSOPHER PROBLEM";
    cout<<"\nEnter the total no. of philosophers: ";
    cin>>P_number;
    for (i = 0; i < P_number; i++)
    {
        Philosopher_ID[i] = (i + 1);
        status[i] = 1;
    }
    cout<<"How many are hungry : ";
    cin>>P_Hungry;
    if (P_Hungry == P_number)
    {
        cout<<"\nAll are hungry..\nDead lock stage will occur";
        cout<<"\nExiting..";
    }
    else
    {
        for (i = 0; i < P_Hungry; i++)
        {
            cout<<"Enter the philosopher "<<(i + 1)<<"'s position : " ;
            cin>>hu[i];
            status[hu[i]] = 2;
        }
        do
        {
            cout<<"1.One can eat at a time\t2.Two can eat at a time\t3.Exit\nEnter your choice:";
            cin>>c;
            switch (c)
            {
            case 1:
                one();
                break;
            case 2:
                two();
                break;
            case 3:
                exit(0);
            default:
                cout<<"\nInvalid option..";
            }
            
        } while (1);
    }
}
void one()
{
    int pos = 0, x, i;
    cout<<"\nAllow one philosopher to eat at any time\n";
    for (i = 0; i < P_Hungry; i++, pos++)
    {
        cout<<"\nP "<<Philosopher_ID[hu[pos]]<<" is granted to eat" ;
        for (x = pos; x < P_Hungry; x++)
            cout<<"\nP "<<Philosopher_ID[hu[x]]<<" is waiting" ;
    }
}
void two()
{
    int i, j, s = 0, t, r, x;
    cout<<"\n Allow two philosophers to eat at same time\n";
    for (i = 0; i < P_Hungry; i++)
    {
        for (j = i + 1; j < P_Hungry; j++)
        {
            if (abs(hu[i] - hu[j]) >= 1 && abs(hu[i] - hu[j]) != 4)
            {
                cout<<"\n\ncombination "<<(s + 1)<<" \n" ;
                t = hu[i];
                r = hu[j];
                s++;
                cout<<"\nP "<<Philosopher_ID[hu[i]]<<" and P "<<Philosopher_ID[hu[j]]<<" are granted to eat";
                for (x = 0; x < P_Hungry; x++)
                {
                    if ((hu[x] != t) && (hu[x] != r))
                        cout<<"\nP "<< Philosopher_ID[hu[x]]<<" is waiting";
                }
            }
        }
    }
}
