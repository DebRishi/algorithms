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
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};

// HASHING
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         set<ListNode*> set;
//         for(auto h = head ; h != 0 ; h = h->next) {
//             if(set.find(h) != set.end())
//                 return true;
//             set.insert(h);
//         }
//         return false;
//     }
// };

int main() {
    return 0;
}