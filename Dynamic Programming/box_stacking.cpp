#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
    public:
    
    struct Box {
        int l;
        int w;
        int h;
    };
    
    static bool compare(Box& a,Box& b) {
        return a.l*a.w > b.l*b.w;
    }
    
    int maxHeight(int height[],int width[],int length[],int n) {
        vector<Box> boxes;
        for(int i = 0 ; i < n ; i++) {
            boxes.push_back({ max(length[i],width[i]) , min(length[i],width[i]) , height[i]});
            boxes.push_back({ max(width[i],height[i]) , min(width[i],height[i]) , length[i]});
            boxes.push_back({ max(height[i],length[i]),min(height[i],length[i]) , width[i]});
        }
        
        sort(boxes.begin(),boxes.end(),compare);
        
        int dp[boxes.size()];
        for(int i = 0 ; i < boxes.size() ; i++)
            dp[i] = boxes[i].h;
        
        for(int i = 0 ; i < boxes.size() ; i++) {
            for(int j = i+1 ; j < boxes.size() ; j++) {
                if(boxes[j].l < boxes[i].l && boxes[j].w < boxes[i].w && dp[j] < dp[i] + boxes[j].h) {
                    dp[j] = dp[i]+boxes[j].h;
                }
            }
        }
        
        int ans = 0;
        for(int i : dp) 
            ans = max(ans,i);
        return ans;
    }
};

int main() {
    int n = 9;
    int height[] = {6,9,2,3,9,4,9,4,5};
    int width[] = {2,7,9,8,4,4,3,4,4};
    int length[] = {4,3,3,8,3,9,1,8,4};
    Solution s;
    cout<<s.maxHeight(height,width,length,n);
}