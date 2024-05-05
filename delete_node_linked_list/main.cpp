#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

 void deleteNode(Node* node) {
        node->data = node->next->data;
        node->next = node->next->next;
    }

// This function print the linked list elements 
void traverseLinkedList(Node* head){
    // start from the head of the linked list
    Node* current = head;

    // traverse the linked list until we reach the end 
    while (current != nullptr)
    {
        cout << current->data << endl;
        // Move to the next node
        current = current->next; 
    }
    
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

    // Memory Cleanup (free allocated memory)
    delete head;
    delete second;
    delete third;

    return 0;
}