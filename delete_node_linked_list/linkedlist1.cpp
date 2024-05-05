#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value): data(value), next(nullptr) {}
};

// Assuming head is a global variable
Node*head = nullptr;

void insertAtPosition(int value, int position){
    Node* newNode = new Node(value);
    
    // If position is 0 or the list is empty, insert at the beginning
    if(position == 0 || head == nullptr){
        newNode -> next = head;
        head = newNode;
        return;
    }
    // Traverse to the node just before the specified position
    Node*current = head;
    for(int i=1; i < position && current->next != nullptr; i++){
        current = current->next;
    }

    // Insert the new node at specified position
    newNode -> next = current->next;
    current->next = newNode;
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

int main(){
     // Let's create a nodes 
    head = new Node{1};
    Node* second = new Node{2};
    Node* third = new Node{3};

    // Connect Nodes
    head-> next = second;
    second-> next = third;
    insertAtPosition(0,2);
    traverseLinkedList(head);

}