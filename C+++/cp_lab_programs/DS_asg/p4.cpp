#include<iostream>
#define null NULL

using namespace std;

template<class T>
class nodeSLL{  //node for singly linked list
    public :
    T data;
    nodeSLL*next=null;

    nodeSLL(T Data){
        this->data=Data;
        this->next=null;
    }
    void freeMemory(){
        this->next=null;
        cout<<"freeMemory\n";
        //code to free th memory occupoed by node
    }
};

template<typename T>
class sll{   //singly linked list class
    int length = 0;
    public:
    nodeSLL<T> *head=null;

    int getLength(){
        return this->length;
    }
   
    void print(){
        cout<<"printing lil:\t";
        nodeSLL<T> *temp = this->head;
        while (temp!=null )
        {
            cout<<temp->data<<'\t';
            temp = temp->next;
            
        }
        cout<<'\n';
    }

    void append(nodeSLL<T> *toAdd){
        nodeSLL<T>* temp = this->head;
        if (temp==null)
        {
            cout<<"appended  to the empty list\n";
            this->head=toAdd;
        }else{
            while (temp->next!=null)
            {
                //cout<<"proceed to\t";
                temp=temp->next;
                //cout<<temp->data<<'\t';
            }
            temp->next=toAdd;
            toAdd->next=null;
        } 
        //cout<<"\n";
        length++;        
    }

    nodeSLL<T>* get(int index){ //get node at index i
        if(index<length){
            int i = 0;
            nodeSLL<T>*temp = this->head;
            while (i<index)
            {
                //cout<<i<<"\tindex\n";
                temp=temp->next;
                i++;
            }
            //cout<<"get returns\t"<<temp->next->data<<'\n';
            return temp;
        }else{
            throw "index_Out_Of_Range_@_get\n";
        }
        return null;  
    }

    void insert(nodeSLL<T> *toAdd, int index){  //insert toAdd at index i (possible at indices 0 to length b4 insertion)
        this->length++;

        nodeSLL<T>*temp = this->head;
        if (index< this->length)
        {
            if (index==0)
            {
                //cout<<"appended  to empty list\n";
                this->head=toAdd;
            }else{
                temp = this->get(index-1);
                if (temp->next!=null || index!=length-1)
                {
                    //cout<<"toAdd->next=temp.next;\n";
                    toAdd->next=temp->next;
                }               
                temp->next=toAdd;
                //cout<<"temp.next=toAdd;\n";                       
            } 
        
        }else{
            this->length--;
            throw "index_Out_Of_Range\n";
        }
        
        
    };
    
    // word "delete" can't be used, so use "deleteNode"
    void deleteNode(int index){  //delete node at index i (possible at indices 0 to length b4 insertion)
        //this->length++;

        nodeSLL<T>*temp = this->head, *temp2;
        if (index< this->length)
        {
            if (index==0)
            {
                cout<<"deleted head\n";
                this->head=this->head->next;
                //temp->freeMemory();
            }else{
                temp = this->get(index-1);
                
                if (temp->next->next==null || index==length-1)
                {
                    cout<<"delete last node\n";
                    temp->next->next=temp2;
                    temp->next=null;
                    //temp2->freeMemory();
                }else{
                    temp2=temp;  
                    temp->next=temp->next->next;
                    //cout<<"temp2.next=temp.next.next;\n"; 
                }
                                      
            } 
            this->length--;

        }else{
            throw "index_Out_Of_Range_@_deleteNode\n";
        }
        
    }

    void invert(int a, int b){ //invert from index a to b(both inclusive)
        if(a>=b){
            throw "a>=b can't invert\n";
        }
        if (a==0)
        {
            nodeSLL<T> *start = this->head, *temp = start->next, *temp2 ;
            
            while (a<b)
            {
                //start2 = temp;
                temp2 = temp->next;
                //cout<<start2->data<<temp2->data<<'\t';

                //cout<<start->data<<temp->data<<"->\t"; 
                temp->next = start;
                //cout<<start->data<<temp->data<<'\t';

                //cout<<start->data<<temp->data<<"->\t"; 
                start = temp;temp = temp2;
                //cout<<start->data<<temp->data<<'\n';
                a++;

            }
            this->head->next = temp;
            this->head = start;
            

        }else{
            nodeSLL<T>*back = this->get(a-1), *start = back->next, *temp = start->next, *temp2 , *front = start;
            
             while (a<b)
            {
                //start2 = temp;
                temp2 = temp->next;
                //cout<<start2->data<<temp2->data<<'\t';

                //cout<<start->data<<temp->data<<"->\t"; 
                temp->next = start;
                //cout<<start->data<<temp->data<<'\t';

                //cout<<start->data<<temp->data<<"->\t"; 
                start = temp;temp = temp2;
                //cout<<start->data<<temp->data<<'\n';
                a++;

            }
            front->next = temp;
            back->next = start;
            
        }       
    }
    void invert(){
        invert(0, this->getLength()-1);
    }

};

int main(){
    try
    {
        sll<int> lil ;       
        int i=0;
        nodeSLL<int> *node = new nodeSLL<int>(i);


        while(i<10){
            node = new nodeSLL<int>(i) ;        
            lil.append(node);          
            i++;
        }
        lil.print();

        int a,b;
        cout<<"number to insert: ";
        cin>>a;
        cout<<"index to insert at ";
        cin>>b;
        node = new nodeSLL<int>(a);
        lil.insert(node, b);
        lil.print();

        cout<<"index to delete: ";
        cin>>a;
        lil.deleteNode(a);
        lil.print();

        cout<<"index of node to get: ";
        cin>>a;
        cout<<"Get function returns node with data: "<<lil.get(a)->data<<'\n';
        

        cout<<"indices to reverce from: ";
        cin>>a>>b;
        lil.invert(a,b);
        lil.print();
        
        cout<<"revercing the whole list gives:\n";
        lil.invert();
        lil.print();
    }
    catch(const char* s){
        cout<<s;
    }
}















