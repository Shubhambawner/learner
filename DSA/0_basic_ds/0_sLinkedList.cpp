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

class unilist
{
public:
    node *head = NULL;
    unilist()
    {
        // empty constructor
    }
    /*
        * number of nodes from countfrom including it untill we hit null
        * will advance the countFrom to last pointer
    */
    static int length(node *countFrom) 
    { 
        int length = 0;
        if (countFrom == NULL)
            return length;
        while (countFrom)
        {
            countFrom = countFrom->next;
            length++;
        }
        return length; //as we did not increment pointer from last, it did not get counted
    }

    
    /*
        * will pop out the first node from list and return its pointer
    */
    node* pop_front(){ //
        if(this->head==NULL) return NULL;
        node*temp = this->head;
        this->head = head->next;
        temp->next = NULL;
        return temp;
    }

    void push_front(node*temp){
        temp->next = this->head;
        this->head = temp;
    }

    node* push_back(node*toAdd){
        if(this->head==NULL){ this->head = toAdd;return toAdd;}
        node*temp = this->head;
        while(temp && temp->next) temp=temp->next;
        temp->next = toAdd;
        return toAdd;
    }

    node* pop_back(){
        node*temp = this->head;
        node*last=NULL; // last node
        if(this->head==NULL) return NULL;
        if(this->head->next==NULL){
            last = this->head;
            this->head = NULL;
            return temp;
        }
        while(temp && temp->next && temp->next->next) temp=temp->next;
        last = temp;
        temp->next = NULL;
        return last;
    }

    node* insert_after(node*toAdd, node*Node){
        if(Node==NULL) return toAdd;
        node*temp = Node->next;
        Node->next = toAdd;
        toAdd->next = temp;
        return toAdd;
    }

    node* insert_before(node*toAdd, node*Node){
        node*temp = this->head;
        node*afterNode = NULL;
        
        if(temp==Node){
            this->head = toAdd;
            toAdd->next = temp;
            return toAdd;
        }
        while(temp && temp->next){
            if(temp->next==Node) afterNode = temp;
        }

        if(afterNode==NULL){
            throw "node not found in the list\n";
        }

        afterNode->next = toAdd;
        toAdd->next = Node;
        return toAdd;
    }

    node* get_node_before(node*Node){
        node*temp = this->head;
        node*nodeBefore = NULL;
        
        if(temp==Node){
            throw "the node provided is Head, can't have node before itself.";
        }
        if(temp==NULL) throw "list is empty";
        if(Node==NULL) throw "empty node provided";

        while(temp && temp->next){
            if(temp->next==Node) nodeBefore = temp;
        }

        if(nodeBefore==NULL){
            throw "node not found in the list\n";
        }
    }

    node* pop_after(node*Node){
        if(Node==NULL) return NULL;
        if(Node->next==NULL) return NULL;
        
        node*temp = Node->next;
        Node->next = temp->next ? temp->next : NULL;

        return temp;
    }
};