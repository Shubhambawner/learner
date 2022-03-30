// doubly linked list

#include <iostream>
using namespace std;

struct node
{
public:
    int data;
    node *next = NULL;
    node *prev = NULL;

    node(int n)
    {
        this->data = n;
    }
    
};

class dLinkedList
{
public:
    node *head = NULL;

    dLinkedList()
    {
        this->head = NULL;
    }

    static void insertMiddle(node*left, node*middle, node*right){
        left->next=middle;
        middle->next = right;

        right->prev = middle;
        middle->prev = left;
    }

    static void attach(node*left, node*right){
        left->next=right;
        right->prev=left;
    }

    node* append_back(node*toAdd, node*target){
        if(toAdd==NULL || target==NULL) return NULL;
        node*temp = target->next;
        insertMiddle(target, toAdd, temp);
    }

    node* append_front(node*toAdd, node*target){
        if(this->head==target){
            this->head = toAdd;
            this->head->next = target;
            target->prev = toAdd;
            return toAdd;
        }
        node*temp = target->prev;
        insertMiddle(temp, toAdd, target);
    }

    node* remove_front(node*toAdd, node*target){

    }

    node* remove_back(node*toAdd, node*target){

    }
};