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
class cLinkedList
{
public:
    node *head;
    int length;

    cLinkedList()
    {
        this->length = 0;
        this->head = NULL;
    }

    node *at(int n)
    {
        if (n < 0 || n > this->length - 1)
        {
            throw "invalid_Index";
        }
        node *t = this->head;
        while (n--)
        {
            t = t->next;
        }
        return t;
    }

    node *insert(int data, int n)
    {
        if (n < 0 || n > this->length)
        {
            throw "out_of bounds";
        }
        node *dnode = new node(data);
        if (this->length == 0)
        {
            this->head = dnode;
            this->head->next = this->head;
        }
        else
        {
            node *knode;
            if (n == 0)
            {
                n = this->length;
                knode = this->at(n - 1);
                dnode->next = knode->next;
                knode->next = dnode;
                this->head = dnode;
            }
            else
            {
                knode = this->at(n - 1);
                dnode->next = knode->next;
                knode->next = dnode;
            }
        }
    }

    void remove(int n)
    {
        if (n < 0 || n >= this->length)
        {
            throw "invalid_index";
        }
        node *tnode;
        if (n == 0)
        {
            n = this->length;
            tnode = this->at(n - 1);
            node *temp = tnode->next;
            tnode->next = tnode->next->next;
            temp->next = NULL;
            //if head is deleated, its next node becoms head
            this->head = tnode->next;
        }else{
            tnode = this->at(n - 1);
            node *temp = tnode->next;
            tnode->next = tnode->next->next;
            temp->next = NULL;
        }
    }
};