#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// RECURSIVE
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         if(!l1 && !l2) {
//             return 0;
//         }
//         ListNode* node;
//         if(!l1) {
//             node = l2;
//             node->next = mergeTwoLists(l1,l2->next);
//             return node;
//         }
//         if(!l2) {
//             node = l1;
//             node->next = mergeTwoLists(l1->next,l2);
//             return node;
//         }
//         if(l1->val < l2->val) {
//             node = l1;
//             node->next = mergeTwoLists(l1->next,l2);
//             return node;
//         }
//         else {
//             node = l2;
//             node->next = mergeTwoLists(l1,l2->next);
//             return node;
//         }
//     }
// };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = 0;
        ListNode* temp = 0;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                ListNode* node = new ListNode(l1->val);
                if(!head) {
                    head = node;
                    temp = head;
                }
                else {
                    temp->next = node;
                    temp = temp->next;
                }
                l1 = l1->next;
            }
            else {
                ListNode* node = new ListNode(l2->val);
                if(!head) {
                    head = node;
                    temp = head;
                }
                else {
                    temp->next = node;
                    temp = temp->next;
                }
                l2 = l2->next;
            }
        }
        while(l1) {
            ListNode* node = new ListNode(l1->val);
            if(!head) {
                head = node;
                temp = head;
            }
            else {
                temp->next = node;
                temp = temp->next;
            }
            l1 = l1->next;
        }
        while(l2) {
            ListNode* node = new ListNode(l2->val);
            if(!head) {
                head = node;
                temp = head;
            }
            else {
                temp->next = node;
                temp = temp->next;
            }
            l2 = l2->next;
        }
        return head;
    }
};

int main() {
    return 0;
}