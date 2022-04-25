#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int M = 100000001;
bool seive[100000001] = {true};

void thanos(){
    for(int i = 2; i*i<M; i++)
        if(seive[i])
            for(int k = 2*i; k<=M; k+=i) 
                seive[k] = false;
}


int main()
{
    for (int i = 0; i < M; i++)
    {
        seive[i] = true;
    }
    thanos();
    
    int N;
    cin >> N;
    while (N--)
    {
        int m;
        cin >> m;
        int h;
        for (int i = 2; i < m-2; i++)
        {
            if(seive[i] && (m-i-1)%i!=0){
                h=i;
            }
        }
        cout<<h<<" "<<m-h-1<<" "<<1<<"\n";
        
    }
}