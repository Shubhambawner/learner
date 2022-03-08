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
    node* operator++(node n){
        return n.next;
    }
};

class sLinkedList
{
private:
    node *head;
    int length;

public:
    sLinkedList()
    {
        length = 0;
        head = NULL;
    }

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

    node *insert(int n, int data)
    {
        if (n > 0 && n <= length)
        {
            node *dnode = new node(data);
            node *knode = this->at(n - 1), *temp = knode->next;
            knode->next = dnode;
            dnode->next = temp;
            this->length++;
            return dnode;
        }
        else if (n == 0)
        {
            this->push_front();
        }
        else
        {
            throw "invalid_index";
            return NULL;
        }
        return NULL;
    }

    void remove(int n)
    {
        if (n > 0 && n < this->length)
        {
            node*temp = this->at(n - 1)->next
            this->at(n - 1)->next = temp->next;
            temp->next = NULL;
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

    void push_back(int data)
    {
        this->insert(this->length, data);
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
        this->length++;
    }

    void pop_front()
    {
        if (this->length > 0)
        {
            node*temp = this->head;
            this->head = this->head->next;
            temp->next = NULL;
            this->length--;
        }
        else
        {
            throw "underFlow";
        }
    }
};
