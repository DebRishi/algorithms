#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// OPTIMIZED
class Solution {
public:
    
    int listLength(ListNode* head) {
        int count = 0;
        for(auto h = head ; h != 0 ; h = h->next) 
            count++;
        return count;
    }
    
    ListNode* moveHead(ListNode* head,int n) {
        for(int i = 0 ; i < n ; i++)
            head = head->next;
        return head;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = listLength(headA);
        int l2 = listLength(headB);
        ListNode* h1 = headA;
        ListNode* h2 = headB;
        if(l1 > l2) {
            h1 = moveHead(h1,l1-l2);
        }
        else {
            h2 = moveHead(h2,l2-l1);
        }
        while(h1 && h2) {
            if(h1 == h2)
                return h1;
            h1 = h1->next;
            h2 = h2->next;
        }
        return 0;
    }
};

// SIMPLIFIED
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* h1 = headA;
//         ListNode* h2 = headB;
//         while(h1 != h2) {
//             h1 = h1==0 ? headB : h1->next;
//             h2 = h2==0 ? headA : h2->next;
//         }
//         return h1;
//     }
// };

// HASHING
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         set<ListNode*> set;
//         for(auto h = headA ; h != 0 ; h = h->next) {
//             set.insert(h);
//         }
//         for(auto h = headB ; h != 0 ; h = h->next) {
//             if(set.find(h) != set.end())
//                 return h;
//         }
//         return 0;
//     }
// };

// BRUTE FORCE
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         for(auto l1 = headA ; l1 != 0 ; l1 = l1->next) {
//             for(auto l2 = headB ; l2 != 0 ; l2 = l2->next) {
//                 if(l1 == l2) {
//                     return l1;
//                 }
//             }
//         }
//         return 0;
//     }
// };

int main() {
    return 0;
}