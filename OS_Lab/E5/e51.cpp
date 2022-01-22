#include <iostream>
#include <vector>
using namespace std;

void Print(vector<int> fr)
{
    int n = fr.size();
    for (int i = 0; i < n; i++)
    {
        cout << fr[i] << " |";
    }
    cout << "|\n";
}

int predict(int page[], vector<int> &fr, int pn, int index)
{
    // Store the index of pages which are going
    // to be used recently in future
    int res = -1, farthest = index;
    for (int i = 0; i < fr.size(); i++)
    {
        int j;
        for (j = index; j < pn; j++)
        {
            if (fr[i] == page[j])
            {
                if (j > farthest)
                {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        // Return the page which are
        // are never referenced in future,
        if (j == pn)
            return i;
    }
    // If all of the frames were not in future,
    // return any of them, we return 0. Otherwise
    // we return res.
    return (res == -1) ? 0 : res;
}
bool search(int key, vector<int> &fr)
{
    for (int i = 0; i < fr.size(); i++)
        if (fr[i] == key)
            return true;
    return false;
}
void opr(int page[], int pn, int fn)
{
    // Create an array for given number of
    // frames and initialize it as empty.
    vector<int> fr;
    int hit = 0;

    // Traverse through page reference array
    // and check for miss and hit.
    for (int i = 0; i < pn; i++)
    {
        cout << "----------------------------------------------------------------------\n";

        cout << "Frames status: \t";
        Print(fr);
        cout << "request for page no.: " << page[i] << "\n";

        // increment HIT if Page found in a frame
        if (search(page[i], fr))
        {
            hit++;
            cout << "it's a hit!\n";
            continue;
        }

        // If a page not found in a frame its a miss
        cout << "it's a miss!\n";

        //  check if there is space available in frames.
        if (fr.size() < fn)
        {
            fr.push_back(page[i]);
            cout << "page inserted at " << fr.size() << "\n";
        }
        // Find the page to be replaced.
        else
        {
            int j = predict(page, fr, pn, i + 1);
            cout << "page inserted at " << j << "\n";
            fr[j] = page[i];
        }
    }
    cout << "----------------------------------------------------------------------\n";
    cout << "Hits = " << hit << endl;
    cout << "Misses = " << pn - hit << endl;
}

// main Function
int main()
{
    cout << "page fault optimisation algorithm: \n\n";
    cout << "input the number of page requests--";
    int n;
    cin >> n;
    int page[n];
    cout << "\ninput the integer array of page requests: \n";

    int i = 0;
    while (n > i)
    {
        cin >> page[i];
        i++;
    }

    cout << "input the numbr of frames--";

    int fn;
    cin >> fn;

    //
    opr(page, n, fn);
    return 0;
}