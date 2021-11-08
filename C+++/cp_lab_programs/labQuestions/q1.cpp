#include"Myself.h"
 class book
{
private:
    int Price;
    string Title,Author;
public:
    book(int price, string author, string title);
    book(book &toCopy);
    book();
    void DisplayDetails();
    ~book();
};

book::book(int price, string author, string title)
{
    this->Author=author;
    this->Price=price;
    this->Title=title;
}
book::book(book &toCopy){
    this->Author=toCopy.Author;
    this->Price=toCopy.Price;
    this->Title=toCopy.Title;
}
void book::DisplayDetails(){
    cout<<this->Author<<endl;
    cout<<this->Price<<'\n';
    cout<<this->Title<<'\n';

}
book::~book()
{
}

int main(){
    //WhoamI();
    book *hcv = new book(300,"HCverma","physics");
    hcv->DisplayDetails();
}

/*

Name: Shubham Shrikant Bawner
Roll.no: 20118100
Btech. 1'st Year 2'nd sem
---------------------------------------------------
HCverma
300
physics

*/