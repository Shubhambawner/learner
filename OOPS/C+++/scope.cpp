#include<iostream>
using namespace std;
 class node{
     public:
     node*next = NULL;
     int data;
     node(int a){
            this->data = a;
     }
     
 };
class sll{
    public:
    node*head;
     
     void add(int a){
         node*temp = this->head;
         while (temp->next!=NULL)
         {
             temp = temp->next;
         }
         temp->next = new node(a);
         
             
     }
     void print(){
        node*temp = this->head;
         while (temp->next!=NULL)
         {
             cout<<temp->data<<'\t';
             temp = temp->next;
         }
         cout<<temp->data<<'\n';
    
         
     }
     sll(int a){
         this->head->data = a;
         this->head->next = NULL;
     }
};
 int main(){
     int i = 2;
     sll a(i);
     while (i<40)
     {
        i++;
        a.add(i);a.print();
     }
     
 }