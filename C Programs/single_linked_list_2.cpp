# include <iostream>
using namespace std;


// struct node
// {
//     int data;
//     node *next;
// };
class single_linked_list_2
{
private:
    int data;
    single_linked_list_2 *next;
public:
    single_linked_list_2(/* args */);
    single_linked_list_2(int);
    ~single_linked_list_2();
    void add_node(int data);
    void print_list_itr();
    void print_list_rec();
    void print_list_rec_rev();
    void reverse_list_itr();
    void reverse_list_rec();
    void remove_head();
    void add_node_rec(int data);
};

single_linked_list_2::single_linked_list_2(){
    this->next=NULL;
}

single_linked_list_2::single_linked_list_2(int data)
{
    this->next=NULL;
    this->data=data;
}

void single_linked_list_2::add_node(int data){
    single_linked_list_2 *current=this;
    single_linked_list_2 *node= new single_linked_list_2;
    node->data=data;
    
    while (current->next!=NULL)
        current=current->next;
    current->next=node;
    
}

void single_linked_list_2::print_list_itr(){
    single_linked_list_2 *current=this;
    while (current!=NULL)
    {
        cout<<current->data<<"\t";
        current=current->next;
    }
}

void single_linked_list_2::print_list_rec(){

    if (this==NULL)
        return;
    single_linked_list_2 *current=this;
    cout<<current->data<<"\t";
    this->next->print_list_rec();
}

void single_linked_list_2::print_list_rec_rev(){

    single_linked_list_2 *current=this;
    if (current==NULL)
        return;
    current->next->print_list_rec_rev();
    cout<<current->data<<"\t";
}

void single_linked_list_2::add_node_rec(int data){
    single_linked_list_2 *current=this;
    
    // Base case.
    if (current->next==NULL){
        single_linked_list_2 *node= new single_linked_list_2;
        node->data=data;
        current->next=node;
        return;
    }

    current->next->add_node_rec(data);
}

void single_linked_list_2::remove_head(){
    single_linked_list_2 *current=this;
    current=current->next;
    delete this;
}

single_linked_list_2::~single_linked_list_2()
{
    
    
}


int main(){

    single_linked_list_2 sll(26);
    single_linked_list_2 *list;

    list=&sll;

    list->add_node(10);
    list->add_node(20);
    list->add_node(30);
    list->add_node(40);
    list->add_node(50);
    list->add_node(60);

    cout<<"Printing list iteratively"<<endl;
    list->print_list_itr();

    cout<<"\nPrinting list recursively"<<endl;
    list->print_list_rec();
    
    cout<<"\nPrinting list recursively in reverse"<<endl;
    list->print_list_rec_rev();

    cout<<"\nAdding a node recursively"<<endl;
    list->add_node_rec(70);
    list->print_list_itr();

    cout<<"\nRemoving the head"<<endl;
    list->remove_head();
    list->print_list_itr();

    return 0;
}