#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int n)
    {
        this->data = n;
        this->next = NULL;
    }
};

class sll
{
private:
    node *head;
    int length;

public:
    sll()
    {
        length = 0;
        head = NULL;
    }

    //return pointer to node at index n
    node *at(int n)
    {
        if (n < length && n >= 0)
        {
            node *dnode = this->head;
            while (n--)
            {
                dnode = dnode->next;
            }
            return dnode;
        }
        else
        {
            throw "invalid_index";
            return NULL;
        }
        return NULL;
    }

    //add node at given index & return its pointer
    node *insert(int n, int data)
    {
        if (n >= 0 && n <= length)
        {
            node *dnode = new node(data);
            node *knode = this->at(n - 1), *temp = knode->next;
            knode->next = dnode;
            dnode->next = temp;
            this->length++;
            return dnode;
        }
        else
        {
            throw "invalid_index";
            return NULL;
        }
        return NULL;
    }

    void Delete(int n)
    {
        if (n > 0 && n < this->length)
        {
            this->at(n - 1)->next = this->at(n - 1)->next->next;
            this->length--;
        }
        else if (n == 0)
        {
            this->pop_front();
        }
        else
        {
            throw "invalid_index";
        }
    }

    //stack & queue
    void push_back(int data)
    {
        this->insert(this->length++, data);
    }

    void pop_back()
    {
        if (this->length > 1)
        {
            this->at(--(this->length) - 1)->next = NULL;
        }
        else if (this->length == 1)
        {
            this->head = NULL;
            this->length--;
        }
        else
        {
            throw "underFlow";
        }
    }

    void push_front(int data)
    {
        node *dnode = new node(data);
        dnode->next = this->head;
        this->head = dnode;
    }

    void pop_front()
    {
        if (this->length > 0)
        {
            this->head = this->head->next;
        }
        else
        {
            throw "underFlow";
        }
    }
};
