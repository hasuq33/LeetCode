#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int findLength(Node* head){
    // Intialize the length 
    int length = 0;
    Node *current = head;
    while (current != nullptr)
    {
        length++;
        current = current->next;

    }
    cout << endl;
    return length;
}

// Function to search for a value in the linked list 
bool searchLinkedList(Node* head, int target){
    // Traverse the Linked List
    while(head != nullptr){
        if(head->data == target){
            return true;
        }
        head =  head->next;
    }
    cout << endl;
    return false;
}

// This function print the linked list elements 
void traverseLinkedList(Node* head){
    // start from the head of the linked list
    Node* current = head;

    // traverse the linked list until we reach the end 
    while (current != nullptr)
    {
        cout << current->data << " ";
        // Move to the next node
        current = current->next; 
    }

    cout << endl;
    
}

// insert a new node at the beginning
void insertionAtBeginning(Node** head_ref, int new_data){
    Node* new_node = new Node();
    
    // Put a data in new node
    new_node->data = new_data;

    // Make next of new node as a head
    new_node-> next = (*head_ref);

    // Move yo the head to point to the new node
    (*head_ref) = new_node;
}

void insertAtEnd(Node** head_ref, int new_data){
    Node* new_node = new Node({new_data});
    Node* last = *head_ref;

    // If the linked list is empty then make a new node as a head
    if(*head_ref == nullptr){
        *head_ref = new_node;
        return;
    }

    // Else traverse till the last node
    while(last->next != nullptr){
        last = last->next;
    }

    last->next = new_node;
}

int main(){
    // Let's create a nodes 
    Node* head = new Node{1};   
    Node* second = new Node{2};
    Node* third = new Node{3};

    // Connect Nodes
    head-> next = second;
    second-> next = third;

    //Call the traverseLinkedList function to print the
    // linked list elements 
    traverseLinkedList(head);
    cout << searchLinkedList(head, 10);
    cout << findLength(head);
    insertionAtBeginning(&head,4);
    cout<<endl;
    traverseLinkedList(head);
    insertAtEnd(&head, 10);
    traverseLinkedList(head);

    // Memory Cleanup (free allocated memory)
    delete head;
    delete second;
    delete third;

    return 0;
}