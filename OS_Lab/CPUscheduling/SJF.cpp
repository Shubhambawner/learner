#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Process
{
    int process_id;
    int arrivalTime;
    int burstTime;
    int waitTime;
    int turnaroundTime;
    int completetionTime;
};

struct compareProcess
{
    bool operator()(Process const& a,Process const& b){
        if(a.burstTime == b.burstTime){
        if(a.arrivalTime == b.arrivalTime){
            return a.process_id > b.process_id;
            }
            return a.arrivalTime > b.arrivalTime;
        }
        return a.burstTime > b.burstTime;
    }
};

int main(){
    int n;
    cout<<"Enter Number of Processes : ";
    cin>>n;
    vector<Process> data(n);

    cout<<"Enter "<<n<<" process id's : ";
    for(int i=0;i<n;i++){
        cin>>data[i].process_id;
    }
    cout<<endl;
    
    cout<<"Enter arrival time of each process :"<<endl;
    for(int i=0;i<n;i++){
        cout<<"ProcessId "<<data[i].process_id<<" : ";
        cin>>data[i].arrivalTime;
    }

    cout<<endl;
    cout<<"Enter burst time of processes :"<<endl;
    for(int i=0;i<n;i++){
        cout<<"ProcessId "<<data[i].process_id<<" : ";
        cin>>data[i].burstTime;
    }

    priority_queue<Process,vector<Process>,compareProcess> pq;

    for(int i=0;i<n;i++){
        pq.push(data[i]);
    }

    for(int i=0;i<n;i++){
        Process p = pq.top();
        pq.pop();
        data[i] = p;
    }

    data[0].completetionTime = data[0].arrivalTime + data[0].burstTime;
    data[0].turnaroundTime = data[0].completetionTime - data[0].arrivalTime;
    data[0].waitTime = 0;

    for(int i=0;i<n;i++){
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