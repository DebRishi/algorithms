#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Huffman {
    struct TreeNode {
        char data;
        int freq;
        TreeNode* left;
        TreeNode* right;

        TreeNode(char d,int f) {
            data = d;
            freq = f;
            left = right = 0;
        }
    };

    class compare {
        public:
        bool operator()(TreeNode* a,TreeNode* b) {
            return a->freq > b->freq;
        }
    };

    static void printCode(TreeNode* node,string str = "") {
        if(!node) {
            return;
        }
        if(node->data != '*') {
            cout<<node->data<<" -> "<<str<<endl;
        }
        printCode(node->left,str+"0");
        printCode(node->right,str+"1");
    }

    TreeNode* root;

    public:

    Huffman(char data[],int freq[],int size) {
        priority_queue<TreeNode*,vector<TreeNode*>,compare> minheap;
        for(int i = 0 ; i < size ; i++) {
            minheap.push(new TreeNode(data[i],freq[i]));
        }
        TreeNode* left = 0;
        TreeNode* right = 0;
        TreeNode* top = 0;
        while(minheap.size() > 1) {
            left = minheap.top();
            minheap.pop();
            right = minheap.top();
            minheap.pop();
            top = new TreeNode('*',left->freq + right->freq);
            top->left = left;
            top->right = right;
            minheap.push(top);
        }
        root = minheap.top();
        printCode(root);
    }

    string decode(string str) {
        string ans = "";
        TreeNode* cur = root;
        for(auto s : str) {
            if(s == '0') {
                cur = cur->left;
            }
            if(s == '1') {
                cur = cur->right;
            }
            if(!cur->left && !cur->right) {
                ans += cur->data;
                cur = root;
            }
        }
        return ans;
    }
};

int main() {
    char data[] = {'a','b','c','d','e','f'};
    int freq[] = {5,9,12,13,16,45};
    int size = 6;
    Huffman h(data,freq,size);
    return 0;
}