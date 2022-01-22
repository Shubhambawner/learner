#include <iostream>
#include <algorithm>
#include <vector>
#include "scheduler.h"
using namespace std;





int main(){
    vector<Process> data;

    data = takeInputProcess();
    int n = data.size();

    sort(data.begin(),data.end(),comppareFPFS);

    data[0].completetionTime = data[0].arrivalTime + data[0].burstTime;
    data[0].turnaroundTime = data[0].burstTime;
    data[0].waitTime = 0;

    for(int i=1;i<n;i++){
        if(data[i].arrivalTime <= data[i-1].completetionTime){
            data[i].completetionTime = data[i-1].completetionTime + data[i].burstTime;
        }
        else{
            data[i].completetionTime = data[i].arrivalTime + data[i].burstTime;
        }

        data[i].turnaroundTime = data[i].completetionTime - data[i].arrivalTime;
        data[i].waitTime = data[i].turnaroundTime - data[i].burstTime;
    }



    return 0;
}