#include<iostream>
#include<utility>
#include<vector>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == 0 || k == 1)
            return head;
        
        int count = 0;
        for(auto h = head ; h != 0 ; h = h->next)
            count++;
        
        ListNode* dummy = new ListNode(-1,head);
        ListNode* curr = 0;
        ListNode* next = 0;
        ListNode* prev = dummy;
        
        while(count >= k) {
            curr = prev->next;
            next = curr->next;
            for(int i = 1 ; i < k ; i++) {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            prev = curr;
            count -= k;
        }
        
        return dummy->next;
    }
};

// class Solution {
// public:
    
//     void reverseList(ListNode** start,ListNode** finish) {
//         (*finish)->next = 0;
//         ListNode* head = *start;
//         ListNode* next = 0;
//         ListNode* prev = 0;
//         while(head) {
//             next = head->next;
//             head->next = prev;
//             prev = head;
//             head = next;
//         }
//         *finish = *start;
//         *start = prev;
//     }
    
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         vector<pair<ListNode*,ListNode*>> nodes;
//         int steps = k;
//         ListNode* start = head;
//         for(auto h = head ; h != 0 ; h = h->next) {
//             steps--;
//             if(steps == 0) {
//                 steps = k;
//                 nodes.push_back({start,h});
//                 start = h->next;
//             }
//         }
//         for(auto& n : nodes){
//             reverseList(&n.first,&n.second);
//         }
//         head = 0;
//         ListNode* h = 0;
//         for(auto n : nodes) {
//             if(!head) {
//                 head = n.first;
//                 h = n.second;
//             }
//             else {
//                 h->next = n.first;
//                 h = n.second;
//             }
//         }
//         if(!head) {
//             head = start;
//         }
//         else {
//             h->next = start;
//         }
//         return head;
//     }
// };

int main() {
    return 0;
}