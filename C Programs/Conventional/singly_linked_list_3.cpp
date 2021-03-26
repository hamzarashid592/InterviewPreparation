# include <iostream>
# include <vector>
using namespace std;

class singly_linked_list_3
{
private:
    string data;
    singly_linked_list_3 *next;
public:
    singly_linked_list_3();
    ~singly_linked_list_3();
    singly_linked_list_3 *add_data(string);
    singly_linked_list_3 *add_data_rec(string);
    singly_linked_list_3 *remove_data(string);
    singly_linked_list_3 *recursive_deletion(string);
    void print_list_rec();
    void print_list_rec_rev();
    bool search(string);
    void print();
};

singly_linked_list_3::singly_linked_list_3(/* args */)
{
    data="";
    next=NULL;
}

singly_linked_list_3 *singly_linked_list_3::add_data(string data){
    singly_linked_list_3 *head=this;
    singly_linked_list_3 *current=this;
    singly_linked_list_3 *new_node= new singly_linked_list_3;
    new_node->data=data;
    // For adding the first node.
    if (head==NULL){
        head=new_node;
        return head;
    }
    // Going to the last
    while (current->next!=NULL)
        current=current->next;
    current->next=new_node;
    return head;
}

void singly_linked_list_3::print(){
    
    singly_linked_list_3 *current=this;
    while (current!=NULL)
    {
        cout<<current->data<<"\t";
        current=current->next;
    }
    cout<<endl;
}

singly_linked_list_3 *singly_linked_list_3::remove_data(string data){
    singly_linked_list_3 *head=this;
    singly_linked_list_3 *current=this;

    if (head->data==data){
        singly_linked_list_3 *temp=head;
        head=head->next;
        delete temp;
        return head;
    }

    while (current->next!=NULL && current->next->data!=data)
        current=current->next;

    if (current->next==NULL)
        return head;
    
    singly_linked_list_3 *temp=current->next;
    current->next=current->next->next;
    delete temp;
    return head;
    
}

bool singly_linked_list_3::search(string data){
    singly_linked_list_3 *current=this;
    while (current!=NULL)
    {
        if (current->data==data)
            return true;
        current=current->next;
    }
    return false;
}

void singly_linked_list_3::print_list_rec(){
    singly_linked_list_3 *current=this;
    // The base case
    if (current==NULL){
        cout<<endl;
        return;
    }
    // printing
    cout<<current->data<<"\t";
    // recursion
    current->next->print_list_rec();
}

void singly_linked_list_3::print_list_rec_rev(){
    singly_linked_list_3 *current=this;
    // The base case
    if (current==NULL){
        return;
    }
    // recursion
    current->next->print_list_rec_rev();
    // printing
    cout<<current->data<<"\t";
}

singly_linked_list_3 *singly_linked_list_3::add_data_rec(string data){
    singly_linked_list_3 *current=this;
    // Base case.
    if (current->next==NULL){
        singly_linked_list_3 *new_node = new singly_linked_list_3;
        new_node->data=data;
        current->next=new_node;
        return current;
    }
    // Recursion.
    current->next=current->next->add_data_rec(data);
    return current;
}

singly_linked_list_3 *singly_linked_list_3::recursive_deletion(string data){
    singly_linked_list_3 *current=this;
    // Base cases

    // If data does not exist...
    if (current->next==NULL)
        return current;
        
    // If data exists in the list...
    if (current->next->data==data){
        singly_linked_list_3 *temp=current->next;
        current->next=temp->next;
        delete temp;
        return current;
    }
    
    // Recursion.
    current->next=current->next->recursive_deletion(data);
    return current;
}

singly_linked_list_3::~singly_linked_list_3()
{
}


int main(){

    singly_linked_list_3 *list=NULL;
    list=list->add_data("ive");
    list=list->add_data("got");
    list=list->add_data("a");
    list=list->add_data("blue");
    list=list->add_data("panda");
    list=list->add_data("icecream");
    cout<<"Normal printing"<<endl;
    list->print();
    cout<<"Recursive printing"<<endl;
    list->print_list_rec();
    cout<<"Reverse recursive printing"<<endl;
    list->print_list_rec_rev();
    cout<<endl;
    cout<<"Adding a node recursively"<<endl;
    list=list->add_data_rec("recursive");
    list->print();
    cout<<"Deleting a node recursively"<<endl;
    list=list->recursive_deletion("blue");
    list->print();
    list=list->recursive_deletion("girrafe");
    list->print();



    

    // singly_linked_list_3 *list[100]={};
    // list[4]=list[4]->add_data("Fire");
    // list[4]=list[4]->add_data("in");
    // list[4]=list[4]->add_data("the");
    // list[4]->print();

    return 0;
}