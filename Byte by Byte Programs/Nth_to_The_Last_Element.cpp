#include <iostream>
using namespace std;

class linked_list
{

public:
    int data;
    linked_list *next_node;

    linked_list();
    ~linked_list();

    linked_list *addNodeRecursively(int data);
    linked_list *addNodeIteratively(int data);
    void printList();
};

linked_list::linked_list()
{
}

linked_list *linked_list::addNodeRecursively(int data)
{
    linked_list *head = this;

    if (head == NULL)
    {
        linked_list *newNode = new linked_list;
        newNode->data = data;
        newNode->next_node = NULL;
        return newNode;
    }

    //Base case:
    if (head->next_node == NULL)
    {
        linked_list *newNode = new linked_list;
        newNode->data = data;
        newNode->next_node = NULL;
        head->next_node = newNode;
        return head;
    }

    //Recursive Call:
    head->next_node = head->next_node->addNodeRecursively(data);
    return head;
}

void linked_list::printList()
{

    linked_list *head = this;

    //Base case:
    if (head == NULL)
        return;

    //Printing:
    cout << head->data << "\t";

    //Recursive Call:
    head->next_node->printList();
}

int nthToLastElement(linked_list *head, int n)
{
    linked_list *leader = head;
    linked_list *trailer = head;

    //Giving the leader pointer the lead by n times.
    for (int i = 0; i < n; i++)
        leader = leader->next_node;

    //Now moving both the pointers by equal steps.
    while (leader->next_node != NULL)
    {
        leader = leader->next_node;
        trailer = trailer->next_node;
    }

    //Now returning the trailer.
    return trailer->data;
}

int main()
{

    linked_list *list = NULL;
    list = list->addNodeRecursively(2);
    list = list->addNodeRecursively(13);
    list = list->addNodeRecursively(1);
    list = list->addNodeRecursively(17);
    list = list->addNodeRecursively(16);
    list = list->addNodeRecursively(9);
    list = list->addNodeRecursively(20);
    list = list->addNodeRecursively(6);
    list = list->addNodeRecursively(14);
    list = list->addNodeRecursively(8);
    list = list->addNodeRecursively(5);
    list = list->addNodeRecursively(11);
    list = list->addNodeRecursively(7);
    list = list->addNodeRecursively(10);
    list = list->addNodeRecursively(15);
    list = list->addNodeRecursively(4);
    list = list->addNodeRecursively(18);
    list = list->addNodeRecursively(3);
    list = list->addNodeRecursively(12);
    list = list->addNodeRecursively(19);

    list->printList();
    cout << endl;

    cout << "1 to last " << nthToLastElement(list, 1) << endl;
    cout << "2 to last " << nthToLastElement(list, 2) << endl;
    cout << "3 to last " << nthToLastElement(list, 3) << endl;

    return 0;
}
