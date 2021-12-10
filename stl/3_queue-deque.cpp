#include <deque>
#include <queue>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    //circular queue
    //only use when:
    //memory constraint & frequent deletions & insertions from front & rear 
    queue<int> q;
    q.push(2);
    q.push(23);
    q.push(22);
    q.push(42);

    cout<<q.back()<<" back\n";
    cout<<q.front()<<" front\n";

    q.pop();
    q.pop();
    q.pop();

    cout<<q.size()<<" :size\n";


    deque<int> d;
    d.push_back(5);  // [5]
    d.push_back(2);  // [5,2]
    d.push_front(3); // [3,5,2]
    d.pop_back();    // [3,5]
    d.pop_front();   // [5]
    /*
    The internal implementation of a deque is more complex than that of a vector,
    and for this reason, a deque is SLOWER THAN VECTOR. Still, both adding and
    removing elements take O(1) time on average at both ends.
    */

    priority_queue<int> pq;
    pq.push(3);
    pq.push(5);
    pq.push(7);
    pq.push(2);
    //pq:  3 5 7 2
    cout << pq.top() << "\n"; //7
    q.pop(); 
    //pq:  3 5 7 
    cout << pq.top() << "\n"; // 7
    pq.pop(); 
    //pq:  3 5 
    cout << pq.top() << "\n"; // 5
    q.pop(); 
    //pq:  3 
    cout << pq.top() << "\n"; // 5 ??
    
    /*
    Insertion and removal take O(logn) time,
    and retrieval of front takes O(1) time.
    While an ordered set efficiently supports all the operations of a priority queue,
    the benefit of using a priority queue is that it has smaller constant factors. A
    priority queue is usually implemented using a heap structure that is much
    simpler than a balanced binary tree used in an ordered set.
    */
}