#include <iostream>
using namespace std;

bool semaphore = false;

int buffer[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // let buffer initial size be 10
int waitingQue_Producer = 0;                     // no. of producers waiting
int waitingQue_Consumer = 0;                     // no. of producers waiting

int producerIndex = 0;
int consumerIndex = 0;
int objNumber = 0;
int s = 0;

int producer();
int consumer();

void V()
{
    semaphore = false;
    s = 0;
    cout << "process executed successfully, coming out of critical section-----------------> \n";
    if (waitingQue_Producer)
    {
        cout<<"--------Now picking up the Producer processes from waiting Queue--------\n";
        waitingQue_Producer--;
        producer();
    }
    else if (waitingQue_Consumer)
    {
        cout<<"--------Now picking up the Consumer processes from waiting Queue--------";
        waitingQue_Consumer--;
        consumer();
    }
    else
    {
        cout << "No process in waiting Queue! \n";
    }
}
void P(int *waitingQue)
{
    if (semaphore == true)
    {
        cout << "process put to wait, because other process is executing!! \n";
        *waitingQue = *waitingQue + 1;
        s++;
    }
    else
    {
        cout << "Binary semaphore passed: process allowed to run \n";
        semaphore = true;
        s++;
    }
}
void Full()
{
    if (objNumber == 9)
    {
        cout << "producer process put to wait, because Buffer is full!! \n";
        waitingQue_Producer++;
        s++;
    }
    else
    {
        cout << "object-Number Semaphore Passed: producer allowed to run \n";
        objNumber++;
    }
}
void Empty()
{
    if (objNumber == 0)
    {
        cout << "consumer process put to wait, because Buffer is empty!! \n";
        waitingQue_Consumer++;
        s++;
    }
    else
    {
        cout << "object-Number Semaphore Passed: consumer allowed to run \n";
        objNumber--;
    }
}

void stimulateCPU()
{
    cout << "--Stimulation : process in waiting Queue: " << waitingQue_Producer << "\n"
         << "--enter 1 to stimulate producer, \n"
         << "--enter 2 for consumer, and \n"
         << "--enter 3 to continue with ongoing process\n"
         << "--";
    int i = 0;
    cin >> i;
    if (i == 1)
        producer();
    else if (i == 2)
        consumer();
    else
        return;
}

int producer()
{
    Full();
    P(&waitingQue_Producer);

    if (s > 1 || objNumber == 9)
    {
        return 0; //(this is for stimulation purpose)
    }
    // critical section

    // to stimulate CPU in between the producer, so that samaphores can be tested!!
    cout << "<-------Semaphores passed, process entering into critical section\n";
    stimulateCPU();

    buffer[producerIndex] = 1;
    // code to create object at buffer
    producerIndex = (producerIndex + 1) % 10;
    objNumber--;
    V();
    return 0;
}

int consumer()
{
    Empty();
    P(&waitingQue_Consumer);

    if (s > 1 || objNumber == 9)
    {
        return 0; //(this is for stimulation purpose)
    }             //(this is for stimulation purpose)
    // critical section

    cout << "<-------Semaphores passed, process entering into critical sectiom\n";
    stimulateCPU();

    buffer[consumerIndex] = 0;
    // code to create object at buffer
    consumerIndex = (consumerIndex + 1) % 10;
    objNumber++;
    V();
    return 0;
}

int main()
{

    stimulateCPU();
}