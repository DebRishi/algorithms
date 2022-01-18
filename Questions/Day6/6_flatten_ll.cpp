#include<iostream>
using namespace std;

// GEEKSFORGEEKS
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
};

Node* merge(Node* l1,Node* l2) {
    Node* dummy = new Node(-1);
    Node* node = dummy;
    while(l1 && l2) {
        if(l1->data < l2->data) {
            node->bottom = l1;
            node = node->bottom;
            l1 = l1->bottom;
        }
        else {
            node->bottom = l2;
            node = node->bottom;
            l2 = l2->bottom;
        }
    }
    if(l1)
        node->bottom = l1;
    else 
        node->bottom = l2;
    return dummy->bottom;
}

Node* flatten(Node* head) {
    if(!head || !head->next)
        return head;
    Node* l1 = head;
    Node* l2 = flatten(head->next);
    return merge(l1,l2);
}

// LEETCODE
// class Node {
// public:
//     int val;
//     Node* prev;
//     Node* next;
//     Node* child;
// };

// class Solution {
// public:
//     Node* flatten(Node* head) {
//         auto h = head;
//         while(h) {
//             if(h->child) {
//                 auto temp = h->next;
//                 h->next = flatten(h->child);
//                 auto tail = h->next;
//                 tail->prev = h;
//                 while(tail->next) {
//                     tail = tail->next;
//                 }
//                 if(temp) {
//                     tail->next = temp;
//                     temp->prev = tail;
//                 }
//                 h->child = 0;
//                 h = temp;
//                 continue;
//             }
//             h = h->next;
//         }
//         return head;
//     }
// };

int main() {
    return 0;
}