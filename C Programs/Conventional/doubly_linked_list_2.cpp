#include<iostream>
using namespace std;



class doubly_linked_list
{
private:
    int data;
    doubly_linked_list *next,*prev;
public:
    doubly_linked_list(int);
    ~doubly_linked_list();
    doubly_linked_list*  add_node(int);
    doubly_linked_list*  reverse_list();
    
    void print_list();
};

doubly_linked_list::doubly_linked_list(int data)
{
    next=nullptr;
    prev=nullptr;
    this->data=data;
}

doubly_linked_list::~doubly_linked_list()
{
}

doubly_linked_list* doubly_linked_list::add_node(int val){
    // Creating the node..
    doubly_linked_list *temp=new doubly_linked_list(val);
    temp->next=nullptr;
    temp->prev=nullptr;

    //Getting the current head.
    doubly_linked_list *head=this;
    doubly_linked_list *iterator=head;


    // If we are adding the first node.
    if(head==nullptr){
        head=temp;
        return head;
    }
    else
    {
        while(iterator->next!=nullptr)
            iterator=iterator->next;

        iterator->next=temp;
        temp->prev=iterator;
        return head;
    }
}



void doubly_linked_list::print_list(){
    doubly_linked_list *iterator=this;

    while (iterator!=nullptr)
    {
        cout<<iterator->data<<"\t";
        iterator=iterator->next;
    }
    cout<<endl;
}

doubly_linked_list* doubly_linked_list::reverse_list(){
    doubly_linked_list* head=this;
    doubly_linked_list* iterator=head;
    doubly_linked_list* next_node;
    doubly_linked_list* prev_node;

    while(iterator!=nullptr){
        next_node = iterator->next;
        prev_node=iterator->prev;
        iterator->next=prev_node;
        iterator->prev=next_node;

        
        if(next_node==nullptr)
            head=iterator;
        iterator=next_node;

    }
    // New head.
    return head;
}


int main(){

    doubly_linked_list *head=nullptr;

    head=head->add_node(22);
    head=head->add_node(3);
    head=head->add_node(55);
    head=head->add_node(67);
    head=head->add_node(32);
    head=head->add_node(10);
    head=head->add_node(5);
    head=head->add_node(12);
    head=head->add_node(14);
    head=head->add_node(16);

    head->print_list();

    head=head->reverse_list();
    head->print_list();

    return 0;
}