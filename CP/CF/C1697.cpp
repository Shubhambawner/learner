#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int cl[8]={0}, clm = 0; 
        for(int i = 0; i<8; i++){
            for(int j = 0; j<8; j++){
                char c;cin>>c;
                if(c=='#'){
                    cl[i]++;
                    clm = j-1;
                }
            }
            if(i>=2 && cl[i]==2 && cl[i-1]==1 && cl[i-2]==2){
                cout<<i-1+1<<" "<<clm+1<<endl;
            }
        }
    }
}
