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
    ListNode* findMid(ListNode* head) {
        if(!head)
            return 0;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return 0;
        ListNode* curr = head;
        ListNode* next = 0;
        ListNode* prev = 0;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* mid = findMid(head);
        mid->next = reverseList(mid->next);
        ListNode* h1 = head;
        ListNode* h2 = mid->next;
        while(h1 && h2) {
            if(h1->val != h2->val)
                return false;
            h1 = h1->next;
            h2 = h2->next;
        }
        return true;
    }
};

// BRUTE FORCE
// class Solution {
// public:
//     bool isPalindrome(ListNode *head) {
//         vector<int> arr;
//         for(auto h = head ; h != 0 ; h = h->next)
//             arr.push_back(h->val);
        
//         int i = 0;
//         int j = arr.size()-1;
//         while(i < j) {
//             if(arr[i] != arr[j])
//                 return false;
//             i++;
//             j--;
//         }
//         return true;
//     }
// };