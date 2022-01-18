#include<iostream>
#include<tuple>
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
    ListNode* getPivot(ListNode* head) {
        while(head->next && head->next->next)
            head = head->next;
        ListNode* tail = head->next;
        head->next = tail->next;
        return tail;
    }
    
    tuple<ListNode*,ListNode*,ListNode*> partition(ListNode* head) {
        ListNode* small = new ListNode();
        ListNode* large = new ListNode();
        ListNode* snode = small;
        ListNode* lnode = large;
        ListNode* pivot = getPivot(head);
        while(head) {
            if(head->val < pivot->val) {
                snode->next = head;
                snode = snode->next;
                head = head->next;
            }
            else {
                lnode->next = head;
                lnode = lnode->next;
                head = head->next;
            }
        }
        snode->next = 0;
        lnode->next = 0;
        return {small->next,large->next,pivot};
    }
    
    void printList(ListNode* head) {
        while(head) {
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        auto [small,large,pivot] = partition(head);
        small = sortList(small);
        large = sortList(large);
        pivot->next = large;
        if(!small)
            return pivot;
        else {
            ListNode* temp = small;
            while(temp->next)
                temp = temp->next;
            temp->next = pivot;
            return small;
        }
    }
};

int main() {
    return 0;
}