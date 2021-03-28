#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    int length1=0; 
    int length2=0;
    SinglyLinkedListNode *it1=head1;
    SinglyLinkedListNode *it2=head2;

    //Finding the lengths of the two lists.
    while (it1!=nullptr){
        it1=it1->next;
        length1++;
    }
    while (it2!=nullptr){
        it2=it2->next;
        length2++;
    }

    //If list1 is smaller than list2.
    if (length1<length2){
        //Finding the difference in lengths.
        int common_length=length2-length1;    
        //Offsetting the second list such that its length becomes equal to the first list.
        for (int i=0;i<common_length;i++)
            head2=head2->next;
    }

    else{
        //Finding the difference in lengths.
        int common_length=length1-length2;
        //Offsetting the first list such that its length becomes equal to the second list.
        for (int i=0;i<common_length;i++)
            head1=head1->next;
    }
    

    //Now iterating both the lists in parallel.
    for (int i=0;i<length1;i++){
        if (head1==head2)
            return head1->data;
        head1=head1->next;
        head2=head2->next;
    }

    //If there is no merge point.
    return 0;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        int index;
        cin >> index;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        SinglyLinkedList* llist1 = new SinglyLinkedList();

        int llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist1_count; i++) {
            int llist1_item;
            cin >> llist1_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist1->insert_node(llist1_item);
        }
      
      	SinglyLinkedList* llist2 = new SinglyLinkedList();

        int llist2_count;
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist2_count; i++) {
            int llist2_item;
            cin >> llist2_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist2->insert_node(llist2_item);
        }
      
      	SinglyLinkedListNode* ptr1 = llist1->head;
      	SinglyLinkedListNode* ptr2 = llist2->head;
      
      	for (int i = 0; i < llist1_count; i++) {
            if (i < index) {
          		ptr1 = ptr1->next;
            }
        }
      
      	for (int i = 0; i < llist2_count; i++) {
          	if (i != llist2_count-1) {
          		ptr2 = ptr2->next;
            }
        }
      
      	ptr2->next = ptr1;

        int result = findMergeNode(llist1->head, llist2->head);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
