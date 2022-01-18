#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
using namespace std;
#define pii pair<int,int>

struct Item {
    int value;
    int weight;
};

bool compare(Item & a,Item & b) {
    double v1 = (double)a.value/a.weight;
    double v2 = (double)b.value/b.weight;
    return v1 > v2;
}

double fractionalKnapsack(vector<Item> items,int weight) {
    sort(items.begin(),items.end(),compare);
    double ans = 0;
    for(auto item : items) {
        if(weight >= item.weight) {
            ans += item.value;
            weight -= item.weight;
            continue;
        }
        double v = (double)item.value/item.weight;
        ans += v * weight;
        weight = 0;
        break;
    }
    return ans;
}

// PRIORITY QUEUE
// struct Compare{
//     bool operator()(pii & a,pii & b) {
//         double v1 = (double)a.first/a.second;
//         double v2 = (double)b.first/b.second;
//         return v1 > v2;
//     }
// };

// double fractionKnapsack(vector<int> value,vector<int> weight,int maxWeight,int n) {
//     priority_queue<pii,vector<pii>,Compare> maxheap;
//     for(int i = 0 ; i < n ; i++) maxheap.push({value[i],weight[i]});
//     double ans = 0;
//     while(!maxheap.empty()) {
//         pii top = maxheap.top();
//         maxheap.pop();
//         if(maxWeight >= top.second) {
//             ans += top.first;
//             maxWeight -= top.second;
//             continue;
//         }
//         double v = (double)top.first/top.second;
//         ans += v*maxWeight;
//         break;
//     }
//     return ans;
// }

int main() {
    int n = 3;
    int max_weight = 50;
    vector<int> values = {60,100,120};
    vector<int> weight = {10,20,30};
    vector<Item> items;
    for(int i = 0 ; i < n ; i++) {
        items.push_back({values[i],weight[i]});
    }
    cout<<fractionalKnapsack(items,max_weight);
    return 0;
}