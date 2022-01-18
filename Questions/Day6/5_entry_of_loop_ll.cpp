#include<iostream>
#include<set>
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
    ListNode* detectCycle(ListNode* head) {
        if(!head)
            return 0;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;
        
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                while(entry != slow) {
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        
        return 0;
    }

    ListNode* removeLoop(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        
        if(slow == head) {
            while(fast->next != head)
                fast = fast->next;
            fast->next = 0;
        }
        else if(slow == fast) {
            fast = head;
            while(slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
            slow->next = 0;
        }
    }
};

// BRUTE FORCE
// class Solution {
// public:
//     ListNode *detectCycle(ListNode* head) {
//         set<ListNode*> set;
//         for(auto h = head ; h != 0 ; h = h->next) {
//             if(set.find(h) != set.end())
//                 return h;
//             set.insert(h);
//         }
//         return 0;
//     }
// };

int main() {
    return 0;
}