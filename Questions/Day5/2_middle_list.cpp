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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
            if(fast->next) 
                fast = fast->next;
        }
        return slow;
    }
};

int main() {
    // LEETCODE 876
    return 0;
}