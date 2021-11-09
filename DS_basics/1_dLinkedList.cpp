//doubly linked list

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
    int length;

    dLinkedList()
    {
        this->length = 0;
        this->head = NULL;
    }

    node *at(int n)
    {
        if (n >= 0 && n < this->length)
        {
            node *tnode = this->head;
            while (n--)
            {
                tnode = tnode->next;
            }
            return tnode;
        }
        else
        {
            throw "invalid_index";
        }
        return NULL;
    }

    void push_back(int data)
    {
        node *dnode = new node(data);
        if (this->length > 0)
        {
            node *tnode = this->at(this->length - 1);
            tnode->next = dnode;
            dnode->prev = tnode;
        }
        else
        {
            this->head = dnode;
        }
        this->length++;
    }

    node *insert(int n, int data)
    {
        node *m = new node(data);
        node *t = this->at(n);
        if (n == this->length)
            this->push_back(data);
        if (n > 0)
        {
            t->prev->next = m;
            m->prev = t->prev;
        }
        if (n < this->length)
        {
            t->prev = m;
            m->next = t;
        }
        if (n == 0)
        {
            this->head = m;
        }
        this->length++;
    }

    void remove(int n)
    {
        node *tnode = this->at(n);
        if (n >= 0 && n < this->length)
        {
            if (n == 0)
            {
                this->head = tnode->next;
                if (this->length != 1)
                    this->head->prev = NULL;
            }
            else if (n == this->length - 1)
            {
                tnode->prev->next = NULL;
                tnode->prev = NULL;
            }
            else
            {
                tnode->next->prev = tnode->prev;
                tnode->prev->next = tnode->next;
            }
            this->length--;
        }
        else
        {
            throw "invalid_index/underFlow";
        }
    }

    void push_front(int data)
    {
        if (this->length == 0)
        {
            this->head = new node(data);
            this->length++;
        }
        else
        {
            node *t = this->head;
            this->head = new node(data);
            this->head->next = t;
            t->prev = this->head;
            this->length++;
        }
    }

    void pop_back()
    {
        if (this->length > 0)
        {
            node*tnode = this->head;
            if(this->length == 1){
                this->head = NULL;
                tnode->next = tnode->prev = NULL;
            }else{
                while (tnode->next!=NULL)
                {
                    tnode->prev->next = NULL;
                    tnode->prev = NULL ;
                }
                
            }
            this->length--;
        }
        else
        {
            throw "underFlow";
        }
    }

    void pop_front(){
        this->head = this->head->next;
        this->head->prev->next = NULL;
        this->head->prev = NULL;
    }
};