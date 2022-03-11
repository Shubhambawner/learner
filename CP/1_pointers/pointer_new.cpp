

#include<iostream>
using namespace std;
struct node{
    int val; node*next;
    node(int a){
        val = a;
    }
};
int main(){
    node*head = new node(1);
    head->next = new node(2);
    node*temp = head;
    head = head->next;
    cout<<temp->val<<'\n';
    cout<<head->val<<'\n';
}