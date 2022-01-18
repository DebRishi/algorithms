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
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2,int carry = 0) {
//         if(!l1 && !l2) {
//             if(carry)
//                 return new ListNode(carry);
//             else 
//                 return 0;
//         }
//         if(!l1) {
//             int sum = l2->val + carry;
//             return new ListNode(sum%10,addTwoNumbers(l1,l2->next,sum/10));
//         }
//         if(!l2) {
//             int sum = l1->val + carry;
//             return new ListNode(sum%10,addTwoNumbers(l1->next,l2,sum/10));
//         }
//         int sum = l1->val + l2->val + carry;
//         return new ListNode(sum%10,addTwoNumbers(l1->next,l2->next,sum/10));
//     }
// };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = 0;
        ListNode* temp = 0;
        int carry = 0;
        while(l1 && l2) {
            ListNode* node = new ListNode((l1->val+l2->val+carry)%10);
            carry = (l1->val+l2->val+carry)/10;
            if(!head) {
                head = node;
                temp = head;
            }
            else {
                temp->next = node;
                temp = temp->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            ListNode* node = new ListNode((l1->val+carry)%10);
            carry = (l1->val+carry)/10;
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
            ListNode* node = new ListNode((l2->val+carry)%10);
            carry = (l2->val+carry)/10;
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
        if(carry) {
            ListNode* node = new ListNode(carry);
            if(!head) {
                head = node;
                temp = head;
            }
            else {
                temp->next = node;
                temp = temp->next;
            }
        }
        return head;
    }
};

int main() {
    return 0;
}