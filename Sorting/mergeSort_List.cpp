#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    
    ListNode* mergeList(ListNode* list1,ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* dnode = dummy;
        while(list1 && list2) {
            if(list1->val < list2->val) {
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
        return dummy->next;
    }
    
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* midd = slow->next;
        slow->next = 0;
        return midd;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* midd = findMiddle(head);
        head = sortList(head);
        midd = sortList(midd);
        return mergeList(head,midd);
    }
};

int main() {
    return 0;
}