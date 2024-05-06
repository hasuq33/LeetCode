#include<iostream>
#include<stack>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};

 ListNode* removeNodes(ListNode* head) {
        ListNode* cur = head;
        stack<ListNode*> stack;
        
        while (cur != nullptr) {
            while (!stack.empty() && stack.top()->val < cur->val) {
                stack.pop();
            }
            stack.push(cur);
            cur = cur->next;
        }
        
        ListNode* nxt = nullptr;
        while (!stack.empty()) {
            cur = stack.top();
            stack.pop();
            cur->next = nxt;
            nxt = cur;
        }
        
        return cur;
}

void traverseLinkedList(ListNode*head){
    ListNode* cur = head;
    // Traverse the linked List
    while(head != nullptr){
        cout<< cur->val <<" ";
        cur = cur->next;
    }
    cout<< endl;
}

int main(){
    ListNode* head = new ListNode({5});
    ListNode* second = new ListNode({2});
    ListNode* third = new ListNode({13});
    ListNode* fourth = new ListNode({3});
    ListNode* fifth = new ListNode({8});

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    removeNodes(head);
    traverseLinkedList(head);
}