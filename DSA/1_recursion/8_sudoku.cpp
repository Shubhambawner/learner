#include <bits/stdc++.h>
using namespace std;



vector<vector<bool>> boxes;
vector<vector<bool>> rows;
vector<vector<bool>> columns;

vector<vector<int>> temp;
vector<vector<vector<int>>> ans;
// row of current cell
int r = 0;
// column of current cell
int c = 0;

void setup(vector<vector<int>> initial)
{
    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            rows[r][initial[r][c]]=1;
            columns[c][initial[r][c]]=1;
            boxes[(r / 3) * 3 + (c / 3)][initial[r][c]]=1;
        }
    }
}

bool fill(int i)
{
    rows[r][i]=1;
    columns[c][i]=1;
    boxes[(r / 3) * 3 + (c / 3)][i]=1;
}
bool remove(int i)
{
    rows[r][i]=0;
    columns[c][i]=0;
    boxes[(r / 3) * 3 + (c / 3)][i]=0;
}
bool canFill(int i)
{
    return
    !rows[r][i] &&
    !columns[c][i] &&
    !boxes[(r / 3) * 3 + (c / 3)][i];
}

/*
for first occuring empty cell, choose a valid number to be placed, ( from 1 to 9 )
place it, and repeat for remaning cells.
if no empty cell left, sudoku solved!
*/
void sd()
{
    while (temp[r][c] != '.') // already filled with some number...
    {
        c++;
        if (c == 9)
        {
            c = 0;
            r++;
        }
    }
    if (r >= 9)
    {
        ans.push_back(temp);
        return;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (canFill(i))
        {
            fill(i);
            c++; if (c == 9){c = 0;r++;}
            sd();
            c--; if(c==-1){c=8;r--;}
            remove(i);
        }
    }
}

vector<vector<vector<int>>> sudoku(vector<vector<int>> initial)
{
    temp = initial;
    setup(initial); // set up rows columns boxes acc...
    sd();
    return ans;
}

int main()
{
}