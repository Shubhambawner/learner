// HIERARCHICAL DIRECTORY ORGANIZATION

#include<iostream>

using namespace std;
struct treeElement
{
    char name[20];
    int x, y, typeF, lx, rx, nc, level;
    struct treeElement *link[5];
};
typedef struct treeElement node;
void create(node **root, char *dname)
{
    int i, gap;
    if (*root == NULL)
    {
        (*root) = (node *)malloc(sizeof(node));
        cout<<"Enter name of dir/file(under "<<dname<<") : ";
        cin>>((*root)->name);
        cout<<"enter 1 for Dir/2 for file :";
        cin>>(*root)->typeF;
        for (i = 0; i < 5; i++)
            (*root)->link[i] = NULL;
        if ((*root)->typeF == 1)
        {
            cout<<"No of sub directories/files(for "<<(*root)->name<<"):";
            cin>>(*root)->nc;
            for (i = 0; i < (*root)->nc; i++)
                create(&((*root)-> link[i]), (*root)->name);
        }
        else
            (*root)->nc = 0;
    }
}
int indent = 0;
void displayIndent(int i){
    while(i-->1)cout<<"\t";
    cout<<"-> ";
}
void display(node *root)
{
    int i;
    indent++;
    if (root != NULL)
    {   displayIndent(indent);
        cout<<root->name<<"\n";
        for (i = 0; i < root->nc; i++)
            display(root->link[i]);
        
    }
    indent--;
}
int main()
{

    node *root;
    root = NULL;

    char RootD[] = "root";
    create(&root, RootD );
    cout<<"\n\nDisplaying the file System: \n\n";
    display(root);

    
}
