#include<iostream>
#include<vector>
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

//take inputs of processes with 
vector<Process> takeInputProcess()
{
    int n;
    cout << "Enter Number of Processes : ";
    cin >> n;
    vector<Process> data(n);
    cout << "Enter " << n << " process id's : ";
    for (int i = 0; i < n; i++)
    {
        cin >> data[i].process_id;
    }
    cout << endl;

    cout << "Enter arrival time of each process :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "ProcessId " << data[i].process_id << " : ";
        cin >> data[i].arrivalTime;
    }
    cout << endl;
    cout << "Enter burst time of processes :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "ProcessId " << data[i].process_id << " : ";
        cin >> data[i].burstTime;
    }
    return data;
};

bool comppareFPFS(Process a, Process b)
{
    if (a.arrivalTime == b.arrivalTime)
    {
        return a.process_id < b.process_id;
    }
    return a.arrivalTime < b.arrivalTime;
}
/*

*/