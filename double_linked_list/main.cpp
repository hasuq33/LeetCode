#include<iostream>
#include<string>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// This function print the linked list elements 
void traverseLinkedList(ListNode* head){
    // start from the head of the linked list
    ListNode* current = head;

    // traverse the linked list until we reach the end 
    while (current != nullptr)
    {
        cout << current->val << " ";
        // Move to the next node
        current = current->next; 
    }

    cout << endl;
    
}

// In this solution I got the answer but the issue is that stoi is not working in large numers
ListNode* doubleIt1(ListNode* head){
    ListNode *cur = head;
    string str_num = "";

    while(cur != nullptr){
       str_num += to_string(cur->val );
       cur = cur->next;
    }
    str_num = to_string(stoi(str_num)*2);

    ListNode *new_head = nullptr;
    ListNode *prev_node = nullptr;

    for(int i=0; i<str_num.length(); i++){
        ListNode *new_node = new ListNode(str_num[i] -'0');

        if(!new_head){
            new_head = new_node;
        }else{
            prev_node->next = new_node;
        }
        prev_node = new_node;
    }
    return new_head;
}

// Method to reverse the linked list


ListNode* doubleIt(ListNode* head){
    // Intialize stack to store the value of linked list 
    stack<int> values;
    int val = 0;

    while(head != nullptr){
        values.push(head->val);
        head = head->next;
    }

    ListNode*newTail = nullptr;

    // Iterate over the stack of values and the carryover
    while(!values.empty() || val != 0){

        newTail = new ListNode(0,newTail);

        //Calculate the new value for the current node 
        // by doubling the last digit , adding the carry, and getting the remainder

        if(!values.empty()){
            val += values.top()*2;
            values.pop();
        }

        newTail->val = val %10;
        val /= 10;
    }


    return newTail;
}

int main(){
    ListNode* head = new ListNode({1});
    ListNode* second = new ListNode({8});
    ListNode* third = new ListNode({9});

    head->next = second;
    second->next = third;

    doubleIt(head);
}