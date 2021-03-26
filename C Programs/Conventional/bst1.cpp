# include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};


node *add_node(node *root, int data){
    
    // Creating the new node to be added.
    node *new_node= new node;
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    // An iterating pointer.
    node *iterator=root;
    
    // If we are inserting the first node.
    if (iterator==NULL)
        return new_node;
    // Going to the end of the tree.
    while (1)
    {
        if (data<=iterator->data){
            if(iterator->left==NULL){
                iterator->left=new_node;
                break;
            }
            iterator=iterator->left;
        }
        else{
            if (iterator->right==NULL){
                iterator->right=new_node;
                break;
            }
            iterator=iterator->right;
        }
    }
    return root;
}

// Left-->Node-->Right
void print_tree_inorder(node *root){
    if (root==NULL)
        return;
    print_tree_inorder(root->left);
    cout<<root->data<<"\t";
    print_tree_inorder(root->right);
}

// Node-->Left-->Right
void print_tree_preorder(node *root){
    if (root==NULL)
        return;
    cout<<root->data<<"\t";
    print_tree_preorder(root->left);
    print_tree_preorder(root->right);
}

// Left-->Right-->Node
void print_tree_postorder(node *root){
    if (root==NULL)
        return;
    print_tree_postorder(root->left);
    print_tree_postorder(root->right);
    cout<<root->data<<"\t";
}

node *add_node_rec(node *root, int data){

    if (data>root->data){
        if (root->right==NULL){
            node *new_node= new node;
            new_node->data=data;
            new_node->left=NULL;
            new_node->right=NULL;
            root->right=new_node;
            return root;
        }
        root->right=add_node_rec(root->right, data);
        return root;
    }
    else
    {
        if (root->left==NULL){
            node *new_node= new node;
            new_node->data=data;
            new_node->left=NULL;
            new_node->right=NULL;
            root->left=new_node;
            return root;
        }
        root->left=add_node_rec(root->left, data);
        return root;
    }
}

node *find_min_in_bst(node *root){
    if (root->left==NULL)
        return root;
    find_min_in_bst(root->left);
}

node *find_max_in_bst(node *root){
    if (root->right==NULL)
        return root;
    find_max_in_bst(root->right);
}

node *delete_node(node *root, int data){
    
    if (root==NULL){
        return root;
    }

    // If i find the data   
    if (data==root->data){
        // If the node is a leaf.
        if(root->left==NULL && root->right==NULL){
            delete root;
            root=NULL;
        }
        // If node has no right child.
        else if (root->right==NULL){
            node *temp=root;
            root=root->left;
            delete temp;
        }
        // If node has no left child.
        else if (root->left==NULL){
            node *temp=root;
            root=root->right;
            delete temp;
        }
        // If the node has two children.
        else {
            // Findind the max element in the left subtree.
            node *temp=find_max_in_bst(root->left);
            root->data=temp->data;
            root->left=delete_node(root->left,temp->data);
        }
        return root;
    }

    else if (data>root->data)
        root->right= delete_node(root->right,data);
    
    else if (data<root->data)
        root->left= delete_node(root->left,data);

    return root;
}


int main(){

    node *tree=NULL;

    tree=add_node(tree,17);
    tree=add_node(tree,29);
    tree=add_node(tree,48);
    tree=add_node(tree,9);
    tree=add_node(tree,32);
    tree=add_node(tree,95);
    tree=add_node(tree,16);

    cout<<"Inorder traversal"<<endl;
    print_tree_inorder(tree);
    cout<<endl;
    cout<<"Pre order traversal"<<endl;
    print_tree_preorder(tree);
    cout<<endl;
    cout<<"Post order traversal"<<endl;
    print_tree_postorder(tree);
    cout<<endl;

    cout<<"Adding nodes recursively"<<endl;
    tree=add_node_rec(tree,45);
    tree=add_node_rec(tree,3);
    tree=add_node_rec(tree,10);
    print_tree_inorder(tree);
    cout<<endl;

    cout<<"Maximum element is BST"<<endl;
    cout<<find_max_in_bst(tree)->data<<endl;

    cout<<"Minimum element is BST"<<endl;
    cout<<find_min_in_bst(tree)->data<<endl;

    cout<<"Node Deletion"<<endl;
    tree=delete_node(tree,17);
    print_tree_inorder(tree);
    cout<<endl;

    return 0;
}