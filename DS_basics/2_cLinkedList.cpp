// circular linked list

#include <iostream>
using namespace std;

struct node
{
    public:
    int data;
    node *next = NULL;
    node(int data)
    {
        this->data = data;
    }
};
class cLinkedList{
    public:
    node*head;
    int length;

    cLinkedList(){
        this->length = 0;
        this->head = NULL;
    }

    node* at(int n){
        node* t = this->head;
        while (n--)
        {
            t = t->next;
        }
        return t;
    }

    node* insert(int data, int n){
        
    }
}