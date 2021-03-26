# include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

class bst
{
private:
    node *root;
public:
    bst();
    ~bst();
    void add_node(int data);
    void print_tree_itr();
    void print_tree_rec();
    void del_node();
};

bst::bst(/* args */)
{
    root=NULL;
}

bst::~bst()
{

}

void bst::add_node(int data){
    // Creating the node.
    node *temp=new node;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    // Creating an iterator.
    node *iterator=root;
    // If we're adding the first node.
    if (root==NULL){
        root=temp;
        return;
    }
    // Iterating the entire tree to reach the end.
    while (1)
    {
        if (data>iterator->data){
            // If the current node is the final node, insert the new node here.
            if (iterator->right==NULL){
                iterator->right=temp;
                break;
            }
            // Move to the next node.
            iterator=iterator->right;
        }
        else{
            // If the current node is the final node, insert the new node here.
            if (iterator->left==NULL){
                iterator->left=temp;
                break;
            }
            // Move to the next node.
            iterator=iterator->left;
        }
    }
    
    
    
    

}

void bst::print_tree_rec(){
    
}

void bst::del_node(){

}


int main(){

    bst tree;

    tree.add_node(17);
    tree.add_node(29);
    tree.add_node(48);
    tree.add_node(9);
    tree.add_node(32);
    tree.add_node(95);
    tree.add_node(16);
    tree.add_node(77);
     

    return 0;
}