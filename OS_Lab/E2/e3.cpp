#include <iostream>
#include <conio.h>
#include <map>
using namespace std;
int main()
{
    int n, m[20], i, j,  s[20],  x, memory_size;
    map<string, int> DirectoryFileTable;  // maping of names to index block adresses
    cout << "Enter no. of files: ";
    cin >> n;
    cout << "Enter no. of storage blocks (memory size): ";
    cin >> memory_size;
    int storageBlocksMemory[memory_size][20];
    //let each block of memory be able to hold 20 adresses(iff became an index block)

    for (i = 0; i < n; i++)
    {
        cout << "Enter Name of file: "<<i+1<<" ";
        string fileName = "";
        cin>>fileName;
        cout << "Enter adress of index block block of file: "<<fileName<<" ";
        cin >> DirectoryFileTable[fileName]; 
        // Directory File Table stores name and adress to index block of file mapped together
        cout << "Enter number of blocks occupied by file: ";
        cin >> m[i];
        cout << "enter blocks of file: ";
        for (j = 0; j < m[i]; j++)
            cin >> storageBlocksMemory[DirectoryFileTable[fileName]][j]; 
            //index block to store adress of all memory blocks
    }
    cout << "File"
         << "\t"
         << "index"
         << "\t"
         << "length" << endl;
    auto DirectoryPointer = DirectoryFileTable.begin();
    for (i = 0; i < n; i++, DirectoryPointer++)
    {
        cout << DirectoryPointer->first << "\t" << DirectoryPointer->second << "\t" << m[i]<<"\n";
    }
    cout << "\nEnter file name: ";
    string xy;
    cin >> xy;
    if(DirectoryFileTable[xy]){
    cout << "file name is: " << xy;
    cout << "\nIndex block location is: " << DirectoryFileTable[xy];
     i =DirectoryFileTable[xy];
    cout << "\nBlock occupied are: ";
    for (j = 0; j < m[i]; j++)
    {
        cout << storageBlocksMemory[i][j]<<",\t";
    }
    }
    else{
        cout << "No file found\n";
    }
   
    return 0;
}