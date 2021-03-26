# include <iostream>
using namespace std;


struct node
{
    int data;
    node *next;
};

class singly_linked_list
{
private:
    node *head,*tail;
public:
    singly_linked_list();
    node *get_head();
    void add_node(int);
    void add_node_after(int,int);
    void add_node_at_position(int,int);
    void delete_node(int);
    void print_list();
    void print_list_rec();
    void reverse_list_itr();
    void reverse_list_rec();
    ~singly_linked_list();
};

singly_linked_list::singly_linked_list(/* args */)
{
    head=NULL;
    tail=NULL;
}
node *singly_linked_list::get_head(){
    return head;
}

void singly_linked_list::add_node(int value){
    node *temp=new node;
    temp->data=value;
    temp->next=NULL;

    if (head==NULL){
        head=temp;
        tail=temp;
    }
    else
    {
        tail->next=temp;
        tail=tail->next;
    }

}

void singly_linked_list::print_list(){
    node *iterator=new node;
    iterator=head;
    while (iterator!=NULL)
    {
        cout<<iterator->data<<"\t";
        iterator=iterator->next;
    }
    cout<<endl;
}

void singly_linked_list::add_node_after(int list_value, int value){
    node *iterator=new node;
    iterator=head;
    // Reaching the specific point in the list.
    while (iterator->data!=list_value && iterator->next!=NULL)
        iterator=iterator->next;
    // Inserting the node if list_value actually exists in the list.
    if(iterator->next==NULL)
        return;
    node *new_node=new node;
    new_node->data=value;
    new_node->next=iterator->next;
    iterator->next=new_node;
}

void singly_linked_list::add_node_at_position(int i, int val){
    int counter=0;
    node *iterator=head;
    // Reaching the specific point in the list.
    while (counter!=(i-1)){
        iterator=iterator->next;
        counter++;
    }
    // Inserting the node in the list.
    node *new_node=new node;
    new_node->data=val;
    new_node->next=iterator->next;
    iterator->next=new_node;       
}

void singly_linked_list::delete_node(int val){
    node *iterator=new node;
    iterator=head;

    // If head is to be deleted.
    if(head->data==val){
        head=head->next;
        delete(iterator);
        return;
    }

    // Reaching the specific point in the list.
    while (iterator->next->data!=val){
        iterator=iterator->next;
        if (iterator->next==NULL)
            break;
    }

    // Deleting that node if exists.
    if (iterator->next==NULL)
        return;
    node *temp=iterator->next;
    iterator->next=temp->next;
    delete(temp);
}

void singly_linked_list::reverse_list_itr(){
    node *iterator=head;
    node *temp = new node;
    node *prev=NULL;
    while (iterator!=NULL)
    {
        // Saving the next node.
        temp=iterator->next;
        // Pointing current node to previous node.
        iterator->next=prev;
        // Moving previous node as the current node.
        prev=iterator;
        // Moving iterator to the next node.
        iterator=temp;
    }
    // The new head node.
    head=prev;
}

void singly_linked_list::print_list_rec(){
    
    

}

singly_linked_list::~singly_linked_list()
{
    node *iterator=head;   
    node *temp=new node;
    while (iterator)
    {
        temp=iterator;
        iterator=iterator->next;
        delete temp;
    }
    
}

// // Global Functions.
// void print_list_rec(node *h){
//     if(h==NULL)
//         return;
//     cout<<h->data<<'\t';
//     print_list_rec(h->next);
// }

// void print_list_rec_reverse(node *h){
//     if(h==NULL)
//         return;
//     print_list_rec_reverse(h->next);
//     cout<<h->data<<'\t';
// }

int main(){

    singly_linked_list list;

    list.add_node(10);
    list.add_node(35);
    list.add_node(11);
    list.add_node(1);
    list.add_node(5);
    list.add_node(99);

    list.print_list();

    list.add_node_at_position(2,85);
    list.print_list();

    list.add_node_after(85,6);
    list.print_list();

    list.delete_node(99);
    list.print_list();

    list.delete_node(10);
    list.print_list();

    list.delete_node(11);
    list.print_list();

    // list.reverse_list_itr();
    // list.print_list();

    // print_list_rec(list.get_head());
    // cout<<endl;
    // print_list_rec_reverse(list.get_head());

    return 0;
}