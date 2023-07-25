#include<bits/stdc++.h>
using namespace std;
# define unsigned int uint

class Solution {
public:
    struct Engineer {
        int speed;
        int efficiency;
    };
    
    static bool compare(Engineer& a,Engineer& b) {
        if(a.efficiency != b.efficiency)
            return a.efficiency > b.efficiency;
        else
            return a.speed > b.speed;
    }
    
    int maxPerformance(int n,vector<int>& speed,vector<int>& efficiency,int k) {
        vector<Engineer> engineers;
        for(int i = 0 ; i < n ; i++)
            engineers.push_back({speed[i],efficiency[i]});
        sort(engineers.begin(),engineers.end(),compare);
        priority_queue<int,vector<int>,greater<int>> heap;
        long ans = -1;
        long sum = 0;
        for(int i = 0 ; i < n ; i++) {
            int speed = engineers[i].speed;
            int efficiency = engineers[i].efficiency;
            sum += speed;
            heap.push(speed);
            if(heap.size() > k) {
                sum -= heap.top();
                heap.pop();
            }
            ans = max(ans,(efficiency*sum) % 1'000'000'007);
        }
        return ans;
    }
};