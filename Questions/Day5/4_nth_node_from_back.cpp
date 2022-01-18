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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode(-1,head);
        ListNode* fast = start;
        ListNode* slow = start;
        for(int i = 0 ; i < n ; i++)
            fast = fast->next;
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return start->next;
    }
};

// class Solution {
// public:
    
//     int listLength(ListNode* head) {
//         int count = 0;
//         for(auto h = head ; h != 0 ; h = h->next)
//             count++;
//         return count;
//     }
    
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         int len = listLength(head);
//         if(len == n)
//             return head->next;
//         ListNode* h = head;
//         for(int i = 1 ; i < len-n ; i++)
//             h = h->next;
//         h->next = h->next->next;
//         return head;
//     }
// };

int main() {
    return 0;
}