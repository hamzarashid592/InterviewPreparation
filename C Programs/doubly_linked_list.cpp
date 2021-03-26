#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next,*prev;
};

class doubly_linked_list
{
private:
    node *head, *tail;
public:
    doubly_linked_list();
    ~doubly_linked_list();
    void  add_node(int);
    void add_node_after(int,int);
    void del_node(int);
    void print_list();
};

doubly_linked_list::doubly_linked_list()
{
    head=NULL;
    tail=NULL;
}

doubly_linked_list::~doubly_linked_list()
{
}

void doubly_linked_list::add_node(int val){
    // Creating the node..
    node *temp=new node;
    temp->data=val;
    temp->next=NULL;
    temp->prev=NULL;
    // If we are adding the first node.
    if(head==NULL){
        head=temp;
        tail=temp;
    }
    else
    {
        tail->next=temp;
        temp->prev=tail;
        tail=tail->next;
    }
}

void doubly_linked_list::del_node(int val){
    node *iterator=head;
    // Reaching the node to delete.
    while (iterator->data!=val){
        iterator=iterator->next;
        if (iterator==NULL)
            break;
    }
    // If no matching node was found.
    if(iterator==NULL)
        return;
    // Storing node in a temp var.
    node *temp=iterator;
    // Going one node back.
    iterator=iterator->prev;
    iterator->next=temp->next;
    temp->next->prev=iterator;
    delete temp;
}

void doubly_linked_list::add_node_after(int list_val, int val){
    node *iterator=head;
    // Reaching the node.
    while (iterator->data!=list_val){
        iterator=iterator->next;
        if (iterator==NULL)
            break;
    }
    if (iterator==NULL)
        return;
    // Creating the node to add.
    node *temp=new node;
    temp->data=val;
    temp->next=iterator->next;
    iterator->next->prev=temp;
    iterator->next=temp;
    temp->prev=iterator;
}

void doubly_linked_list::print_list(){
    node *iterator=head;
    while (iterator!=NULL)
    {
        cout<<iterator->data<<"\t";
        iterator=iterator->next;
    }
    cout<<endl;
}


int main(){

    doubly_linked_list list;

    list.add_node(22);
    list.add_node(3);
    list.add_node(55);
    list.add_node(67);
    list.add_node(32);
    list.add_node(10);
    list.add_node(5);

    list.print_list();

    list.del_node(32);
    list.print_list();

    list.del_node(100);
    list.print_list();

    list.add_node_after(67,99);
    list.print_list();

    // list.add_node_after(5,100);
    // list.print_list();

    list.add_node_after(22,22);
    list.print_list();

    return 0;
}