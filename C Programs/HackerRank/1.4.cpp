/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.
*/
//A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    };


bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method


    // Using the Floyd's cycle finding algorithm.
    Node *slow_it=head;
    Node *fast_it=head;

    //If the list is null then we have no loops.
    if (head==nullptr)
        return false;

    while(fast_it!=nullptr && fast_it->next!=nullptr){

        // Moving the fast pointer by two steps.
        fast_it=fast_it->next;
        fast_it=fast_it->next;

        // Moving the slow pointer by a single step.
        slow_it=slow_it->next;

        // If these two pointers meet.
        if (fast_it==slow_it)
            return true;
    }

    // If the list has expired, then there's no loop.
    return false;

}