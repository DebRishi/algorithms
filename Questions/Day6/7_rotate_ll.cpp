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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0) 
            return head;
        
        ListNode* curr = head;
        int len = 1;
        while(curr->next) {
            curr = curr->next;
            len++;
        }
        
        curr->next = head;
        k = len-(k%len);
        curr = head;
        for(int i = 1 ; i < k ; i++) {
            curr = curr->next;
        }
        head = curr->next;
        curr->next = 0;
        return head;
    }
};

// class Solution {
// public:
//     int listLength(ListNode* head) {
//         int len = 0;
//         for(auto h = head ; h != 0 ; h = h->next) 
//             len++;
//         return len;
//     }
    
//     ListNode* rotateRight(ListNode* head, int k) {
//         if(!head)
//             return head;
//         int len = listLength(head);
//         int n = k%len;
//         if(n == 0) 
//             return head;
//         auto slow = head;
//         auto fast = head;
//         for(int i = 0 ; i <= n ; i++) 
//             fast = fast->next;
//         while(fast) {
//             fast = fast->next;
//             slow = slow->next;
//         }
//         auto list = slow->next;
//         slow->next = 0;
//         auto temp = list;
//         while(temp->next)
//             temp = temp->next;
//         temp->next = head;
//         return list;
//     }
// };

int main() {
    return 0;
}