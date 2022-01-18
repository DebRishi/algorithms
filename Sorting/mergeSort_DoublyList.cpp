#include<iostream>
using namespace std;

struct Node {
	int data;
	struct Node *next, *prev;
	Node (int x){
	    data = x;
	    next = prev = NULL;
	}
};

Node* merge(Node* list1,Node* list2) {
    Node* dummy = new Node(INT_MIN);
    Node* dnode = dummy;
    while(list1 && list2) {
        if(list1->data < list2->data) {
            dnode->next = list1;
            dnode = dnode->next;
            list1 = list1->next;
        }
        else {
            dnode->next = list2;
            dnode = dnode->next;
            list2 = list2->next;
        }
    }
    while(list1) {
        dnode->next = list1;
        dnode = dnode->next;
        list1 = list1->next;
    }
    while(list2) {
        dnode->next = list2;
        dnode = dnode->next;
        list2 = list2->next;
    }
    dnode->next = 0;
    Node* dprev = 0;
    dnode = dummy->next;
    while(dnode) {
        dnode->prev = dprev;
        dprev = dnode;
        dnode = dnode->next;
    }
    return dummy->next;
}

Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* temp = slow->next;
    slow->next = 0;
    if(!temp)
        temp->prev = 0;
    return temp;
}

Node* sortDoubly(Node* head) {
    if(!head || !head->next)
        return head;
    Node* midd = findMiddle(head);
    head = sortDoubly(head);
    midd = sortDoubly(midd);
    return merge(head,midd);
}

int main() {
    return 0;
}