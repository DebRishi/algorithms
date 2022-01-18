#include<iostream>
#include<unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* curr = head;
        while(curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }
        
        curr = head;
        while(curr) {
            if(curr->random == 0) 
                curr->next->random = 0;
            else 
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        
        Node* ans = new Node(-1);
        Node* temp = ans;
        curr = head;
        while(curr) {
            temp->next = curr->next;
            curr->next = curr->next->next;
            temp = temp->next;
            curr = curr->next;
        }
        
        return ans->next;
    }
};

// HASHMAP
// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         unordered_map<Node*,Node*> map;
        
//         Node* curr = head;
//         while(curr) {
//             Node* temp = new Node(curr->val);
//             map[curr] = temp;
//             curr = curr->next;
//         }
        
//         curr = head;
//         while(curr) {
//             map[curr]->next = map[curr->next];
//             map[curr]->random = map[curr->random];
//             curr = curr->next;
//         }
        
//         return map[head];
//     }
// };

int main() {
    return 0;
}