// SCAN DISK SCHEDULING ALGORITHM
#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
    int  h, i, n;

    cout << "enter the no of track requests to be traveresed: ";
    cin >> n;
    int t[n];
    cout << "enter the initial position of head: ";
    cin >> h;
   
    cout << "enter the track requests: ";
    for (i = 0; i <n ; i++)
    {
        cin >> t[i];
        
    }
    
    sort(t, t+n);

    cout<<"request hitting sequesnce: \n";
    for(i=0; i<n;i++){
        if(t[i]>=h) cout<<t[i]<<" ";
    }
    for(i=0; i<n;i++){
        if(t[i]<h) cout<<t[i]<<" ";
    }
    cout << "\ntotal header movements: " << 2*t[n-1] - h - t[0];
    cout << "avg is " << (float)(2*t[n-1] - h - t[0]) / n;
}