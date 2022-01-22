#include <iostream>
#include <conio.h>
using namespace std;
void linked_Allocate(int memoryBlocksStorage[])
{
    int startingBlock, len;
    cout << "Enter the index of the starting Block and its length: ";
    cin >> startingBlock >> len;
    int k = len;
    if (memoryBlocksStorage[startingBlock] == 0)
    {
        for (int j = startingBlock; j < (startingBlock + k); j++)
        {
            if (memoryBlocksStorage[j] == 0)
            {
                memoryBlocksStorage[j] = 1;
                cout << j << "------>" << memoryBlocksStorage[j] << endl;
            }
            else
            {
                cout << "The block " << j << " is already allocated" << endl;
                k++;
            }
        }
    }
    else
        cout << "The block " << startingBlock << " is already allocated" << endl;
    cout << "Do you want to enter more files?" << endl;
    cout << "Enter 1 for Yes, Enter 0 for No: ";
    int c;
    cin >> c;
    if (c == 1)
        linked_Allocate(memoryBlocksStorage);
    
    return;
}
int main()
{
    int  p, a, memorySize;
    cout << "Enter the number of blocks already allocated: ";
    cin >> p;
    cout << "Enter the Memory size(in blocks) ";
    cin >> memorySize;
    int memoryBlocksStorage[memorySize] = {0};
    cout << "Enter the blocks already allocated: ";
    for (int i = 0; i < p; i++)
    {
        cin >> a;
        memoryBlocksStorage[a] = 1;
    }
    linked_Allocate(memoryBlocksStorage);
    return 0;
}